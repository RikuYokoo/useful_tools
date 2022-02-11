#include <iostream>
#include <vector>
#include <filesystem>
#include "pixel.hpp"

using namespace std;
namespace fs = std::filesystem;

int main(){
	std::string filepath("20220204T164140");
	
	for(const auto& file : fs::directory_iterator(filepath))
	{
		cout << std::string(file.path()) << endl;
		cv::Mat image = cv::imread(std::string(file.path()));
		Pixel pixel(image);
		cv::Mat img = pixel.pixelManipulationAll(50);
		cv::Mat rimg = pixel.pixelManipulationRed(50);
		cv::Mat gimg = pixel.pixelManipulationGreen(50);
		cv::Mat bimg = pixel.pixelManipulationBlue(50);
		cv::Mat negimg = pixel.pixelManipulationAll(-50);
		cout << "ok"  << endl;
		cv::imshow("tets", img);
		cv::imshow("org", image);
		cv::imshow("red", rimg);
		cv::imshow("green", gimg);
		cv::imshow("blue", bimg);
		cv::imshow("negative", negimg);
		cv::waitKey(1000);
	}

  return 0;
}

