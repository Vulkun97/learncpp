/*Initialize a std::vector with the following values: ‘h’, ‘e’, ‘l’, ‘l’, ‘o’. 
Then print the length of the array (use std::size()). 
Finally, print the value of the element with index 1 
using the subscript operator and the at() member function.
The program should output the following:
The array has 5 elements.
ee*/

#include <iostream>
#include <vector>

auto main() -> int
{
    std::vector<char> data {'h', 'e', 'l', 'l', 'o'};
    std::cout<<"The array has "<<std::size(data)<<" elements.\n";
    std::cout<<data[1]<<data.at(1);
}