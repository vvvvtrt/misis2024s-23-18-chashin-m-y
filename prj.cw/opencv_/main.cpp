#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


enum class Color { RED, GREEN, BLUE, WHITE, YELLOW, ORANGE };

struct Circuit {
	Circuit(int ar, cv::Point st, cv::Point en): area(ar), start(st), end(en) {}
	~Circuit() = default;

	int area;
	cv::Point start;
	cv::Point end;
};

class Detected {
public:
	Detected() = default;
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

	void Recognition(cv::Mat& imgDil, cv::Mat& img) {
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

			if (area > 2000)
			{
				float peri = arcLength(contours[i], true);
				approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
				std::cout << conPoly[i].size() << std::endl;
				boundRect[i] = boundingRect(conPoly[i]);

				Circuit temp(area, boundRect[i].tl(), boundRect[i].br());
				arr_detect.push_back(temp);

				int objCor = (int)conPoly[i].size();

				if (objCor == 3) { objectType = "Tri"; }
				else if (objCor == 4)
				{
					float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
					std::cout << aspRatio << std::endl;
					if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; }
					else { objectType = "Rect"; }
				}
				else if (objCor > 4) { objectType = "Circle"; }

				drawContours(img, conPoly, i, cv::Scalar(255, 0, 255), 2);
				rectangle(img, boundRect[i].tl(), boundRect[i].br(), cv::Scalar(0, 255, 0), 5);
				//line(img, {1, 1}, boundRect[i].br(), Scalar(0, 255, 0), 1);
				putText(img, objectType, { boundRect[i].x,boundRect[i].y - 5 }, cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 69, 255), 2);
				cv::circle(img, cv::Point(304, 317), 5, cv::Scalar(0, 0, 255), -1);
				cv::circle(img, cv::Point(426, 317 + 114), 5, cv::Scalar(0, 0, 255), -1);
			}
		}

	}
	

private:
	std::vector<Circuit> arr_detect;
	std::vector<Color> color_cube;
};


int main() {
	cv::VideoCapture cap(0); // 0 - индекс камеры

	if (!cap.isOpened()) {
		std::cerr << "Error: Could not open camera" << std::endl;
		return -1;
	}

	// считывание кадра с камеры
	cv::Mat frame;
	cap >> frame;

	// сохранение кадра в файл
	//cv::imwrite("Resources/test.jpg", frame);
	cap.release();


	std::string path = "Resources/test.jpg";
	cv::Mat img = cv::imread(path);
	cv::Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	// Preprocessing
	cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, cv::Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	cv::Mat kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	Detected temp;
	temp.Recognition(imgDil, img);


	imshow("Image", img);
	//imshow("Image Gray", imgGray);
	//imshow("Image Blur", imgBlur);
	//imshow("Image Canny", imgCanny);
	//imshow("Image Dil", imgDil);

	cv::waitKey(0);

}
