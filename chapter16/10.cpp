/*Write a program that pushes and pops values, and outputs the following sequence:

       (Stack: empty)
Push 1 (Stack: 1)
Push 2 (Stack: 1 2)
Push 3 (Stack: 1 2 3)
Pop    (Stack: 1 2)
Push 4 (Stack: 1 2 4)
Pop    (Stack: 1 2)
Pop    (Stack: 1)
Pop    (Stack: empty)*/

#include <iostream>
#include <vector>
#include <string>

void printStack (const std::vector<int>& arr){
    std::cout<<"\t(Stack:";
    if (arr.empty()){
         std::cout<<" empty)\n";
    }
    else{
        for (int elem: arr){
            std::cout<<" "<<elem;
        }
        std::cout<<")\n";
    }
}

void pushVal(std::vector<int>& arr, int val){
    std::cout<<"Push"<<val<<" ";
    arr.push_back(val);
    printStack(arr);
}

void popVal(std::vector<int>& arr){
    std::cout<<"Pop";
    arr.pop_back();
    printStack(arr);
}

auto main() -> int {
    std::vector <int> arr{};
    printStack(arr);
    pushVal(arr, 1);
    pushVal(arr, 2);
    pushVal(arr, 3);
    popVal(arr);
    pushVal(arr, 4);
    popVal(arr);
    popVal(arr);
    popVal(arr);
}