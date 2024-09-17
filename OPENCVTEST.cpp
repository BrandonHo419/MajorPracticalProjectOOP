#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Load an image from file
    cv::Mat image = cv::imread("dice.jpg");

    // Check if the image was loaded successfully
    if (image.empty()) {
        std::cout << "Error: Could not load image" << std::endl;
        return -1;
    }

    // Display the image in a window
    cv::imshow("Test Image", image);

    // Wait for a key press indefinitely
    cv::waitKey(0);

    return 0;
}
