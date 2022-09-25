#include<iostream>
#include "../include/learnings/literals.h"
#include <vector>
#include <typeinfo>

int add(int x, int y)
{
    std::cout << "In literal.cpp " << std::endl;
    return x + y;
}

void literals_and_for_loops(){

    constexpr int radius {6472};
    constexpr double diameter {24897.5};
    constexpr float perimeter {34.6f};

    std::vector<int> arr(2, 0);
    // std::cout << typeid(arr.size()).name() << '\n';
    for (auto i = 0; i != arr.size()-2; ++i){
        std::cout<< "Hello Pavan" << std::endl;
    }

    // size_t abc {2};
    const size_t COUNT = 1;

    for(size_t abc {2}; abc < COUNT; ++abc){
        std::cout<< abc << std::endl;
    }

    // for loop - multiple declarations
    for(size_t i{0}, j{1}, k{2}; k<1; i++, j+=1, k+=1){
        std::cout<< "i: " << i << " j: " << j << " k: " << k << std::endl;
    }

    std::cout<< "Here we go....." << std::endl;

}