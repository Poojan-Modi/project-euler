/*
 * Problem 4: Largest palindrome product
 *
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Question: Find the largest palindrome made from the product of two 3-digit numbers.
 *
 * Solutions:
 * 1. Brute Force: Check if the multiples of all 3-digits numbers are palendromic and start from the largest 3-digit number.
 * 2. find all the palendromic numbers below 999*999 and check if they can be factored into two 3-digit numbers.
 *
 */

#include <iostream>
#include <string>

bool isPalindrome(uint32_t n)
{
    std::string sNum{std::to_string(n)};
    size_t sLen{sNum.length()};
    for (int i{0}; i < sLen / 2; i++)
    {
        if (sNum[i] != sNum[sLen - i - 1])
            return false;
    }
    return true;
}

int main()
{
    uint32_t lrgPal{0};
    // find multiplications of 3-digit values from 999->100: check if isPalindrome
    for (uint32_t i{999}; i >= 100; i--)
    {
        for (uint32_t j{i}; j >= 100; j--)
        {
            uint32_t product{i * j};
            if (product < lrgPal)
                break; // No need to continue if the product is less than current largest palindrome

            if (isPalindrome(product))
            {
                lrgPal = product;
                break; // Found the largest for this i... moving on the next i
            }
        }
    }

    std::cout << "The largest palindrome of the multiple of two 3-digit numbers is: " << lrgPal << "\n";

    return 0;
}