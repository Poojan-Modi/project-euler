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
#include <map>
#include <chrono>

int main()
{
    // Start timing
    auto start {std::chrono::high_resolution_clock::now()};

    std::map<long long, int> collatzCache;
    const int MAX {1000000};


    int longestLength = 0;
    int longestStart = 0;


    for (int i {1}; i < MAX; ++i)
    {
        long long n {static_cast<long long> (i)};
        int count {0};

        while (n != 1)
        {
            if (collatzCache.contains(n))
            {
                count += collatzCache[n];
                break;
            }
            if (n % 2 == 0)
                n /= 2;
            else
                n = 3 * n + 1;
            ++count;
        }


        collatzCache[i] = count;

        if (count > longestLength)
        {
            longestLength = count;
            longestStart = i;
        }

    }


    std::cout << "Starting number under one million with the longest Collatz sequence: " << longestStart << "\n";
    std::cout << "Length of sequence: " << longestLength << "\n";


    // End timing and display execution duration
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution Time: " << duration.count() << " seconds\n";

    return 0;
}


