//
//  main.cpp
//  OOPs
//
//  Created by PavanKumar on 04/08/2020.
//  Copyright © 2020 PavanKumar. All rights reserved.
//
#include <cassert>
#include <iostream>

struct Date{
    // Initialise structures.
    int day{1};
    int month{1};
    int year{0};
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Date date;
    date.day   = 21;
    date.month = 01;
    date.year  = 1995;
    std::cout<< date.day;
    assert(date.day == 1);
    
    
    return 0;
    
}



