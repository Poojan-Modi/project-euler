/*
Problem 10: Summation of Primes
The sum of the primes below 10 is:

2 + 3 + 5 + 7 = 17
Find the sum of all the primes below two million.

Task
Write a program to compute the sum of all prime numbers less than 2,000,000.

Complexity
Time: Depends on the algorithm used (e.g., Sieve of Eratosthenes is O(n log log n))
Space: O(n/2) for sieve-based approaches
*/


#include <iostream>
#include <vector>
#include <cstdint>

#define MAX 2000000
int main()
{
    // Only store odd numbers: index i reps numbers 2*i + 3
    std::vector<bool> isPrime((MAX - 1) / 2, true); // 2 is handled separetly
    uint64_t sum {2};

    for (size_t i {0}; (i * i * 4 + 12 * i + 9) < MAX; ++i)
    {
        if (isPrime[i])
        {
            uint64_t p = 2 *i + 3;
            for (size_t j {(p * p -3) / 2}; j < isPrime.size(); j += p)
            {
                isPrime[j] = false;
            }
        }
    }

    for (size_t i {0}; i < isPrime.size(); ++i)
    {
        if (isPrime[i])
        {
            sum += 2 * i + 3;
        }
    }

    std::cout << "the sum of all primes < " << MAX <<" = " << sum << "\n";
    return 0;
}
