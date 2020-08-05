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

class validDate{
public:
    validDate(int d, int m, int y);
    void setDate(int d, int m, int y);
    int daysInMonth(int m, int y);
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
    int day{0}; int month{0}; int year{0};
};

int validDate::daysInMonth(int m, int y){
    if(m == 2){ return 29;}
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    else
        return 31;
}

void validDate::setDay(int d){ day = d; }
void validDate::setMonth(int m){ month = m; }
void validDate::setYear(int y){ year = y; }

void validDate::setDate(int d, int m, int y){
    if(d >= 1 && d <= daysInMonth(m, y)){
        setDay(d);
        setMonth(m);
        setYear(y);
    }
}

validDate::validDate(int dt, int mth, int yr){
    
    setDate(dt, mth, yr);
}


int main(int argc, const char * argv[]){
    
    //Birthday(21, 01, 1995);
    //Person pavan("Pavan");
    //Person naveen("Naveen");
    validDate date(21, 01, 1995);
    
    assert(date.day == 21);
    return 0;
    
}



