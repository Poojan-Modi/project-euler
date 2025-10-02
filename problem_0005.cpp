 /*
  * Problem 5: Smallest Multiple
  *
  * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
  * What is the smallest positive number that is evenly divisible with no remainder by all of the numbers from 1 to 20?
  *
  * Solution: Factorization Method
  * find the factors of all the numbers from 20...1 (1 can technically be skiped)
  * factors that have been found don't need to be done again
  *
  * Time Complexity: O(k^(3/2))
  * Space COmplexity: O(k)
  */

#include <iostream>
#include <map>
#include <cmath>
#include <stdint.h>

void factorize(int n, std::map<int, int> & primeCounts)
{
    for (int i {2}; i <= n; ++i)
    {
        int count = 0;
        // if N is div by i, count max number of divisions
        while (n % i == 0)
        {
            ++count;
            n /= i;
        }
        // Update primeCounts if new count is greater then old count
        if (count > 0 && primeCounts[i] < count) primeCounts[i] = count;
    }
}


int main()
{
    std::map<int, int> primeCounts;

    for (int i = 2; i <= 20; ++i)
    {
        std::map<int, int> temp;
        factorize(i, temp);
        for (const auto& [prime, count] : temp)
        {
            primeCounts[prime] = std::max(primeCounts[prime], count);
        }
    }


    uint64_t result = 1;
    for (const auto& [prime, count] : primeCounts)
    {
        result *= static_cast<uint64_t>(std::pow(prime, count));
    }


    std::cout << "The smallest multiple of the numbers 1...20: " << result << "\n";
    return 0;
}

