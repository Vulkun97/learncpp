/*a)
Write an Apple class and a Banana class that are derived from a common Fruit class. 
Fruit should have two members: a name and a color.*/
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

class Fruit
{
protected:
    std::string m_name {"???"};
    std::string m_color {"???"};
public:
    Fruit(std::string_view name, std::string_view color) 
    : m_name{name}
    , m_color{color}
    {}

    const std::string& getName() const
    {
        return m_name;
    }

    const std::string& getColor() const
    {
        return m_color;
    }
};

class Apple: public Fruit
{
protected:
	Apple(std::string_view name, std::string_view color)
		: Fruit{ name, color }
	{}
public:
    Apple(std::string_view color = "red")
    : Fruit("apple", color)
    {}
};

class Banana: public Fruit
{
public:
    Banana(std::string_view color = "yellow")
    : Fruit("banana", color)
    {}
};

/*b)
Add a new class to the previous program called GrannySmith that inherits from Apple.*/

class GrannySmith: public Apple
{
public:
    GrannySmith()
    : Apple("granny smith", "green")
    {}
};

int main()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}