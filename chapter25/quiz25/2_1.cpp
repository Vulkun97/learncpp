/*Extra credit: Update the prior solution to use a std::vector<std::unique_ptr<Shape>>. Remember that std::unique_ptr is not copyable.*/

#include <array>
#include <iostream>
#include <string_view>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class Shape
{
public:
    virtual std::ostream& print (std::ostream&) const = 0;

    constexpr Shape() {}

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

	constexpr Point(int x, int y)
		: m_x{ x }, m_y{ y }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};

class Circle : public Shape
{
    Point m_p{0, 0};
    int m_radius {0};

public:
    ~Circle() override
    {
        std::cout<<"Circle deleted\n";
    }

    constexpr Circle (const Point& p, const int radius)
    : m_p {p}
    , m_radius {radius}
    {}

    constexpr Circle ()
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

    constexpr Triangle (const Point& p1, const Point& p2, const Point& p3)
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

int getLargestRadius (std::vector<std::unique_ptr<Shape>>& arr)
{
    int temp_rudius {0};
    for (const auto& elem: arr)
    {
        if (auto* temp_circle {dynamic_cast<Circle*>(elem.get())})
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
    //std::unique_ptr<Shape> p{std::make_unique<Circle>(Point{ 1, 2 }, 7)};
    //std::cout<<*p.get()<<"\n";

    
	std::vector<std::unique_ptr<Shape>> v;
    v.reserve(3);
    v.emplace_back(std::make_unique<Circle>(Point{ 1, 2 }, 7));
    v.emplace_back(std::make_unique<Triangle>(Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }));
    v.emplace_back(std::make_unique<Circle>(Point{ 7, 8 }, 3));
    
	// print each shape in vector v on its own line here
    
    for (const auto& elem: v)
    {
        std::cout<<*elem<<"\n";
    }
    
	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here

	return 0;
}