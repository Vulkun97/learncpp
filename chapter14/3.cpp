/*Write a class named Ball. 
Ball should have two private member variables, one to hold a color, 
and one to hold a radius. Also write a function to print out the color and radius of the ball.
Produce the result:

Ball(blue, 10)
Ball(red, 12)*/
#include <iostream>
#include <string>
#include <string_view>

class Ball{
    std::string m_color {"none"};
    double m_radius {0};

public:
    Ball(std::string_view color, double radius) : m_color {color}, m_radius {radius} {}

    std::string_view getColor () const{
        return m_color;
    }

    const double& getRadius () const{
        return m_radius;
    }
};

void print (Ball ball){
    std::cout<<"Ball("<<ball.getColor()<<", "<<ball.getRadius()<<")\n";
}


int main()
{
	Ball blue{ "blue", 10.0 };
	print(blue);

	Ball red{ "red", 12.0 };
	print(red);

	return 0;
}