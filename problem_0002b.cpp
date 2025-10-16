#include <iostream>
#include <cstdint>

constexpr uint32_t MAX_VALUE{4000000}, F_1{2}, F_2{8};

int main()
{
    uint32_t curr{F_2}, prev{F_1}, sumOfEvenFib{F_1 + F_2};

    while (true)
    {
        uint32_t next = 4 * curr + prev;
        if (next >= MAX_VALUE)
            break;

        sumOfEvenFib += next;
        prev = curr;
        curr = next;
    }

    std::cout << "Sum of even Fibonacci numbers less than " << MAX_VALUE << ":\t" << sumOfEvenFib << "\n";
    return 0;
}
