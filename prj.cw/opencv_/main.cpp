#include "main.hpp"
#include <iostream>

cv::Mat kMeansClustering(cv::Mat image, int num_clusters) {
    cv::Mat reshaped_image = image.reshape(1, image.rows * image.cols);
    reshaped_image.convertTo(reshaped_image, CV_32F);

    cv::Mat labels, centroids;
    cv::kmeans(reshaped_image, num_clusters, labels,
        cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 10, 1.0),
        3, cv::KMEANS_PP_CENTERS, centroids);

    // Assign each pixel to its cluster center
    cv::Mat output_image = cv::Mat::zeros(image.size(), image.type());
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            int cluster_id = labels.at<int>(i * image.cols + j);
            output_image.at<cv::Vec3b>(i, j) = centroids.at<float>(cluster_id, 0);
        }
    }

    return output_image;
}

void getCircuit(std::string path) {
    //path = "Resources/test.jpg";
    //Snapshot(path);

    cv::Mat img = cv::imread(path);
    cv::Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

    // Preprocessing
    cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, cv::Size(3, 3), 3, 0);
    Canny(imgBlur, imgCanny, 25, 75);
    cv::Mat kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    dilate(imgCanny, imgDil, kernel);

    int num_clusters = 6; // Number of clusters (colors) to detect
    cv::Mat clustered_image = kMeansClustering(img, num_clusters);

    Detected temp(imgDil, img);
    temp.Recognition();
    temp.SearchSquare();
    temp.FillColors();
    temp.View();

    cv::imshow("Original Image", img);
    cv::imshow("Clustered Image", clustered_image);

    cv::waitKey(0);
}


int main() {
    getCircuit("Resources/test5.jpg");
}
