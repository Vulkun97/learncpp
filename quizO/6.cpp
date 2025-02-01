/*Write a program that asks the user to input a number between 0 and 255. 
Print this number as an 8-bit binary number (of the form #### ####). 
Don’t use any bitwise operators. Don’t use std::bitset.*/

#include <iostream>
#include <string>

int main(){
    std::cout<<"Input number between 0 and 255\n";

    unsigned int number {};
    std::cin>>number;

    std::string binary_number{};
    for (int i = 0; i < 8; i++){
        if (!number){
            
            binary_number.insert(0, "0");
            continue;
        }


        if (number % 2){
            binary_number.insert(0, "1");
        }
        else{
            binary_number.insert(0, "0");
        }
            
        number /= 2;
    }

    binary_number.insert(4, " ");

    std::cout<<"Your number in binary form is "<<binary_number<<std::endl;
    return 0;
}