#include <iostream>
#include <iterator>
#include "Timer.h"
#include <numeric>

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// index_min is the index of the lower bounds of the array we're searching.
// index_max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise

namespace binarySearchIterative {
int binarySearch(const int* array, int target, int index_min, int index_max)
{
    int index {((index_max - index_min) / 2) + index_min};

    while(1)
    {
        if (target == array[index])
        {
            return index;
        }

        if (target > array[index])
        {
            index_min = index;
            index = ((index_max - index) / 2 + index);

            if (index == index_min)
                return -1;
        }
        else
        {
            index_max = index;
            index = ((index - index_min) / 2 + index_min);

            if (index == index_max)
                return -1;
        } 
    }
}
}

inline namespace binarySearchRecursive 
{
    int binarySearch(const int* array, int target, int index_min, int index_max)
    {
        int index {((index_max - index_min) / 2) + index_min};

        while(1)
        {
        if (target == array[index])
        {
            return index;
        }

        if (target > array[index])
        {
            if (index == index_min)
                return -1;

            return binarySearch(array, target, index, index_max);
        }
        else
        {
            if (index == index_max)
                return -1;

            return binarySearch(array, target, index_min, index);
        } 
        }
    }   
}

namespace binarySearchIterativeLearnCpp
{
    int binarySearch(const int* array, int target, int min, int max)
{

    while (min <= max)
    {
        // implement this iteratively
        int midpoint{ std::midpoint(min, max) };
        // Before C++20
        // int midpoint{ min + ((max-min) / 2) }; // this way of calculating midpoint avoids overflow

        if (array[midpoint] > target)
        {
            // if array[midpoint] > target, then we know the number must be in the lower half of the array
            // we can use midpoint - 1 as the upper index, since we don't need to retest the midpoint next iteration
            max = midpoint - 1;
        }
        else if (array[midpoint] < target)
        {
            // if array[midpoint] < target, then we know the number must be in the upper half of the array
            // we can use midpoint + 1 as the lower index, since we don't need to retest the midpoint next iteration
            min = midpoint + 1;
        }
        else
        {
            return midpoint;
        }
    }

    return -1;
}
}

namespace binarySearchRecursiveLearnCpp 
{
    int binarySearch(const int* array, int target, int min, int max)
{

    // implement this recursively

    if (min > max)
        return -1;

    int midpoint{ std::midpoint(min, max) };
    // Before C++20
    // int midpoint{ min + ((max-min) / 2) }; // this way of calculating midpoint avoids overflow

    if (array[midpoint] > target)
    {
        return binarySearch(array, target, min, midpoint - 1);
    }
    else if (array[midpoint] < target)
    {
        return binarySearch(array, target, midpoint + 1, max);
    }

    return midpoint;
}
}

int main()
{
    constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    // We're going to test a bunch of values to see if they produce the expected results
    constexpr int numTestValues{ 9 };
    // Here are the test values
    constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    // And here are the expected results for each value
    int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };

    Timer t;

    // Loop through all of the test values
    for (int count{ 0 }; count < numTestValues; ++count)
    {
        // See if our test value is in the array
        int index{ binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
        // If it matches our expected value, then great!
        if (index == expectedValues[count])
             std::cout << "test value " << testValues[count] << " passed!\n";
        else // otherwise, our binarySearch() function must be broken
             std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    std::cout<<"\nTime elapsed: "<<t.elapsed()<<" s\n";
    return 0;
}