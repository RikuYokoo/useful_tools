#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <chrono>
#include <filesystem>

namespace fs = std::filesystem;

enum class cameraType{
  RIGHT, 
  LEFT, 
  DEV0=RIGHT,
  DEV1=LEFT, 
  NONE=99
};

class SaveImage{
public:
  SaveImage() = delete;
  SaveImage(const cameraType&);
  ~SaveImage();
  void createSaveDirectory();
  void saveCapturedImage(const cv::Mat &);
private:
  int32_t image_count_;
  cameraType camera_type_;
  std::string capture_save_path;

};
SaveImage::SaveImage(const cameraType &camera_type): image_count_(0), camera_type_(camera_type_), capture_save_path("")
{
  createSaveDirectory();
}

SaveImage::~SaveImage()
{
}
void SaveImage::createSaveDirectory(){
	std::string capture_dir("game_images");
	if(!fs::exists(capture_dir)) {
		fs::create_directory(capture_dir);
  }
  std::string camera_save_path{"_left"};
  if(camera_type_ == cameraType::RIGHT){
    camera_save_path = "_right";
  }

	std::stringstream ss_capture;
	auto now_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	ss_capture << capture_dir << "/" << std::put_time(std::localtime(&now_t), "%Y%m%dT%H%M%S") << camera_save_path;
	capture_save_path = ss_capture.str();
	fs::create_directory(capture_save_path);
}

void SaveImage::saveCapturedImage(const cv::Mat &img)
{
			std::stringstream ss;
			ss << capture_save_path << "/" << std::setw(6) << std::setfill('0') << image_count_ << ".jpg";
			image_count_++;
			cv::Mat save_img;
			cv::cvtColor(img, save_img, cv::COLOR_YCrCb2BGR);
			cv::imwrite(ss.str().c_str(), save_img);
}


int main(int argc, char* argv[])
{
  using namespace std::literals::chrono_literals;
  SaveImage save_image_right(cameraType::RIGHT), save_image_left(cameraType::LEFT);
  cv::VideoCapture cap0, cap1;
  cap0.open(0, cv::CAP_V4L2);
  cap1.open(1, cv::CAP_V4L2);

  if(!cap0.isOpened() || !cap1.isOpened()){
    std::cerr << "cant open device" << std::endl;
    return -1;
  }

  cv::Mat frame0, frame1;
  while(true)
  {
    auto start = std::chrono::high_resolution_clock::now();
    cap0.read(frame0);
    cap1.read(frame1);

    if(frame0.empty() || frame1.empty()){
      std::cerr << "frame empty" << std::endl;
      return -1;
    }

    cv::imshow("camera 1", frame0);
    cv::imshow("camera 2", frame1);

    int key = cv::waitKey(1);
    if(key == 'q')
    {
      std::cout << "end" << std::endl;
      return 0;
    }
    if(key == 's'){
      save_image_right.saveCapturedImage(frame0);
      save_image_left.saveCapturedImage(frame1);
    }

    auto end = std::chrono::high_resolution_clock::now();

    double ms_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.;

    std::cout << ms_time << " [ms] " << std::endl;

  }



  return 0;
}
