/*
Problem 7: 10,001st Prime
    By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

Task
    What is the 10,001st prime number?

Solution:
    Modified Sieve of Eratosthenes method

Code Complexity:
    ime: O(n log log n)
    Space: O(n)
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>

uint32_t nthPrime(uint32_t n)
{
    // Estimate the upper bound of the nth prime
    uint32_t limit{static_cast<uint32_t>(n * log(n) + n * log(log(n)))};
    std::vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    if (n < 6)
        limit = 15;

    uint32_t count{0};
    for (uint32_t i{2}; i <= limit; ++i)
    {
        if (isPrime[i])
        {
            ++count;
            if (count == n)
                return i;
            for (uint32_t j{i * 2}; j <= limit; j += i)
                isPrime[j] = false;
        }
    }

    return 0;
}

int main()
{
    uint32_t n{10001};
    uint32_t prime{nthPrime(n)};

    std::cout << "The 10,001st Prime: " << prime << "\n";

    return 0;
}
