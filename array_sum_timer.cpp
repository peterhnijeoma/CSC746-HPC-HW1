// ##################################################################
// (C) 2021, Peter Ijeoma
//
// Description: Array elements sumation timer; calculates the elapsed
//              time for summing N elements. N is passed as
//              command line argument, and also hard coded in the
//              code.
//              The code is compiled in 2 optimization levels, O0
//              and O3.
// usage:
// 	     array_sum_timer N
// ##################################################################

#include <iostream>
#include <chrono>
#include <unistd.h>

int main (int argc, char *argv[])
{
     // default array size - this value determines number of elements in the array
     // used if user does not enter an argument on the command line
    long array_size = 10000;

    long long sum_accm = 0; // accumulator to hold sum of array elements

    if (argc > 1)  // if user enters and argument, use it.
        array_size = std::atol(argv[1]);

    // delcare and initialize array elements. the value of element i, is i.
    long a_var[array_size];
    for (long i = 0; i < array_size; i++)
    {
        a_var[i] = i;
    }
    
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time = std::chrono::high_resolution_clock::now();

    // sum array elemnts in sequence
    for (long i = 0; i < array_size; i++)
    {
        sum_accm += a_var[i];
    }

    std::chrono::time_point<std::chrono::high_resolution_clock> end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << " Elapsed time for summing " << array_size << " interger array elements is: " << elapsed.count() << " " << std::endl;
    
    return 1;
}
