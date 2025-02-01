/*Write a function template to find the largest value in a std::vector. If the vector is empty, return the default value for the element type.*/

#include <iostream>
#include <vector>

template<typename T>
constexpr T findMax(const std::vector<T>& arr){
    

    if (arr.size() == 0)
        return T{};

    T value {arr[0]};

    for(std::size_t index{}; index < arr.size(); index++){
        if (arr[index] > value)
            value = arr[index];
    }
    return value;
}

int main()
{
    std::vector data1 { 84, 92, 76, 81, 56 };
    std::cout << findMax(data1) << '\n';

    std::vector data2 { -13.0, -26.7, -105.5, -14.8 };
    std::cout << findMax(data2) << '\n';

    std::vector<int> data3 { };
    std::cout << findMax(data3) << '\n';

    return 0;
}