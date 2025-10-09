/*
Problem 10: Summation of Primes
The sum of the primes below 10 is:

2 + 3 + 5 + 7 = 17
Find the sum of all the primes below two million.

Task
Write a program to compute the sum of all prime numbers less than 2,000,000.

Complexity
Time: Depends on the algorithm used (e.g., Sieve of Eratosthenes is O(n log log n))
Space: O(n) for sieve-based approaches
*/

#include <iostream>
#include <cstdint>
#include <vector>

#define MAX 2000000

int main()
{
    std::vector<bool> isPrime(MAX,true);
    isPrime[0] = isPrime[1] = false;


    for (uint64_t i {2}; i * i <= MAX; ++i)
    {
        if (isPrime[i])
        {
            for (uint64_t j {i * i}; j <= MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    uint64_t sum {0};
    for (uint64_t i {2}; i <= MAX; ++i)
    {
        if (isPrime[i])
        {
            sum += i;
        }
    }

    std::cout << "the sum of all primes < " << MAX <<" = " << sum << "\n";

    return 0;
}


