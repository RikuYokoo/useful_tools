cmake_minimum_required(VERSION 3.10)

project(main CXX)

find_package(OpenCV REQUIRED)

add_executable(main main.cpp)
add_executable(trac trac.cpp)
add_executable(sample sample.cpp)

target_include_directories(sample PRIVATE ${OpenCV_DIR})
target_link_libraries(main ${OpenCV_LIBS})
target_link_libraries(sample ${OpenCV_LIBS})
target_link_libraries(trac ${OpenCV_LIBS})
