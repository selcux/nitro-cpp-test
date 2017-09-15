cmake_minimum_required(VERSION 3.8)
project(Assignment1)

set(CMAKE_CXX_STANDARD 11)

include_directories(include lib)

set(SOURCE_FILES include/Rect.h src/RectangleOperator.cpp include/RectangleOperator.h src/OutputFormatter.cpp include/OutputFormatter.h include/Intersection.h src/Intersection.cpp)

set(RUNTIME_FILES ${SOURCE_FILES} src/main.cpp)
add_executable(Assignment1 ${RUNTIME_FILES})

set(TEST_FILES ${SOURCE_FILES} tests/test-main.cpp tests/test-rect.cpp tests/test-intersection.cpp)
add_executable(Test ${TEST_FILES})

#[[
enable_testing()
add_test(NAME assignment-test
        COMMAND Test1)
]]
