/*Modify the prior program so that the user can enter as many integers as they like. Stop accepting input when the user enters -1.

Print the vector and find the min and max elements.

When run with the input 3 8 5 2 3 7 -1, the program should produce the following output:

Enter numbers to add (use -1 to stop): 3 8 5 2 3 7 -1
With array ( 3, 8, 5, 2, 3, 7 ):
The min element has index 3 and value 2
The max element has index 1 and value 8

Do something reasonable when the user enters -1 as the first input.*/

#include <iostream>
#include <vector>

template<typename T>
auto findMinMax (const std::vector<T>& arr) -> std::pair<std::size_t, std::size_t>
{
    if (arr.size() == 0)
        return {-1, -1};

    std::pair<std::size_t,std::size_t> min_max {0,0};

    for(std::size_t index {1}; index < arr.size(); ++index){
        if (arr[index] < arr[min_max.first])
            min_max.first = index;
        if (arr[index] > arr[min_max.second])
            min_max.second = index;
    }

    return min_max;
}

auto populateInt(std::vector<int>& arr) -> void
{
    std::cout<<"Enter numbers to add (use -1 to stop): ";
    int number{-1};

    std::cin>>number;

    while (number != -1) {
        arr.push_back(number);
        std::cin>>number;
    } 
}

auto main() -> int
{
    std::vector<int> arr{};
    populateInt(arr);

    

    if(arr.size() != 0)
    {
        std::pair minmax {findMinMax(arr)};
        std::cout<<"The min element has index "<<minmax.first<<" and value "<<arr[minmax.first]<<"\n";
        std::cout<<"The max element has index "<<minmax.second<<" and value "<<arr[minmax.second]<<"\n";
    }
    else
        std::cout<<"You didnt enter any numbers.";
    
}