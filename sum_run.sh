#! 

echo "no memory access run\n"
# run simple summation - default problem size
./simple_sum_timer

# run simple summation for various problem sizes
# [100000, 500000, 1000000, 5000000, 10000000, 50000000,
#  100000000, 500000000]

./simple_sum_timer 100000
./simple_sum_timer 500000
./simple_sum_timer 1000000
./simple_sum_timer 5000000
./simple_sum_timer 10000000
./simple_sum_timer 50000000
./simple_sum_timer 100000000
./simple_sum_timer 500000000

echo "sequential memory access run\n"
# run array summation (sequential memory access) - default problem size
./array_sum_timer

# run array summation (sequential memory access) for various problem sizes
# [100000, 500000, 1000000, 5000000, 10000000, 50000000, 100000000, 500000000]

./array_sum_timer 100000
./array_sum_timer 500000
./array_sum_timer 1000000
./array_sum_timer 5000000
./array_sum_timer 10000000
./array_sum_timer 50000000
./array_sum_timer 100000000
./array_sum_timer 500000000

echo "random memory access run\n"
# run array summation (random memory access) - default problem size
./random_sum_timer

# run array summation (random memory access) for various problem sizes
# [100000, 500000, 1000000, 5000000, 10000000, 50000000, 100000000, 500000000]

./random_sum_timer 100000
./random_sum_timer 500000
./random_sum_timer 1000000
./random_sum_timer 5000000
./random_sum_timer 10000000
./random_sum_timer 50000000
./random_sum_timer 100000000
./random_sum_timer 500000000



