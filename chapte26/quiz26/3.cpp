/*A string-value pair is a special type of pair where the first value is always a string type, and the second value can be any type. 
Write a template class named StringValuePair that inherits from a partially specialized Pair class (using std::string as the first type, 
and allowing the user to specify the second type).*/

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

template<typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
    StringValuePair(std::string str, T y)
    : Pair<std::string, T>(str, y)
    {}
};

int main()
{
	StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}