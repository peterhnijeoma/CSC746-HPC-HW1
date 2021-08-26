// ##################################################################
// (C) 2021, Peter Ijeoma
//
// Description: Random summation of array elements timer; calculates
//              the elapsed time for summing N array elements in a
//              random fashion. Starting from element 0, the index i
//              for the next elemnt is the value of element 0 for N
//              iterations; N is passed as command line argument,
//              and also hard coded in the code. N also serves as the
//              array size. The code is compiled in 2 optimization 
//              levels, O0 and O3.
// usage:
// 	     random_sum_timer N
// ##################################################################

#include <iostream>
#include <chrono>
#include <unistd.h>
#include <random>

int main (int argc, char *argv[])
{
     // default array size - this value determines number of elements in the array
     // used if user does not enter an argument on the command line
    long arr_itn_size = 10000;

    long long sum_accm = 0; // accumulator to hold sum of array elements

    if (argc > 1)  // if user enters and argument, use it.
        arr_itn_size = std::atol(argv[1]);

    // delcare and initialize array elements.
    // the value of element i, is a random integer between 0 and arr_itn_size.
    long a_var[arr_itn_size];

    // random number generator
    std::default_random_engine gen;
    std::uniform_int_distribution<long> dist(0, arr_itn_size);

    for (long i = 0; i < arr_itn_size; i++)
    {
        a_var[i] = dist(gen);
    }
    
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time = std::chrono::high_resolution_clock::now();

    // sum array elemnts in sequence
    long arr_ind = 0;
    for (long i = 0; i < arr_itn_size; i++)
    {
        sum_accm += a_var[arr_ind];
        arr_ind = a_var[i];
    }

    std::chrono::time_point<std::chrono::high_resolution_clock> end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << " Elapsed time for summing " << arr_itn_size << " interger array elements is: " << elapsed.count() << " " << std::endl;
    
    return 1;
}


