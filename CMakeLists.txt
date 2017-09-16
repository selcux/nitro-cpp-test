cmake_minimum_required(VERSION 3.8)
project(NitroPdfAssignment)

set(CMAKE_CXX_STANDARD 11)

include_directories(include lib)

set(SOURCE_FILES include/Rect.h src/RectangleOperator.cpp include/RectangleOperator.h src/OutputFormatter.cpp include/OutputFormatter.h include/Intersection.h src/Intersection.cpp)

set(RUNTIME_FILES ${SOURCE_FILES} src/main.cpp)
add_executable(NitroPdfAssignment ${RUNTIME_FILES})

#enable_testing()

set(TEST_FILES ${SOURCE_FILES} tests/test-main.cpp tests/test-rect.cpp tests/test-intersection.cpp tests/test-output-formatter.cpp tests/test-rectangle-operator.cpp tests/test.h)
add_executable(AssignmentTest ${TEST_FILES})

#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/tests/data DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)

#set_target_properties(AssignmentTest PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


