/*
Problem 7: 10,001st Prime
    By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

Task
    What is the 10,001st prime number?

Solution:
    Mark the multiples of primes as false upto a large value.
    Keep track of the values until the 10,001st prime is found

Code Complexity:
    Time: O(n log log n)
    Space: O(n)
*/

#include <iostream>
#include <stdint.h>
#include <vector>

#define MAX_SIZE 200000

int main()
{
    std::vector<bool> isPrime(MAX_SIZE,true);

    isPrime[0] = isPrime[1] = false;

    for (uint64_t p {2}; p * p < MAX_SIZE; p++)
    {
        if (isPrime[p])
        {
            for (uint64_t i {p * p}; i < MAX_SIZE; i += p)
                isPrime[i] = false;
        }
    }

    uint64_t count {0}, p10001 {0};
    for (uint64_t i {2}; i < MAX_SIZE; ++i)
    {
        if (isPrime[i])
        {
            ++count;
            if (count == 10001)
            {
                p10001 = i;
                break;
            }
        }
    }

    std::cout << "The 10,001st Prime: " << p10001 << "\n";
    return 0;
}
