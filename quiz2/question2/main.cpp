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

