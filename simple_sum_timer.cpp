// ###############################################################
// (C) 2021, Peter Ijeoma
//
// Description: simple sumation timer; calculates the elapsed time
//              for summing N numbers from 1 to N. N is passed as
//              command line argument, and also hard coded in the
//              code.
//              The code is compiled in 2 optimization levels, O0
//              and O3.
// usage:
// 	     simple_sum_timer N
// ###############################################################

#include <iostream>
#include <chrono>
#include <unistd.h>

int main (int argc, char *argv[])
{
     // default sum size - this value determines number of iterations
     // used if user does not enter an argument on the command line
    long loop_size = 10000;

    long long sum_accm = 0; // accumulator to hold sum of numbers

    if (argc > 1)  // if user enters and argument, use it.
        loop_size = std::atol(argv[1]);

    //std::cout << "Going to sleep for " << sleep_secs << " seconds " << std::endl;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_time = std::chrono::high_resolution_clock::now();

    // sum from 1 to N (loop size) in a loop
    for (size_t i = 0; i < loop_size; i++)
    {
        sum_accm += i;
    }

    std::chrono::time_point<std::chrono::high_resolution_clock> end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << " Elapsed time for summing " << loop_size << " interger numbers is: " << elapsed.count() << " " << std::endl;
    
    return 1;
}

