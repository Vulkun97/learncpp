#include <iostream>

int main()
{   
    int num{};

    std::cout << "Enter an integer: ";
    std::cin >> num;

    std::cout << "Double that number is: " << num*2 << std::endl;

    return 0;
}