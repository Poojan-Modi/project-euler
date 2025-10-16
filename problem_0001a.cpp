/*
 * Problem 1: Multiples of 3 or 5
 *
 * if we list all the natural numbers below 10 that are multiples of 3 or 5
 * {n∈N∣n<10 and (nmod3=0 or nmod5=0)} = {3,5,6,9}
 *
 * n∈N|n<1000 and (nmod3=0 or nmod5=0) ∑n = ?
 *
 * Solution: Using the formula of summation of n natural numbers
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

#include <iostream>

#define N 1000
#define A 3
#define B 5

int sumOfMultiples(int x)
{
    int n = (N - 1) / x;
    return x * n * (n + 1) / 2;
}

int main()
{
    int sum = sumOfMultiples(3) + sumOfMultiples(5) - sumOfMultiples(15);
    std::cout << "Optimized sum of multiples of 3 or 5 below " << N << ": " << sum << "\n";
    return 0;
}
