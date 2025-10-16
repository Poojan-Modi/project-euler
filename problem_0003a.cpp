/*
 *  Problem 3: Largest Prime Factor
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143?
 *
 * Solution:
 * 1. Begin with the smallest prime factor (2).
 * 2. Divide the number by each prime factor until it's no longer divisible.
 * 3. Continue with the next odd numbers up to sqrt(n).
 * 4. If the remaining quotient is greater than 2, it's a prime factor.
 *
 * Time Complexity: O(sqrt(n))
 * Space Complexity: O(1)
 */

#include <iostream>
#include <bitset>
#include <cstdint>

const uint32_t MAX{1U << 20}; // 2^20
const uint64_t PRIME{600851475143};

int main()
{
    uint64_t quo{PRIME};
    std::bitset<MAX + 1> primeFactors;
    uint64_t largestPF = 0;

    // Handle factor 2
    if (quo % 2 == 0)
    {
        primeFactors.set(2);
        largestPF = 2;
        while (quo % 2 == 0)
            quo /= 2;
    }

    // Check odd factors
    for (uint64_t i = 3; i * i <= quo; i += 2)
    {
        if (quo % i == 0)
        {
            primeFactors.set(i);
            largestPF = i;
            while (quo % i == 0)
                quo /= i;
        }
    }

    // If remaining quotient is a prime factor
    if (quo > 2)
    {
        largestPF = quo;
        if (quo <= MAX)
        {
            primeFactors.set(quo);
        }
        else
        {
            std::cout << quo << " ";
        }
    }

    // List prime factors
    std::cout << "Prime Factors of " << PRIME << " are: ";
    for (uint32_t i = 0; i <= MAX; ++i)
    {
        if (primeFactors.test(i))
            std::cout << i << " ";
    }

    std::cout << "\nLargest Prime Factor: " << largestPF << "\n";

    return 0;
}
