/*1. Make Point3d a friend class of Vector3d, and implement function Point3d::moveByVector().
2. Instead of making class Point3d a friend of class Vector3d, make member function Point3d::moveByVector a friend of class Vector3d.
3. Reimplement the solution to the prior step using 5 separate files: Point3d.h, Point3d.cpp, Vector3d.h, Vector3d.cpp, and main.cpp.*/

#include <iostream>

class Vector3d;

class Point3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point3d(double x, double y, double z)
		: m_x{x}, m_y{y}, m_z{z}
	{ }

	void print() const
	{
		std::cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ")\n";
	}

	void moveByVector(const Vector3d& v);
};

class Vector3d
{

private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Vector3d(double x, double y, double z)
		: m_x{x}, m_y{y}, m_z{z}
	{
	}

	void print() const
	{
		std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
	}

    friend void Point3d::moveByVector(const Vector3d& v);
};

void Point3d::moveByVector (const Vector3d& v) 
	{
		m_x = m_x + v.m_x;
        m_y = m_y + v.m_y;
        m_z = m_z + v.m_z;
	}



int main()
{
	Point3d p { 1.0, 2.0, 3.0 };
	Vector3d v { 2.0, 2.0, -3.0 };

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}