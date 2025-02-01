#include <iostream>
#include "io.h"

int readNumber(){
    int num{};
    std::cout<<"Enter an integer: ";
    std::cin>>num;
    return num;
}

void writeAnswer(int number){
    std::cout<<"Answer is "<<number<<std::endl;
}