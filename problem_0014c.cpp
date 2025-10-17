/*
Problem 14: Longest Collatz Sequence
The following iterative sequence is defined for the set of positive integers:

n → n / 2 (if n is even)
n → 3n + 1 (if n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proven yet (Collatz Conjecture), it is thought that all starting numbers eventually reach 1.

Task:
Write a program to find the starting number under one million that produces the longest Collatz sequence.

Constraints:
You must consider all starting numbers less than 1,000,000.
The sequence must be computed using integer arithmetic.
You may cache intermediate results to improve performance.
*/


#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>
#include <cstdint>

const int MAX = 1000000;

int main()
{
    auto start {std::chrono::high_resolution_clock::now()};

    // Shared cahce: sequence length excluding the starting element (edge choice explained below)
    std::vector<int> cache(MAX, 0);
    cache[1] = 1; // define length(1) = 1 for convenience

    int g_bestLen {0};
    int g_bestStart {1};

    #pragma omp parallel
    {
        // Per-thread best
        int l_bestLen {0};
        int l_bestStart {1};

        // Path buffer to avoid races; reused to avoid reallocations
        std::vector<uint64_t> path;
        path.reserve(1024);

        // Dynamic scheduling helps load balence (long chains skewed near upper range)
        #pragma omp for schedule(dynamic, 1024) nowait
        for (int i {2}; i < MAX; ++i)
        {
            uint64_t n = i;
            int count = 0;
            path.clear();

            // Traverse until hit cached or 1; collect path
            while (n != 1 && (n >= MAX || cache[n] == 0))
            {
                path.push_back(n);
                // Branchless-ish step using bit test
                if ((n & 1u) == 0u)
                    n >>= 1;
                else
                    n = 3 * n + 1;
                ++count;
            }
            // If within bounds and cached, add known tail length
            if (n < MAX) count += cache[n];
            else count += 1; // if n >= MAX and eventually hits 1, count accounted above

            // Path compression: write back computed lengths for nodes < MAX
            int len {count};
            for (size_t k {0}; k < path.size(); ++k)
            {
                uint64_t v {path[k]};
                if (v < MAX)
                {
                    // Single writer per index if first to comute; skip if already set to avoid races
                    if (cache[v] == 0) cache[v] = len;
                }
                --len;
            }

            // Record result for starting i
            int totalLen {count};
            if (totalLen > l_bestLen)
            {
                l_bestLen = totalLen;
                l_bestStart = i;
            }
        }

        // Combine per-thread bests without heavy contention
        #pragma omp critical
        {
            if (l_bestLen > g_bestLen)
            {
                g_bestLen = l_bestLen;
                g_bestStart = l_bestStart;
            }
        }
    }

    std::cout << "Starting number under one million with the longest Collatz sequence: " << g_bestStart << "\n";
    std::cout << "Length of sequence: " << g_bestLen << "\n";

    auto end {std::chrono::high_resolution_clock::now()};
    std::chrono::duration<double> duration = end - start;
    std::cout << "Exectution Time: " << duration.count() << " seconds\n";
    return 0;
}
