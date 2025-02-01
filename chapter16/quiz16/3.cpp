/*Write a function that takes a std::vector, returns a std::pair 
containing the indices of the elements with the min and max values in the array.
The program should output the following:

With array ( 3, 8, 2, 5, 7, 8, 3 ):
The min element has index 2 and value 2
The max element has index 1 and value 8

With array ( 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 ):
The min element has index 4 and value 1.2
The max element has index 5 and value 8.8*/

#include <iostream>
#include <vector>

template<typename T>
auto findMinMax (const std::vector<T>& arr) -> std::pair<int, int>
{
    std::pair<int,int> min_max {0,0};

    for(std::size_t index {1}; index < arr.size(); ++index){
        if (arr[index] < arr[min_max.first])
            min_max.first = index;
        if (arr[index] > arr[min_max.second])
            min_max.second = index;
    }

    return min_max;
}

auto main() -> int
{
    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

    std::pair minmax_v1 {findMinMax(v1)};

    std::cout<<"The min element has index "<<minmax_v1.first<<" and value "<<v1[minmax_v1.first]<<"\n";
    std::cout<<"The max element has index "<<minmax_v1.second<<" and value "<<v1[minmax_v1.second]<<"\n";

    std::pair minmax_v2 {findMinMax(v2)};

    std::cout<<"The min element has index "<<minmax_v2.first<<" and value "<<v2[minmax_v2.first]<<"\n";
    std::cout<<"The max element has index "<<minmax_v2.second<<" and value "<<v2[minmax_v2.second]<<"\n";
}


