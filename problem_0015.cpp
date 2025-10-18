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

2 Methods:
----------
- Grid based Traversal
- Efficient computation of large factorials or binomial coefficients

Complexity:
-------------
- Time: O(n) using iterative factorial
- Space: O(1) for factorial-based solution

Link:
-------------
https://projecteuler.net/problem=15

*/

#include <iostream>
#include <chrono>

int main()
{
    auto start{std::chrono::high_resolution_clock::now()};

    const int GRID_SIZE = 20;

    unsigned long long grid[GRID_SIZE + 1][GRID_SIZE + 1]{1};

    for (int i{0}; i <= GRID_SIZE; ++i)
    {
        for (int j{0}; j <= GRID_SIZE; ++j)
        {
            if ((i - 1 >= 0) && (j - 1 >= 0))
            {
                grid[i][j] += (grid[i - 1][j] + grid[i][j - 1]);
            }
            else if (i - 1 >= 0)
            {
                grid[i][j] += grid[i - 1][j];
            }
            else if (j - 1 >= 0)
            {
                grid[i][j] += grid[i][j - 1];
            }
        }
    }

    std::cout << "The total number of paths is: " << grid[GRID_SIZE][GRID_SIZE] << "\n";

    auto end{std::chrono::high_resolution_clock::now()};
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution Time: " << duration.count() << "\n";
    return 0;
}