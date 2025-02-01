/*Write a class named Ball. Ball should have two private member variables, 
one to hold a color (default value: black), and one to hold a radius (default value: 10.0). 
Add 4 constructors.

The program should produce the following result:

Ball(black, 10)
Ball(blue, 10)
Ball(black, 20)
Ball(blue, 20)*/

#include <iostream>
#include <string>
#include <string_view>

class Ball{
    static constexpr std::string default_color {"black"};
    static constexpr double default_radius {10.0};

    std::string m_color {default_color};
    double m_radius {default_radius};

public:

    Ball(const double& radius)                                  : Ball{default_color, radius} {}

    Ball(const std::string_view color = default_color, double radius = default_radius)    : m_color {color}, m_radius {radius} {
        std::cout<<"Ball("<<m_color<<", "<<m_radius<<")\n";
    }
};


int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}