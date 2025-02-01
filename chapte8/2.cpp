/*Write a program that prints out the letters a through z along with their ASCII codes. Use a loop variable of type char.*/

#include <iostream>

int main(){
    char letter {'A'};

    do {
        std::cout<<letter<<" "<<static_cast <int> (letter)<<std::endl;
    } while (letter++ != 'Z');
}