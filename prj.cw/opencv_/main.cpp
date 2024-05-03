#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <algorithm>
#include <iostream>
#include <map>


enum class Color { RED, GREEN, BLUE, WHITE, YELLOW, ORANGE };

std::map<Color, cv::Scalar> colorMap = {
	{Color::RED, cv::Scalar(0, 0, 255)},
	{Color::GREEN, cv::Scalar(0, 255, 0)},
	{Color::BLUE, cv::Scalar(0, 0, 255)},
	{Color::WHITE, cv::Scalar(255, 255, 255)},
	{Color::YELLOW, cv::Scalar(0, 255, 255)},
	{Color::ORANGE, cv::Scalar(0, 165, 255)}
};

struct Circuit {
	Circuit(int ar, cv::Point st, cv::Point en) : area(ar), start(st), end(en) {}
	~Circuit() = default;

	int area;
	cv::Point start;
	cv::Point end;
};

class Detected {
public:
	Detected(cv::Mat& imgDil_, cv::Mat& img_) : imgDil(imgDil_), img(img_) {}
	~Detected() = default;

	void Snapshot(std::string& path) {
		cv::VideoCapture cap(0);

		if (!cap.isOpened()) {
			std::cerr << "Error: Could not open camera" << std::endl;
			throw "Error: Could not open camera";
		}

		cv::Mat frame;
		cap >> frame;

		cv::imwrite(path, frame);
		cap.release();
	}

	void Recognition() {
		std::vector<std::vector<cv::Point>> contours;
		std::vector<cv::Vec4i> hierarchy;

		findContours(imgDil, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
		//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);	

		std::vector<std::vector<cv::Point>> conPoly(contours.size());
		std::vector<cv::Rect> boundRect(contours.size());

		std::vector<Circuit> arr_a;

		for (int i = 0; i < contours.size(); i++)
		{
			int area = contourArea(contours[i]);
			std::cout << area << std::endl;
			std::string objectType;

			if (area > 5000)
			{
				double peri = arcLength(contours[i], true);
				approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
				std::cout << conPoly[i].size() << std::endl;
				boundRect[i] = boundingRect(conPoly[i]);

				std::cout << "Cord " << boundRect[i].tl().x << ' ' << boundRect[i].tl() << '\n';

				Circuit temp(area, boundRect[i].tl(), boundRect[i].br());
				arr_detect.push_back(temp);

				//drawContours(img, conPoly, i, cv::Scalar(255, 0, 255), 2);
				//rectangle(img, boundRect[i].tl(), boundRect[i].br(), cv::Scalar(0, 255, 0), 5);
			}
		}

	}

	void Search_square() {
		std::cout << "Start " << '\n';
		std::sort(arr_detect.begin(), arr_detect.end(), [](Circuit x, Circuit y) { return x.area < y.area; });

		int min_diff = pow(10, 4);

		if (arr_detect.size() >= 9) {
			for (int i = 0; i < arr_detect.size() - 9; i++) {
				if (min_diff > arr_detect[i + 9].area - arr_detect[i].area) {
					min_diff = arr_detect[i + 9].area - arr_detect[i].area;
					index_detected = i;
				}
			}
			std::cout << "Sort_ind " << arr_detect[index_detected].area << ' ' << index_detected << '\n';
		}
		else
		{
			throw "Not found";
		}
	}
	void Color_Recognition() {
		for (int i = index_detected; i < index_detected + 9; i++) {
			Circuit const& cur = arr_detect[i];

			cv::Rect roi;
			roi.x = cur.start.x;
			roi.y = cur.start.y;
			roi.width = cur.end.x - cur.start.x;
			roi.height = cur.end.y - cur.start.y;

			cv::Mat image_roi = img(roi);
			cv::Scalar mean_color = cv::mean(image_roi);

			std::cout << "Средний цвет BGR в квадрате: "
				<< "(B,G,R) = (" << mean_color[0] << ", " << mean_color[1] << ", " << mean_color[2] << ")"
				<< std::endl;
		}
	}

	void View() {
		for (int i = index_detected; i < index_detected + 9; i++) {
			rectangle(img, arr_detect[i].start, arr_detect[i].end, colorMap[Color::YELLOW], 5);
		}
	}

private:
	cv::Mat img;
	cv::Mat imgDil;

	std::vector<Circuit> arr_detect;
	std::vector<Color> color_cube;

	int index_detected;
};


int main() {
	std::string path = "Resources/test.jpg";
	cv::Mat img = cv::imread(path);
	cv::Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	// Preprocessing
	cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, cv::Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	cv::Mat kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	Detected temp(imgDil, img);
	temp.Recognition();
	temp.Search_square();
	temp.View();
	temp.Color_Recognition();


	imshow("Image", img);

	cv::waitKey(0);

}