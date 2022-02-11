#include "pixel.hpp"
#include <algorithm>

Pixel::Pixel()
{
}
Pixel::Pixel(cv::Mat image)
{
	image_org_ = image;
	cols_ = image_org_.cols;
	rows_ = image_org_.rows;
}

Pixel::~Pixel(){}

void Pixel::setImage(cv::Mat img)
{
	image_org_ = img;
	cols_ = image_org_.cols;
	rows_ = image_org_.rows;
}
cv::Mat Pixel::pixelManipulationRed(int red)
{
	cv::Mat img(image_org_.rows, image_org_.cols, image_org_.type());
	for(int rows_i=0; rows_i<rows_; rows_i++){
		for(int cols_j=0;cols_j<cols_; cols_j++){
			int b = image_org_.at<cv::Vec3b>(rows_i,cols_j )[0];
			int g = image_org_.at<cv::Vec3b>(rows_i, cols_j)[1];
			int r = image_org_.at<cv::Vec3b>(rows_i, cols_j)[2];
			img.at<cv::Vec3b>(rows_i,cols_j)[0] = b;
			img.at<cv::Vec3b>(rows_i,cols_j)[1] = g;
			img.at<cv::Vec3b>(rows_i,cols_j)[2] = std::min(std::max(red+r, 0), 255);
		}
	}
	return img;
}
cv::Mat Pixel::pixelManipulationBlue(int blue)
{
	cv::Mat img(image_org_.rows, image_org_.cols, image_org_.type());
	for(int rows_i=0; rows_i<rows_; rows_i++){
		for(int cols_j=0;cols_j<cols_; cols_j++){
			int b = image_org_.at<cv::Vec3b>(rows_i,cols_j )[0];
			int g = image_org_.at<cv::Vec3b>(rows_i, cols_j)[1];
			int r = image_org_.at<cv::Vec3b>(rows_i, cols_j)[2];
			img.at<cv::Vec3b>(rows_i,cols_j)[0] = std::min(std::max(blue+b, 0), 255);
			img.at<cv::Vec3b>(rows_i,cols_j)[1] = g;
			img.at<cv::Vec3b>(rows_i,cols_j)[2] = r;
		}
	}
	return img;
}
cv::Mat Pixel::pixelManipulationGreen(int green)
{
	cv::Mat img(image_org_.rows, image_org_.cols, image_org_.type());
	for(int rows_i=0; rows_i<rows_; rows_i++){
		for(int cols_j=0;cols_j<cols_; cols_j++){
			int b = image_org_.at<cv::Vec3b>(rows_i,cols_j )[0];
			int g = image_org_.at<cv::Vec3b>(rows_i, cols_j)[1];
			int r = image_org_.at<cv::Vec3b>(rows_i, cols_j)[2];
			img.at<cv::Vec3b>(rows_i,cols_j)[0] = b;
			img.at<cv::Vec3b>(rows_i,cols_j)[1] = std::min(std::max(green+g, 0), 255);
			img.at<cv::Vec3b>(rows_i,cols_j)[2] = r;
		}
	}
	return img;
}
cv::Mat Pixel::pixelManipulationAll(int all)
{
	cv::Mat img(rows_, cols_, image_org_.type());
	for(int rows_i=0; rows_i<rows_; rows_i++){
		for(int cols_j=0;cols_j<cols_; cols_j++){
			int b = image_org_.at<cv::Vec3b>(rows_i, cols_j )[0];
			int g = image_org_.at<cv::Vec3b>(rows_i, cols_j)[1];
			int r = image_org_.at<cv::Vec3b>(rows_i, cols_j)[2];


			img.at<cv::Vec3b>(rows_i,cols_j)[0] = std::min(std::max(all+b, 0), 255);
			img.at<cv::Vec3b>(rows_i,cols_j)[1] = std::min(std::max(all+g, 0), 255);
			img.at<cv::Vec3b>(rows_i,cols_j)[2] = std::min(std::max(all+r, 0), 255);
		}
	}
	return img;
}
