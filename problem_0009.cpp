/*
Problem: Special Pythagorean Triplet

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which:
    a² + b² = c²

For example:
    3² + 4² = 9 + 16 = 25 = 5²

There exists exactly one Pythagorean triplet for which:
    a + b + c = 1000

Task:
    Find the product abc.

Code Complexity:
    Time: O(√n)
    Space: O(1)
*/

#include <iostream>
#include <cmath>

#define TARGET 1000

int main()
{
    int a{0}, b{0}, c{0};

    // From Euclid's formula: a + b + c = 2m(m + n) = 1000
    // So we solve m(m + n) = 500
    for (int m{2}; m < (TARGET / 2); ++m)
    {
        if (500 % m == 0)
        {
            int k = 500 / m;
            int n = k - m;

            if (n > 0 && m > n)
            {
                a = m * m - n * n;
                b = 2 * m * n;
                c = m * m + n * n;
                break;
            }
        }
    }

    std::cout << "a = " << a << "\tb = " << b << "\tc = " << c << "\n";
    std::cout << "Product abc = " << a * b * c << "\n";

    return 0;
}
