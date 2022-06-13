#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xphoto.hpp>

//cv::Mat src = cv::imread("./mikan.jpg");
cv::Mat image = cv::Mat::zeros(500, 500, CV_8UC3);
int blue_ = 0;
int red_ = 0;
int green_ = 0;

void show_image(cv::Mat dst)
{
	double y = dst.at<cv::Vec3b>(10,10)[0];
	double cr = dst.at<cv::Vec3b>(10,10)[1];
	double cb = dst.at<cv::Vec3b>(10,10)[2];
	cv::Mat hsv;
	cv::cvtColor(image, hsv, cv::COLOR_BGR2HSV);
	double h = hsv.at<cv::Vec3b>(10,10)[0];
	double s = hsv.at<cv::Vec3b>(10,10)[1];
	double v = hsv.at<cv::Vec3b>(10,10)[2];
	if(s > 64 && s < 255){
		if(h > 0 && h < 30 || h > 150 && h < 180){
			std::cout << "hsv red in" << std::endl;
		}
		if(h > 100 && h < 140){
			std::cout << "hsv blue in" << std::endl;
		}
	}

	//std::cout << "[y, cr, cb] = [" << dst.at<cv::Vec3b>(10,10)[0] << ", " << dst.at<cv::Vec3b>(10.10)[1] << ", " << dst.at<cv::Vec3b>(10, 10)[2] << std::endl;
	std::cout << "[y, cr, cb] = [" << y << ", " << cr << ", " << cb << std::endl;
	std::cout << "[h, s, v] = [" << h << ", " << s << ", " << v << std::endl;
	cv::imshow("image", image);
	cv::imshow("ycrcb", dst);

}

void change_red( int red, void*)
{
	cv::Mat dst;
	 for(int i=0;i<image.cols;i++){
		 for(int j=0;j<image.rows;j++){
			 image.at<cv::Vec3b>(j, i)[2] = red;
		 }
	 }
	 cv::cvtColor(image, dst, cv::COLOR_BGR2YCrCb);
	 show_image(dst);
}

void change_blue( int blue, void*)
{
	cv::Mat dst;
	 for(int i=0;i<image.cols;i++){
		 for(int j=0;j<image.rows;j++){
			 image.at<cv::Vec3b>(j, i)[0] = blue;
		 }
	 }
	 cv::cvtColor(image, dst, cv::COLOR_BGR2YCrCb);
	 show_image(dst);
}

void change_green( int green, void*)
{
	cv::Mat dst;
	 for(int i=0;i<image.cols;i++){
		 for(int j=0;j<image.rows;j++){
			 image.at<cv::Vec3b>(j, i)[1] = green;
		 }
	 }
	 cv::cvtColor(image, dst, cv::COLOR_BGR2YCrCb);
	 show_image(dst);
}



int main(int argc, const char* argv[]) {


   //トラックバー表示
	cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
   cv::createTrackbar("red", "image", &red_, 255, change_red);
   cv::createTrackbar("green", "image", &green_, 255, change_green);
   cv::createTrackbar("blue", "image", &blue_, 255, change_blue);

   //最初の表示
	 change_red(0,0);
	 change_green(0,0);
	 change_blue(0,0);

   cv::waitKey(0);

   return 0;
}
