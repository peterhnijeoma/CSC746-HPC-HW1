Readme file for CSC746_HomeWork_1 - contains 3 code files (simple_sum_timer.cpp, array_sum_timer.cpp, and random_sum_timer.cpp) and 1 CMakeLists.txt file. Also included is a shell script (sum_run.sh) for running the programs.

# Purpose:
The programs are to determine the effects of memory access pattern and compiler optimization on performance. The codes perform a summation of N integers (from 0 to N -1).


# build instructions:

1. create a directory (any name, eg.CSC746-HPC-HW1) and unzip the zip file CSC746_HomeWork_1.zip

% mkdir <directory name>

2. create 2 build directories (1 for zero optimization and another for maximum optimization)

% mkdir <build directory name>

3. compile for each optimization level

   # for zero optimization (level O0)
% cd <zero optimization build directory name>

% cmake ../ -DCMAKE_CXX_FLAGS_RELEASE="-O0"

% make
  # verify all 3 executables (simple_sum_timer, array_sum_timer, and random_sum_timer) are created

   # for maximum optimization (level O3)
% cd <maximum optimization build directory name>

% cmake ../

% make
  # verify all 3 executables (simple_sum_timer, array_sum_timer, and random_sum_timer) are created


# run instructions:

   # to run zero optimization code

% cd <zero optimization build directory name>

% ../sum_run.sh

   # to run maximum optimization code

% cd <zero optimization build directory name>

% ../sum_run.sh


after each run output of the run times for each code is displayed on the screen.

Note:
"%" = stands for user prompt - do not type on the terminal.

# EOF
