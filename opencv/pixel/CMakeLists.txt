cmake_minimum_required(VERSION 3.20)

project(main CXX)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "-std=c++17 -lstdc++fs -fPIC")
find_package(OpenCV REQUIRED)

add_executable(main main.cpp pixel.cpp pixel.hpp)
#target_include_directories(main PUBLIC .)
target_link_libraries(main ${OpenCV_LIBS})
#target_link_libraries(main ${stdc++fs})
#target_link_libraries(main std::filesystem)

