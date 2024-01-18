cmake_minimum_required(VERSION 3.16)

project(dual_camera_test CXX)

add_executable(dual)

find_package(OpenCV REQUIRED)

target_sources(dual PRIVATE main.cpp)

target_link_libraries(dual PRIVATE ${OpenCV_LIBS})
