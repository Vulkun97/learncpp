/*Write a short program that prints the elements of the following vector to the screen using a loop:*/

#include <iostream>
#include <vector>
#include <limits>


template <typename T>
void printArray(const std::vector<T>& arr){
    for(std::size_t i {0}; i < arr.size(); i++){
        std::cout<<arr[i]<<' ';
    }

    if (arr.size() > 0)
        std::cout << '\n';
}

template <typename T>
int findElement(const std::vector<T>& arr, T element){
    for(std::size_t i {0}; i < arr.size(); i++){
        if (arr[i] == element)
            return i;
    }

    return -1;
}

void skip(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
T getValidNumber(std::string_view prompt, T low, T high)
{
    // First, read in valid input from user
    T val {};
    do
    {
        std::cout << prompt;
        std::cin >> val;

        // if the user entered an invalid character
        if (!std::cin)
            std::cin.clear(); // reset any error flags

        skip(); // ignore any extra characters in the input buffer (regardless of whether we had an error or not)

    } while (val < low || val > high);

    return val;
}
int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    for(std::size_t i {0}; i < std::size(arr); i++){
        std::cout<<arr[i]<<' ';
    }

    if (arr.size() > 0)
        std::cout << '\n';

    /*Update your code for the prior quiz solution so that the following program compiles and has the same output:*/
    printArray(arr);

    /*Given the solution for quiz 2, do the following:
    Ask the user for a value between 1 and 9. If the user does not enter a value between 1 and 9, repeatedly ask for an integer value until they do. 
    If the user enters a number followed by extraneous input, ignore the extraneous input. Print the array.
    Write a function template to search the array for the value that the user entered. 
    If the value is in the array, return the index of that element. If the value is not in the array, return an appropriate value.
    If the value was found, print the value and index. If the value was not found, print the value and that it was not found.*/

    auto input { getValidNumber("Enter a number between 1 and 9: ", 1, 9) };
    printArray(arr);

    int index{findElement(arr, input)};

    if (index >= 0){
        std::cout<<"Value "<<input<<" found in "<<index<<" position.\n";
    }
    else {
        std::cout<<"Value "<<input<<" was not found.\n";
    }

    /*Extra credit: Modify the prior program so that it can handle a std::vector containing non-int numeric values*/
    std::vector arrD{ 4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9 };
    printArray(arrD);
    auto inputD { getValidNumber("Enter a number between 1 and 9: ", 1.0, 9.0) };
    printArray(arrD);

    index = findElement(arrD, inputD);

    if (index >= 0){
        std::cout<<"Value "<<inputD<<" found in "<<index<<" position.";
    }
    else {
        std::cout<<"Value "<<inputD<<" was not found.";
    }

    return 0;
}