 /*
  * Problem 6: Sum Square Difference
  * The sum of the squares of the first ten natural numbers is:
  * 1² + 2² + ... + 10² = 385
  *
  * The square of the sum of the first ten natural numbers is:
  * (1 + 2 + ... + 10)² = 55² = 3025
  *
  * Hence, the difference between the square of the sum and the sum of the squares is:
  * 3025 - 385 = 2640
  *
  * Task:
  * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
  *
  * Solution:
  *  1. Loop through all the values of 1...100 and find the sum and sum of squares of each
  *  2. Useing the properties of summation that produces the Closed-form formulas allowing
  *     you to compute these values without havining to loop though the values
  *
  * */


#include <iostream>
#include <stdint.h>

int main()
{
    const uint32_t N {100};
    uint64_t sumSquare {(N * (N + 1) * (2*N + 1)) / 6};
    uint64_t squareSum {((N * (N + 1)) / 2) * ((N * (N + 1)) / 2)};
    uint64_t result {squareSum - sumSquare};

    std::cout << "The difference between the sum of the squares of the first one hundred natural numbers " << sumSquare
        << " and the square of the sum " << squareSum << " is " << result;

    return 0;
}
