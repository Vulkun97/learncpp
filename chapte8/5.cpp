/*Modify the FizzBuzz program you wrote in the previous quiz to 
add the rule that numbers divisible by seven should be replaced with “pop”. 
Run the program for 150 iterations.

In this version, using an if/else chain to explicitly cover every possible 
combination of words will result in a function that is too long. 
Optimize your function so only 4 if-statements are used: one for each of the 
non-compound words (“fizz”, “buzz”, “pop”), and one for the case where a number is printed.*/

#include <iostream>

void FizzBuzzPop(int number);

int main(){
    FizzBuzzPop(150);
}

void FizzBuzzPop(int number){
    for (int i {1}; i <= number; i++){
        if (i % 3 == 0){
            std::cout<<"fizz";
        }
        if (i % 5 == 0){
            std::cout<<"buzz";
        }
        if (i % 7 == 0){
            std::cout<<"pop";
        }
        if (i % 3 && i % 5 && i % 7){
            std::cout<<i;
        }
        std::cout<<std::endl;
    }
}