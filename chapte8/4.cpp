/*Now make the numbers print like this:

        1
      2 1
    3 2 1
  4 3 2 1
5 4 3 2 1*/

#include <iostream>

int main(){
    int outer{1};
    while (outer < 6){
        int inner {outer};
        int pudding {5 - outer};

        while (pudding-- > 0){
            std::cout<<" ";
        }

        while (inner > 0){
            std::cout<<inner;
            inner--;
        }

        std::cout<<std::endl;
        outer++;
    }
}