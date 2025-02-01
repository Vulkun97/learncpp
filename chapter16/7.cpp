/*Define a std::vector with the following names: 
“Alex”, “Betty”, “Caroline”, “Dave”, “Emily”, “Fred”, “Greg”, and “Holly”. 
Ask the user to enter a name. Use a range-based for loop 
to see if the name the user entered is in the array.*/

#include <iostream>
#include <vector>
#include <string>

auto main() -> int{
    std::vector<std::string_view> names {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::string guess {};
    std::cout<<"Enter a name ";
    std::cin>>guess;

    for(std::string_view name: names){
        if (name == guess){
            std::cout<<guess<<" was found.\n";
            return 0;
        }
    }

    std::cout<<guess<<" was not found.\n";
    return 0;
}