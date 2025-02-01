// Write function prototypes for the following cases. Use const if/when necessary.

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

// a) A function named max() that takes two doubles and returns the larger of the two.

double max(const double& x, const double& y){
    return x > y ? x : y;
}

// b) A function named swap() that swaps two integers.

void swap(int& x, int& y){
    x = x + y;
    y = x - y;
    x = x - y;
}

// c) A function named getLargestElement() that takes a 
//dynamically allocated array of integers and 
//returns the largest number in such a way that the caller 
//can change the value of the element returned (don’t forget the length parameter).

int& getLargestElement (int arr[], std::size_t length)
{
    std::size_t largestElemIndex {};
    for(std::size_t i {}; i < length-1; i++)
    {
        if (arr[i] < arr[i+1])
            largestElemIndex = i+1;
    }

    return arr[largestElemIndex];
}