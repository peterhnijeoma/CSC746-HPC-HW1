
cmake_minimum_required( VERSION 3.5)

project (sum_timer LANGUAGES CXX)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-Wall")

# uncomment the set(CMAKE_CXX_FLAGS ... ) line for either -O3 or -O0
#
# -O3 is full optimization in gcc/g++
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
#
# -O0 is no optimization in gcc/g++
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O0")
 
add_executable (simple_sum_timer simple_sum_timer.cpp)

