#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <opencv2/opencv.hpp>

class Pixel{
public:
	Pixel();
	Pixel(cv::Mat );
	~Pixel();

	void setImage(cv::Mat );

	cv::Mat pixelManipulationRed(int );
	cv::Mat pixelManipulationBlue(int );
	cv::Mat pixelManipulationGreen(int );
	cv::Mat pixelManipulationAll(int );

private:
	cv::Mat image_org_;
	int cols_;
	int rows_;
};

#endif //PIXEL_HPP
