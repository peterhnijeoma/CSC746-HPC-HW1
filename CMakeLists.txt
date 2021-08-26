
cmake_minimum_required(VERSION 3.5)

project (sum_timer LANGUAGES CXX)

set(CMAKE_BUILD_TYPE "Release")
 
add_executable (simple_sum_timer simple_sum_timer.cpp)
add_executable (array_sum_timer array_sum_timer.cpp)
add_executable (random_sum_timer random_sum_timer.cpp)

