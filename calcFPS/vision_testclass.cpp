#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <thread>
#include <chrono>

#include "vision_testclass.h"

visionTest::visionTest()
{
	initFPS();
}

visionTest::~visionTest()
{
}


void visionTest::initFPS()
{
	cnt_ = 1;
	prevt_ = getTime();
	currentt_ = prevt;
	sum_time_ = 0;
}

float visionTest::getTime()
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
