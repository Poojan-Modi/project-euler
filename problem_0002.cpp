/*
 * Problem 2: Even Fibonacci Numbers
 * F_1 = 1,   F_2 = 2,    F_n = F_n−1 + F_n−2 for n>2
 * First 10: 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...
 *
 * {F_n ≤ 4,000,000 && F_n (mod2) ≡ 0} ∑F_n = ???
 *
 * Naive solution: iterate through the fibonacci sequence and add the relavent numbers
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#define MAX_VALUE 4000000
#define F_1 1
#define F_2 2

int main()
{
    int curr{F_2}, prev{F_1}, temp{0}, sumOfEvenFib{0};

    while (curr < MAX_VALUE)
    {
        if (curr % 2 == 0)
        {
            sumOfEvenFib += curr;
        }

        temp = curr;
        curr += prev;
        prev = temp;
    }

    std::cout << "Sum of even Fibonacci numbers less than " << MAX_VALUE << ":\t" << sumOfEvenFib << "\n";
    return 0;
}
