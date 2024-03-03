#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;

int main() {
    // инициализация видео захвата
    cv::VideoCapture cap(0); // 0 - индекс камеры

    // проверка на успешность инициализации
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera" << std::endl;
        return -1;
    }

    // считывание кадра с камеры
    cv::Mat frame;
    cap >> frame;

    // сохранение кадра в файл
    cv::imwrite("c:/Users/sleim/1.jpg", frame);

    // освобождение ресурсов
    cap.release();

    return 0;
}