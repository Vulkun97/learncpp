/*You are running a website, and you are trying to calculate your advertising revenue. 
Write a program that allows you to enter 3 pieces of data:

How many ads were watched.
What percentage of users clicked on an ad.
The average earnings per clicked ad.

Store those 3 values in a struct. 
Pass that struct to another function that prints each of the values. 
The print function should also print how much you made for that day 
(multiply the 3 fields together).*/

#include <iostream>

struct AddsStats{
    int adds_shown {};
    double percent_clicked {};
    double money_per_add {};
};

AddsStats getAddsStatistic(){
    AddsStats adds;

    std::cout<<"Enter how many adds were shown ";
    std::cin>>adds.adds_shown;

    std::cout<<"Enter percent of clicked users ";
    std::cin>>adds.percent_clicked;

    std::cout<<"Enter average money per add clicked ";
    std::cin>>adds.money_per_add;

    return adds;
}

void showEarnings (const AddsStats& adds){
    std::cout<<"You entered:\n";
    std::cout<<"Adds shown:                          "<<adds.adds_shown<<"\n";
    std::cout<<"Percentage of users clicked on adds: "<<adds.percent_clicked<<"\n";
    std::cout<<"Average money per add:               "<<adds.money_per_add<<"\n";

    std::cout<<"Your earnings:                       "<<adds.adds_shown * adds.percent_clicked * adds.money_per_add<<std::endl;

    return;
}

int main(){
    

    showEarnings(getAddsStatistic());
}
