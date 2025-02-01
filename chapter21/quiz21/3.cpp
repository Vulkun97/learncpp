/*Write your own integer array class named IntArray from scratch (do not use std::array or std::vector). 
Users should pass in the size of the array when it is created, and the array should be dynamically allocated. 
Use assert statements to guard against bad data. 
Create any constructors or overloaded operators needed to make the following program operate correctly:*/

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

class IntArray
{
    int m_size {0};
    int* m_arr {nullptr};

public:
    IntArray(int size) : m_size {size} 
    {
        assert(size > 0 && "Size must be positive integer");
        m_arr = (new int[m_size]);
    }

    ~IntArray() {if (m_size > 0) delete m_arr;}

    IntArray(const IntArray& arr) : m_size {arr.m_size} 
    {
        m_arr = (new int[m_size]);

        for(std::size_t index {0}; index < m_size; ++ index)
        {
            m_arr[index] = arr.m_arr[index];
        }
    }

    IntArray& operator= (const IntArray& arr)
    {
        if (&arr == this)
            return *this;

        delete[] m_arr;

        m_size = arr.m_size;
        m_arr = (new int[m_size]);

        for(std::size_t index {0}; index < m_size; ++ index)
        {
            m_arr[index] = arr.m_arr[index];
        }

        return *this;
    }

    //void operator() (int size) {IntArray{size};}

    int& operator[](std::size_t index)
    {
        assert(index >= 0 && "Index out of range");
        assert(index < m_size && "Index out of range");

        return m_arr[index];
    }

    friend std::ostream& operator<< (std::ostream& out, IntArray arr)
    {
        for(std::size_t index {0}; index < arr.m_size; ++ index)
        {
            std::cout<<arr.m_arr[index]<<" ";
        }

        return out;
    }

    
};

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}