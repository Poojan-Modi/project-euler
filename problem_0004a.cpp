/*
 * Problem 4: Largest Palindromic Product
 * Find the largest palindromic product of two 3-digit numbers
 *
 * Example: 2-digit palendromic product => 9009 = 91 * 99
 *
 * Solution: 2 Brute-Force Methods
 * 1. FInd all the products of all the 3 digit numbers and find the largest palindromic product
 * 2. Find all the palindromic numbers between the largest to smallest products of two 3-digit numbers and check for which of those are also products of two 3-digit numbers
 *
 */

#include <iostream>
#include <stdint.h>

bool isPalindrome(uint32_t n)
{
    uint32_t original{n}, reverse{0};

    while (n > 0)
    {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }

    return reverse == original;
}

bool is3Digits(uint32_t n)
{
    return n >= 100 && n <= 999;
}

int main()
{
    // Max value = 999 * 999
    // least value = 100 *100
    uint32_t x{0}, lrgPal{0};

    for (uint32_t i{999 * 999}; i > 100 * 100; i--)
    {
        if (i <= lrgPal)
            break;
        if (isPalindrome(i))
        {
            for (uint32_t j{999}; j > 100; j--)
            {
                // Check if x the result of i / j is 3-digits in length
                if (!(i % j))
                {
                    x = i / j;
                    lrgPal = is3Digits(x) ? i : lrgPal;
                    break;
                }
            }
        }
    }

    std::cout << "The largest palindromic product of two 3-digit numbers: " << lrgPal << "\n";

    return 0;
}
