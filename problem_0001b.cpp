#include <iostream>
/*
 *  Problem 1: Multiples of 3 or 5
 *
 * if we list all the natural numbers below 10 that are multiples of 3 or 5
 * {n∈N∣n<10 and (nmod3=0 or nmod5=0)} = {3,5,6,9}
 *
 * n∈N|n<1000 and (nmod3=0 or nmod5=0) ∑n = ?
 *
 * Solution: only multibles of A*i || B*i below N and calculate the summation of multiples of A nand B that are below N
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Notes: This method reduces the brute force method of N-1 iterations to N/3 + 1 iterations
 */

#define N 1000
#define A 5
#define B 3

 int main()
 {
    int sum{0};

    for (int i = 0; i * A < N || i * B < N; i++)
    {
        if (i * A < N)
        {
            sum += (i * A);
        }
        if (i * B < N && i * B % A != 0)
        {
            sum += (i * B);
        }
    }



    std::cout << "Sum of the multiples of " << A << " and " << B << " below " << N << ":\t" << sum << "\n";
    return 0;
 }
