/*

Project Euler Problem 15: Lattice Paths

Description:
-------------
In a 20×20 grid, you can only move right or down from the top-left corner to the bottom-right.
This program calculates the total number of unique paths using combinatorics.

Mathematical Insight:
---------------------
The number of lattice paths from (0,0) to (n,n) is given by:
    C(2n, n) = (2n)! / (n! * n!)
For a 20×20 grid:
    C(40, 20)

Constraints:
-------------
- Use integer arithmetic to avoid floating-point inaccuracies.

Methods:
----------
- Recursive + Memoization

Complexity:
-------------
- Time: O(n)
- Space: O(1)

Link:
-------------
https://projecteuler.net/problem=15

*/

#include <iostream>
#include <chrono>

unsigned long long binomialCoefficient(int n, int k)
{
    unsigned long long result = 1;
    for (int i = 1; i <= k; ++i)
    {
        result *= (n - k + i);
        result /= i;
    }
    return result;
}

int main()
{
    auto start{std::chrono::high_resolution_clock::now()};

    const int GRID_SIZE = 30;
    unsigned long long paths = binomialCoefficient(2 * GRID_SIZE, GRID_SIZE);

    std::cout << "The total number of paths is: " << paths << "\n";

    auto end{std::chrono::high_resolution_clock::now()};
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution Time: " << duration.count() << " seconds\n";

    return 0;
}
