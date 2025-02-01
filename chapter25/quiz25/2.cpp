/*Step 1
Create an abstract class named Shape. 
This class should have three functions: a pure virtual print function that takes and returns a std::ostream&, an overloaded operator<< and an empty virtual destructor.*/

#include <array>
#include <iostream>
#include <string_view>
#include <string>
#include <vector>
#include <algorithm>

class Shape
{
public:
    virtual std::ostream& print (std::ostream&) const = 0;

    virtual ~Shape()
    {
        std::cout<<"Shape deleted\n";
    }

    friend std::ostream& operator<< (std::ostream& out, const Shape& p)
    {
		return p.print(out);
	}
};

class Point
{
private:
	int m_x{};
	int m_y{};

public:

	Point(int x, int y)
		: m_x{ x }, m_y{ y }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};

/*Step 2
Derive two classes from Shape: a Triangle, and a Circle. The Triangle should have 3 Points as members. 
The Circle should have one center Point, and an integer radius. Override the print() function so the following program runs:*/

class Circle : public Shape
{
    Point m_p{0, 0};
    int m_radius {0};

public:
    ~Circle() override
    {
        std::cout<<"Circle deleted\n";
    }

    Circle (const Point& p, const int radius)
    : m_p {p}
    , m_radius {radius}
    {}

    Circle ()
    {}

    std::ostream& print (std::ostream& out) const override
    {
        out<<"Circle ("<<m_p<<", radius "<<m_radius<<")";
        return out;
    }

    const int getRadius() const
    {
        return m_radius;
    }
};

class Triangle : public Shape
{
    Point m_p1 {0, 0};
    Point m_p2 {0, 0};
    Point m_p3 {0, 0};

public:
    ~Triangle() override
    {
        std::cout<<"Triangle deleted\n";
    }

    Triangle (const Point& p1, const Point& p2, const Point& p3)
    : m_p1 {p1}
    , m_p2 {p2}
    , m_p3 {p3}
    {}

    std::ostream& print (std::ostream& out) const override
    {
        out<<"Triangle ("<<m_p1<<", "<<m_p2<<", "<<m_p3<<")";
        return out;
    }
};

/*Step 3
Given the above classes (Point, Shape, Circle, and Triangle), finish the following program:*/

int getLargestRadius (std::vector<Shape*> arr)
{
    int temp_rudius {0};
    for (const auto& elem: arr)
    {
        if (auto* temp_circle {dynamic_cast<Circle*>(elem)})
        {
            if (temp_circle->getRadius() > temp_rudius)
            {
                temp_rudius = temp_circle->getRadius();
            }
        }
    }

    return temp_rudius;
}

int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

	// print each shape in vector v on its own line here
    for (const auto elem: v)
    {
        std::cout<<*elem<<"\n";
    }

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here
    for (const auto& elem: v)
    {
        delete elem;
    }

	return 0;
}