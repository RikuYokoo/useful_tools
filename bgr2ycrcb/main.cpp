#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>

using namespace std;

int main(){

	cv::Mat image = cv::Mat::zeros(100, 100, CV_8UC3);

	cv::imshow("aaa", image);
	cv::waitKey(0);

  return 0;
}

