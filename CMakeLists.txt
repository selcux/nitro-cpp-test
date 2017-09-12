cmake_minimum_required(VERSION 3.8)
project(Assignment1)

set(CMAKE_CXX_STANDARD 11)

include_directories(include lib)

set(SOURCE_FILES lib include src src/main.cpp include/Rect.h include/helpers.h src/RectangleOperator.cpp include/RectangleOperator.h src/OutputFormatter.cpp include/OutputFormatter.h include/Intersection.h src/Rect.cpp)
add_executable(Assignment1 ${SOURCE_FILES})