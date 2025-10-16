/*
 *  Problem 3: Largest Prime Factor
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143?
 *
 * General Solution:
 * 1. Begin with the smallest PF {2} -> if it's divisible by 2 continue to divide the number until it is no longer divisible by 2
 * 2. Continue to the next Prime and do so for all high and higher primes until the Quotient is 1
 *
 * Time Complexity: O(sqrt(n))
 * Space Complexity: O(1)
 *
 */

#include <iostream>
#include <bitset>
#include <stdint.h>

const uint32_t MAX{1U << 20}; // 2^20
const uint64_t PRIME{600851475143};

int main()
{

    uint64_t quo{PRIME};
    std::bitset<MAX + 1> primeFactors;

    // Handle Factor 2
    if (!(quo % 2))
    {
        primeFactors.set(2);
        while (!(quo % 2))
            quo /= 2;
    }

    // Check odd factors from 3 to sqrt(quo)
    for (uint64_t i{3}; i * i <= quo; i += 2)
    {
        if (!(quo % i))
        {
            primeFactors.set(i);
            while (!(quo % i))
                quo /= i;
        }
    }

    // if quo is still greater than 2, it's a prime factor
    if (quo > 2)
    {
        if (quo <= MAX)
        {
            primeFactors.set(quo);
        }
        else
        {
            std::cout << quo << " ";
        }
    }

    // List Prime Factors
    std::cout << "Prime Factors of " << PRIME << " are: ";
    for (uint32_t i{0}; i <= MAX; ++i)
    {
        if (primeFactors.test(i))
            std::cout << i << " ";
    }

    std::cout << "\n";

    return 0;
}
