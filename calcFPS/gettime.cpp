#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <boost/date_time/posix_time/posix_time.hpp>

float getTime()
{
  static boost::posix_time::ptime tinit = boost::posix_time::second_clock::local_time();
  std::cout << "tinit = " << tinit << std::endl;
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
  std::cout << "now = " << now << std::endl;
	boost::posix_time::time_duration diff = now - tinit;
  std::cout << "diff = " << diff << std::endl;
	long long msec = diff.total_milliseconds();
	return msec/ 1000.;
}

int main(){

  int i=0;
  float prevt = getTime();
  float currentt=prevt;
  double sum_time=0;
  double fps;
  int cnt=1;
  while(1){
    currentt=getTime();
    sum_time+=currentt - prevt;
    fps = cnt/sum_time;
    std::cout << "fps = " << fps << std::endl;
    //float time = getTime();
    cnt++;
    prevt = currentt;
    //std::cout << "time" << time << "[s]" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "cnt = " << cnt << std::endl;
    std::cout << "sum_time = " << sum_time << std::endl;
    std::cout << "=====================================" << std::endl;
    i++;
    if(i==25) break;
  }

  return 0;
}

