cmake_minimum_required(VERSION 3.20)

project(main CXX)

add_executable(main gettime.cpp)

#find_package(Boost 1.65.1 REQUIRED COMPONENTS data_time)
find_package(Boost 1.65.1 REQUIRED )

target_link_libraries(main ${BOOST_LIBRARIES})
