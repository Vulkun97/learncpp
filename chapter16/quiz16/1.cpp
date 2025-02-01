/*Write definitions for the following queries. Use CTAD where possible.*/

#include <iostream>
#include <vector>
#include <string>

auto main() -> int {
    //a) A std::vector initialized with the first 6 even numbers.
    std::vector evens {2, 4, 6, 8, 10, 12};

    //b) A constant std::vector initialized with the values 1.2, 3.4, 5.6, and 7.8.
    const std::vector doubles {1.2, 3.4, 5.6, 7.8};

    //c) A constant std::vector of std::string_view initialized with the names “Alex”, “Brad”, “Charles”, and “Dave”.
    const std::vector<std::string_view> names {"Alex", "Brad", "Charles", "Dave"};

    using namespace std::literals::string_view_literals; // for sv suffix
    const std::vector names_sv { "Alex"sv, "Brad"sv, "Charles"sv, "Dave"sv }; // sv suffix needed for CTAD to infer std::string_view

    //d) A std::vector with the single element value 12.
    std::vector twelve {12};

    //e) A std::vector with 12 int elements, initialized to the default values.
    std::vector<int> twelve_elems (12);
}