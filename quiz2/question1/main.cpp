#include <iostream>

int readNumber();

void writeAnswer(int number);

int main()
{
    int num1{};
    int num2{};

    num1 = readNumber();
    num2 = readNumber();
    writeAnswer(num1 + num2);

    return 0;
}

int readNumber(){
    int num{};
    std::cout<<"Enter an integer: ";
    std::cin>>num;
    return num;
}

void writeAnswer(int number){
    std::cout<<"Answer is "<<number<<std::endl;
}