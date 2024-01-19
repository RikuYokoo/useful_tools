cmake_minimum_required(VERSION 3.16)

project(dual_camera_test CXX)

add_executable(dual)
add_executable(save_image)

find_package(OpenCV REQUIRED)

target_sources(dual PRIVATE main.cpp)
target_sources(save_image PRIVATE save_image.cpp)

target_link_libraries(dual PRIVATE ${OpenCV_LIBS})
target_link_libraries(save_image PRIVATE ${OpenCV_LIBS})
