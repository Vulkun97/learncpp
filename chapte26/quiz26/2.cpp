/*Write a Pair class that allows you to specify separate types for each of the two values in the pair.
Name this class differently from the previous one because C++ does not currently allow you to “overload” 
classes that differ only in the number or type of template parameters.*/

#include <array>
#include <iostream>
#include <string_view>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

template<typename T, typename T1>
class Pair
{
    T m_x {};
    T1 m_y {};

public:
	Pair (const T& x, const T1& y)
	: m_x {x}
	, m_y {y}
	{}

	const T& first() const { return m_x; }

	const T1& second() const { return m_y; }
};

int main()
{
	Pair<int, double> p1 { 5, 6.7 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2 { 2.3, 4 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}