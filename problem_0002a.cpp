/*
 * Problem 2: Even Fibonacci Numbers
 * F_1 = 1,   F_2 = 2,    F_n = F_n−1 + F_n−2 for n>2
 * First 10: 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...
 *
 * {F_n ≤ 4,000,000 && F_n (mod2) ≡ 0} ∑F_n = ???
 *
 * Pattern: Every third value of the sequence after 2 is an even value
 * Property: E(n) = 4E(n-3) + E(n-6)
 *
 * Slighty optimized solution: Using the pattern observed and the mathematical relationship that is recognized as a result of this pattern. Only iterate over the even values
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 *
 */


#include <iostream>
#include <cstdint>
#define MAX_VALUE 4000000
#define F_1 2
#define F_2 8

int main()
{
    uint32_t  curr{F_2}, prev{F_1}, temp{0}, sumOfEvenFib{F_2 + F_1};

    while (true)
    {
        temp = curr;
        curr = 4 * curr + prev;
        if (curr > MAX_VALUE)
        break;

        sumOfEvenFib += curr;
        prev = temp;
    }

    std::cout << "Sum of even Fibonacci numbers less than " << MAX_VALUE << ":\t" << sumOfEvenFib << "\n";
    return 0;
}
