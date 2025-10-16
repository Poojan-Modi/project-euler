/*
 * Problem 5: Smallest Multiple
 *
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible with no remainder by all of the numbers from 1 to 20?
 *
 * Solution: Prime Powers Method
 * - Generate all prime numbers ≤ 20.
 * - For each prime p, find the highest power p^a such that p^a ≤ 20.
 * - Multiply all such p^a together to get the least common multiple (LCM).
 *
 * Time complexity: O(kloglogk)+O(k/logk)
 * Space Complexity: O(k)
 */

#include <iostream>
#include <stdint.h>
#include <cmath>
#include <vector>

// Generates a list of prime numbers up to k using the Sieve of Eratosthenes
std::vector<uint32_t> createPrimeSet(uint32_t k)
{
    std::vector<bool> isPrime(k + 1, true);
    std::vector<uint32_t> p{};

    isPrime[0] = false;
    isPrime[1] = false;

    // Sieve of Eratosthenes: mark non-primes
    for (int i{2}; i * i <= k; i++)
    {
        if (isPrime[i])
        {
            // Mark all multiples of i as non-prime
            for (int j = i * i; j <= k; j += i)
                isPrime[j] = false;
        }
    }

    // Collect all primes into vector p
    for (uint32_t i{0}; i <= k; i++)
        if (isPrime[i])
            p.push_back(i);

    return p;
}

int main()
{
    const uint32_t k{20};                    // Upper bound for divisibility
    const uint32_t limit{(uint32_t)sqrt(k)}; // Used to optimize exponent calculation
    uint64_t lcm{1};                         // Resulting least common multiple

    // Generate all primes ≤ k
    std::vector<uint32_t> p{createPrimeSet(k)};

    // For each prime, calculate the highest power ≤ k and multiply into lcm
    for (auto &p_i : p)
    {
        uint32_t a = 1;

        // Only calculate exponent if prime ≤ sqrt(k)
        // Because higher powers of larger primes exceed k
        if (p_i <= limit)
            a = (uint32_t)(log(k) / log(p_i)); // max exponent such that p^a ≤ k

        lcm *= (uint64_t)(pow(p_i, a)); // Multiply prime power into lcm
    }

    std::cout << "Smallest multiple divisible by all numbers from 1 to " << k << " is: " << lcm << "\n";
    return 0;
}
