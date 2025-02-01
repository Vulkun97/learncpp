/*Create a Fruit base class that contains two private members: a name (std::string), and a color (std::string). 
Create an Apple class that inherits Fruit. Apple should have an additional private member: fiber (double). 
Create a Banana class that also inherits Fruit. Banana has no additional members.*/

#include <iostream>

class Fruit
{
    std::string m_name{};
    std::string m_color{};
public:
    Fruit(std::string_view name, std::string_view color)
        : m_name {name}, m_color {color}
        {}

    std::string_view getName() const
    {
        return m_name;
    }

    std::string_view getColor() const
    {
        return m_color;
    }
};

class Apple : Fruit
{
    double m_fiber{};
public:
    Apple(std::string_view name, std::string_view color, double fiber)
        : Fruit {name, color}, m_fiber {fiber}
        {}

    friend std::ostream& operator<<(std::ostream& out, const Apple& apple)
    {
        std::cout<<"Apple("<<apple.getName()<<", "<<apple.getColor()<<", "<<apple.m_fiber<<")";
        return out;
    }
};

class Banana : Fruit
{
public:
    Banana(std::string_view name, std::string_view color)
        : Fruit {name, color}
        {}

    friend std::ostream& operator<<(std::ostream& out, const Banana& banana)
    {
        std::cout<<"Banana("<<banana.getName()<<", "<<banana.getColor()<<")";
        return out;
    }
};

int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}