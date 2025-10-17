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

const int MAX {1000000};

int main()
{
    // Start timing
    auto start {std::chrono::high_resolution_clock::now()};

    // SHared gLobal cache
    std::vector<int> g_collatzCache(MAX, 0);
    g_collatzCache[1] = 1;


    int g_longestLength {0};
    int g_longestStart {0};

    #pragma omp parallel
    {
        int l_longestLength {0};
        int l_longestStart {0};

        #pragma omp for nowait
        for (int i {2}; i < MAX; ++i)
        {
            long long n {i};
            int count {0};

            while (n != 1 && (n >= MAX || g_collatzCache[n] == 0))
            {
                n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
                ++count;
            }

            if(n < MAX)
                count += g_collatzCache[n];

            // ✅ Store result in the global cache safely
            #pragma omp critical
            {
                g_collatzCache[i] = count;
            }

            if (count > l_longestLength)
            {
                l_longestLength = count;
                l_longestStart = i;
            }
        }

        // Update global best result
        #pragma omp critical
        {
            if (l_longestLength > g_longestLength)
            {
                g_longestLength = l_longestLength;
                g_longestStart = l_longestStart;
            }
        }
    }


    std::cout << "Starting number under one million with the longest Collatz sequence: " << g_longestStart << "\n";
    std::cout << "Length of sequence: " << g_longestLength << "\n";


    // End timing and display execution duration
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution Time: " << duration.count() << " seconds\n";

    return 0;
}


