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
        int Day();
        void SetDay(int d);
        
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

class NewDate{
    public:
    NewDate(int d, int m, int y){
        Day(d);
    }
        int Day() { return day_; }
    void Day(int d);
    private:
        int day_{1};
        int month_{1};
        int year_{2};
};

void NewDate::Day(int d){
    day_ = d;
}

void Date::SetDay(int d){
     if (d >= 1 && d <= 31)
         this->day = d;
}


int Date::Day(){
    return this->day;
}


class Birthday{
    public:
        Birthday(int d, int m, int y);
        int Day();
        void SetDay(int d);
    
        
    private:
        int const day;
        int const month;
        int const year;
     
};

int Birthday::Day(){
    return this->day;
}

Birthday::Birthday(int d, int m, int y) : day(d), month(m), year(y){}


class Person{
public:
    Person(std::string name);
    
private:
    std::string s;
};

Person::Person(std::string d) : s(d){}


int main(int argc, const char * argv[]){
    
    Birthday(21, 01, 1995);
    Person pavan("Pavan");
    Person naveen("Naveen");

    return 0;
    
}



