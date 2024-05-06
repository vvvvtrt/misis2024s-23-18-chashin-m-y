#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>


enum class Color { RED, GREEN, BLUE, WHITE, YELLOW, ORANGE };

std::map<Color, cv::Scalar> colorMap = {
	{Color::RED, cv::Scalar(0, 0, 255)},
	{Color::GREEN, cv::Scalar(0, 255, 0)},
	{Color::BLUE, cv::Scalar(255, 0, 0)},
	{Color::WHITE, cv::Scalar(255, 255, 255)},
	{Color::YELLOW, cv::Scalar(0, 255, 255)},
	{Color::ORANGE, cv::Scalar(0, 165, 255)}
};

std::map<Color, std::string> colorName = {
	{Color::RED, "Red"},
	{Color::GREEN, "Green"},
	{Color::BLUE, "Blue"},
	{Color::WHITE, "White"},
	{Color::YELLOW, "Yellow"},
	{Color::ORANGE, "Orange"}
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

	void Recognition() {
		std::vector<std::vector<cv::Point>> contours;
		std::vector<cv::Vec4i> hierarchy;

		findContours(imgDil, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
		//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);	

		std::vector<std::vector<cv::Point>> conPoly(contours.size());
		std::vector<cv::Rect> boundRect(contours.size());

		std::vector<Circuit> arr_a;

		for (int i = 0; i < contours.size(); i++)
		{
			int area = contourArea(contours[i]);
			std::cout << area << std::endl;
			std::string objectType;

			if (area > 3000)
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

	void SearchSquare() {
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


	Color GetNearestColor(cv::Scalar const& color)
	{
		Color nearest_color = Color::RED;
		double min_distance = std::numeric_limits<double>::max();

		for (auto const& pair : colorMap)
		{
			double distance =
				sqrt(
					pow(pair.second[2] - color[2], 2) +
					pow(pair.second[1] - color[1], 2) +
					pow(pair.second[0] - color[0], 2)
				);

			if (distance < min_distance)
			{
				min_distance = distance;
				nearest_color = pair.first;
			}
		}

		return nearest_color;
	}


	void FillColors() {
		for (int i = index_detected; i < index_detected + 9; i++) {
			Circuit const& cur = arr_detect[i];

			cv::Rect roi;
			roi.x = cur.start.x;
			roi.y = cur.start.y;
			roi.width = cur.end.x - cur.start.x;
			roi.height = cur.end.y - cur.start.y;

			cv::Mat image_roi = img(roi);
			cv::Scalar mean_color = cv::mean(image_roi);

			color_cube.push_back(GetNearestColor(mean_color));
		}
	}

	void View() {
		for (int i = index_detected; i < index_detected + 9; i++) {
			rectangle(img, arr_detect[i].start, arr_detect[i].end, colorMap[color_cube[i - index_detected]], 5);
			putText(img, colorName[color_cube[i - index_detected]], { arr_detect[i].start.x, arr_detect[i].start.y - 5 }, cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 69, 255), 2);
		}
	}

private:
	cv::Mat img;
	cv::Mat imgDil;

	std::vector<Circuit> arr_detect;
	std::vector<Color> color_cube;

	int index_detected;
};


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