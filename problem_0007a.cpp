/*
Problem 7: 10,001st Prime
    By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

Task
    What is the 10,001st prime number?

Solution:
    1 is not a prime.
    All primes except 2 are odd.
    All primes greater than 3 can be written in the form 6k+/-1.
    Any number n can have only one primefactor greater than n .
    The consequence for primality testing of a number n is: if we cannot find a number f less than
    or equal n that divides n then n is prime: the only primefactor of n is n itself

Code Complexity:
    Time: O(n√n)
    Space: O(1)

*/

#include <iostream>
#include <cmath>
#include <cstdint>

bool isPrime(uint32_t n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    uint32_t limit{static_cast<uint32_t>(std::sqrt(n))};
    for (uint32_t i{5}; i <= limit; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    const uint32_t TARGET{10001};
    uint32_t count{2}; // 2 and 3 are already prime
    uint32_t candidate{5};

    while (true)
    {
        if (isPrime(candidate))
        {
            ++count;
            if (count == TARGET)
            {
                std::cout << "The 10,001st Prime: " << candidate << "\n";
                break;
            }
        }
        candidate += 2; // skip even numbers
    }

    return 0;
}
