#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;

int main() {
    // ������������� ����� �������
    cv::VideoCapture cap(0); // 0 - ������ ������

    // �������� �� ���������� �������������
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera" << std::endl;
        return -1;
    }

    // ���������� ����� � ������
    cv::Mat frame;
    cap >> frame;

    // ���������� ����� � ����
    cv::imwrite("c:/Users/sleim/1.jpg", frame);

    // ������������ ��������
    cap.release();

    return 0;
}