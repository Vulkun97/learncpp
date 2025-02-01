/*Write a function that takes two parameters: a std::vector and an index. 
If the index is out of bounds, print an error. If the index is in bounds, print the value of the element.
Produce the following result:
The element has value 2
Invalid index
The element has value 1.1
Invalid index*/

#include <iostream>
#include <vector>

void printElement( const auto& arr, int index){
    if (index < 0 || index >= static_cast<int>(std::size(arr)))
        std::cout<<"Invalid index\n";
    else
        std::cout<<"The element has value "<<arr[index]<<"\n";
}

int main()
{
    std::vector v1 { 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}