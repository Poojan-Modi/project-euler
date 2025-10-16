#include <iostream>
/*
 *  Problem 1: Multiples of 3 or 5
 *
 * if we list all the natural numbers below 10 that are multiples of 3 or 5
 * {n∈N∣n<10 and (nmod3=0 or nmod5=0)} = {3,5,6,9}
 *
 * n∈N|n<1000 and (nmod3=0 or nmod5=0) ∑n = ?
 *
 * Solution: Loop through the first N numbers and calculate the summation of multiples of A nand B that are below N
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#define N 1000
#define A 3
#define B 5

int main()
{
    int sum{0};
    for (int i = 0; i < N; i++)
    {
        if (i % A == 0 || i % B == 0)
        {
            sum += i;
        }
    }

    std::cout << "Sum of the multiples of " << A << " and " << B << " below " << N << ":\t" << sum << "\n";
    return 0;
}
