/*Write a class named Average that will keep track of the average of all integers passed to it. 
Use two members: The first one should be type std::int32_t, and used to keep track of the sum of all the numbers you’ve seen so far. 
The second should keep track of how many numbers you’ve seen so far. You can divide them to find your average.*/
#include <array>
#include <string>
#include <string_view>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <utility>
#include <limits>
#include <functional>
#include <numeric>
#include <cinttypes>

class Average
{
    std::int32_t m_sum{0};
    int m_count {0};

public:
    friend std::ostream& operator<< (std::ostream& out, const Average& average)
    {
        if (average.m_count == 0)
            std::cout<<0;
        else
            std::cout<<static_cast<double>(average.m_sum)/average.m_count;
        
        return out;
    }

    Average& operator+= (int num)
    {
        ++m_count;
        m_sum += num;
        return *this;
    }
};

int main()
{
	Average avg{};
	std::cout << avg << '\n';

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}