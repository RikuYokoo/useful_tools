#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <chrono>

int main(int argc, char* argv[])
{
  using namespace std::literals::chrono_literals;
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

    auto end = std::chrono::high_resolution_clock::now();

    double ms_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.;

    std::cout << ms_time << " [ms] " << std::endl;

  }



  return 0;
}
