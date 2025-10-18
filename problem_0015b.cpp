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
- Time: O(n^2) due to memoization
- Space: O(n^2) for memoization map

Link:
-------------
https://projecteuler.net/problem=15

*/

#include <iostream>
#include <chrono>
#include <map>

std::map<std::pair<int, int>, unsigned long long> meno;

unsigned long long findPaths(int x, int y)
{
    if (x == 0 || y == 0)
        return 1;

    auto key = std::make_pair(x, y);
    if (meno.count(key))
        return meno[key];

    if (x == y)
    {
        meno[key] = 2 * findPaths(x - 1, y);
        return meno[key];
    }

    meno[key] = findPaths(x - 1, y) + findPaths(x, y - 1);
    return meno[key];
}

int main()
{
    auto start{std::chrono::high_resolution_clock::now()};

    const int GRID_SIZE = 30;

    std::cout << "The total number of paths is: " << findPaths(GRID_SIZE, GRID_SIZE) << "\n";

    auto end{std::chrono::high_resolution_clock::now()};
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution Time: " << duration.count() << "\n";
    return 0;
}