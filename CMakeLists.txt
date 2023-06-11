cmake_minimum_required(VERSION 3.8)
project(exercise VERSION 1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
# for gcc less than v5.2 use -std=c++1y for c++14
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y") 
# add component to build
add_subdirectory(binarySearch)
add_subdirectory(heapSort)
add_subdirectory(quickSort)
add_subdirectory(backTrack)
add_subdirectory(graph)