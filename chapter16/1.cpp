/*Define a std::vector using CTAD and initialize it with the first 5 positive square numbers (1, 4, 9, 16, and 25).*/
/*Define a std::vector (using an explicit template type argument) to hold the high temperature 
(to the nearest tenth of a degree) for each day of a year (assume 365 days in a year).*/
/*Using a std::vector, write a program that asks the user to enter 3 integral values. Print the sum and product of those values.

The output should match the following:

Enter 3 integers: 3 4 5
The sum is: 12
The product is: 60*/

#include <iostream>
#include <vector> 

int main (){
    std::vector data {1, 4, 9, 16, 25};
    std::vector<double> temperature (365);

    std::vector<int> input (3);
    std::cout<<"Enter 3 integers: ";
    for(int i{0}; i < 3; i++){
        std::cin>>input[i];
    }
    std::cout<<"The sum is: "<<input[0] + input [1] + input[2];
    std::cout<<"\nThe product is: "<<input[0] * input [1] * input[2];
    
}