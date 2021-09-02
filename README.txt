# CSC746-HPC-HW1
code and documents for CSC746 High Performance Computing course Homework 1.

##########
# description of homework
##########

Overview

This is a multi-part assignment with multiple deliverables: multiple codes, a report in PDF format, and powerpoint slides summarizing results. Three students will give 5-minute presentations of their work in class on Weds 8 Sep 2021.

The objective for this assignment is to begin to study cache effects on modern processor architectures.

Coding projects: 
(1) arithmetic operations only,
(2) structured memory accesses (sum a vector),
(3) unstructured memory accesses (pointer chasing)

Deliverables 

1. A tarball/zipfile containing the three different codes along with a CMakeLists.txt file for use in building the codes (more details below).

2. A PDF report describing your implementation, results, and answers to homework questions (more details below).

3. Three students will give 5-minute presentations to the class describing their implementation and results. These will be chosen at random by the professor.

Part 0 - General Information

For each of the coding projects below, begin with the starter code project chrono_timer, and:

1. Make a copy of chrono_timer.cpp, which we refer to below as the template code, and create a new program from that template (see Lab 1 for instructions on obtaining the chrono_timer.cpp code);

2. Modify the CMakeLists.txt file to set up the build rules/etc for each new executable (there will be 3 of them, you choose the names). 

3. For compiling with -O3 and -O0 optimization, a suggestion is to make two different build directories, e.g, build_O3 and build_O0, and then run cmake with different flags in each directory.

For example, for the -O3 build:
% mkdir build_O3; cd build_O3
% cmake ../ -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS_RELEASE="-O3 -NDEBUG"
% make
# then run your code

And for the -O0 build:
% mkdir build_O0; cd build_O0
% cmake ../ -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS_RELEASE="-O0"
% make
# then run your code


Part 1 - Computing a Sum 

Modify the template code to 

1. Use the value read in from the command line, in argv[1], to be the number of loop iterations to execute;
2. Compute the sum from 0, 1, ... , N-1 where N-1 is (a) argv[1]-1, then (b) hard-coded inside your program; 
3. Do not use any arrays, vectors, etc, use only a single accumulator variable (hint: 64-bit unsigned integer) and a loop index variable (hint: 64-bit unsigned integer);
4. Make sure your std::chrono timer instrumentation surrounds only the sum loop;
5. After the timing code block, also print out the problem size and the elapsed time.

Execute the new code as follows:

1. Iterate over these problem sizes: [100000, 500000, 1000000, 5000000, 10000000, 50000000,  100000000, 500000000]. Do not put these problem sizes in a loop in your program, run your program from the command line passing in the problem size.
2. Record the runtime, as reported by your internal code timer, for each problem size using (a) values provided by the command line, or (b) hard-coded problem sizes.
3. Compile your code in two different optimization levels: -O0 and -O3, record timings for each configuration and for each of (a) command-line problem size specification and (b) hard-coded problem size specification

For your report:

1. Describe your implementation in plain, simple English. Feel free to include code snippets in your latex for illustration purposes.
2. In your results section, describe your methodology: what machine do you run on, what are its characteristics (what CPU processor and what clock rate, how much DRAM of what type and speed), what compiler version, what questions are you trying to answer? (Hint: if you use the same machine in several different studies, you only need to state the machine configuration once at the start of the Results section)
3. Produce plots showing runtime vs problem size in each of the 4 problem configurations: (a) command-line args (2 of them), and (b) compiler optimization levels (2 of them).


Part 2 - Structured Memory Accesses (sum elements in a vector via sequential access)

Modify the template code to 

1. Use the value read in from the command line, in argv[1], the problem size N;  
2. Create and initialize a data structure capable of holding 64-bit integer quantities, e.g., std::vector<unsigned long long> (there are other, additional suitable data types);
3. Create a loop to sum up the values of vector or array; 
4. Make sure your std::chrono timer instrumentation surrounds only the sum loop;
5. After the timing code block, also print out the problem size, the sum, and the elapsed time.

Execute the new code as follows:

1. Iterate over these problem sizes: [100000, 500000, 1000000, 5000000, 10000000, 50000000,  100000000, 500000000]. Do not put these problem sizes in a loop in your program, run your program from the command line passing in the problem size.
2. Record the runtime, as reported by your internal code timer, for each problem size using (a) values provided by the command line.
3. Compile your code in two different optimization levels: -O0 and -O3, record timings for each configuration and for each of (a) command-line problem size specification and (b) hard-coded problem size specification

For your report:

1. Describe your implementation in plain, simple English. Feel free to include code snippets in your latex for illustration purposes.
2. In your results section, describe your methodology: what machine do you run on, what are its characteristics (what CPU processor and what clock rate, how much DRAM of what type and speed), what compiler version, what questions are you trying to answer? (Hint: if you use the same machine in several different studies, you only need to state the machine configuration once at the start of the Results section)
3. Produce plots showing runtime vs problem size in each of the 2 compiler optimization levels. 


Part 3 - Unstructured Memory Accesses (sum elements in a vector via "random" access)

Modify the template code to 

1. Use the value read in from the command line, in argv[1], the problem size N;  
2. Create and initialize a data structure capable of holding 64-bit integer quantities, e.g., std::vector<unsigned long long>, and fill the vector/array with random numbers that are in the range 0..N-1 (hint, use lrand48() % N). 
3. Initialize a pointer to be 0 (zero);
4. Create a loop to from 0 to N that will:
     Access v[pointer] and add it to the sum, then
     Assign v[pointer] to be the new pointer
5. Make sure your std::chrono timer instrumentation surrounds only the sum loop;
6. After the timing code block, print out the problem size, the sum, and the elapsed time.

Execute the new code as follows:

1. Iterate over these problem sizes: [100000, 500000, 1000000, 5000000,  10000000, 50000000 , 100000000]. Do not put these problem sizes in a loop in your program, run your program from the command line passing in the problem size.
2. Record the runtime, as reported by your internal code timer, for each problem size using (a) values provided by the command line.
3. Compile your code in two different optimization levels: -O0 and -O3, record timings for each configuration and for each of (a) command-line problem size specification and (b) hard-coded problem size specification

For your report:

1. Describe your implementation in plain, simple English. Feel free to include code snippets in your latex for illustration purposes.
2. In your results section, describe your methodology: what machine do you run on, what are its characteristics (what CPU processor and what clock rate, how much DRAM of what type and speed), what compiler version, what questions are you trying to answer? (Hint: if you use the same machine in several different studies, you only need to state the machine configuration once at the start of the Results section)
3. Produce plots showing runtime vs problem size in each of the 2 compiler optimization levels.


Questions in the Report 

Please answer the following questions as part of your analysis/discussion of results:

1. What is the number of FLOPs/second you are able to realize in this assignment? Which of the 3 programs are you using to derive this figure, and why?
2. What is the min/max/average memory bandwidth you are able to realize in this assignment? And in which of the 3 programs does this happen, and why?
3. Produce a table showing the number of memory accesses/second (one column) and an estimate of memory latency (a second column) for the codes in Part 2 and Part 3 at different problem sizes. 
4. Which configuration produces the best number of memory accesses per second/lowest latency? Why?
5. Which configuration produces the worst number of memory accesses per second/highest latency? Why?
