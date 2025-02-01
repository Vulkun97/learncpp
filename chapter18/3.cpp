/*Unoptimized bubble sort performs the following steps to sort an array from smallest to largest:
A) Compare array element 0 with array element 1. If element 0 is larger, swap it with element 1.
B) Now do the same for elements 1 and 2, and every subsequent pair of elements until you hit the end of the array. 
At this point, the last element in the array will be sorted.
C) Repeat the first two steps again until the array is sorted.*/

#include <array>
#include <string>
#include <string_view>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <utility>

template <std::size_t N>
void bubble_sort(std::array<int, N>& arr)
{
    bool sorted{true};
    for(int i {N-1}; i > 0; i--)
    {
        sorted = true;

        for (int k {0}; k < i; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                std::swap(arr[k], arr[k + 1]);
                sorted = false;
            }
        }

        if (sorted)
        {
            std::cout<<"Early termination on iteration "<<N - i<<std::endl;
            return;
        }
            
    }
}

int main()
{
    std::array arr{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };

    bubble_sort(arr);

    for( auto e: arr)
    {
        std::cout<<e<<" ";
    }
}