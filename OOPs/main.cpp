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
    public:
        int Day(){ return this->day; }
        void SetDay(int d){ if(d>0) this->day = d; }
        
        int Month(){ return this->month; }
        void SetMonth(int m){ if(m>0) this->month = m; }
    
        int Year(){ return this->year; }
        void SetYear(int y){ if(y>2000) this->year = y; }
    
    
    
    private:
        // Initialise structures here
        int day{1};
        int month{1};
        int year{0};
};

int main(int argc, const char * argv[]) {
    // insert code here...
     
    Date date;
    date.SetMonth(87);
    std::cout<< date.Year()<<std::endl;
    /*date.day   = 21;
    date.month = 01;
    date.year  = 1995;*/
    //std::cout<< date.day;
    //assert(date.Day() == 2);
    
    
    return 0;
    
}



