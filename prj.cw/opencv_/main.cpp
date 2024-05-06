#include "main.hpp"



void View() {

}


void Start() {
	std::string path = "Resources/test.jpg";
	//Snapshot(path);

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
	temp.SearchSquare();
	temp.FillColors();
	temp.View();

	imshow("Image", img);
	//imshow("Image2", equalizedImage);

	cv::waitKey(0);
}



int main() {
	Start();
}