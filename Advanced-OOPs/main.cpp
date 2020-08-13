//
//  main.cpp
//  Advanced-OOPs
//  Created by PavanKumar on 13/08/2020.
//  Copyright © 2020 PavanKumar. All rights reserved.
//

#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class Vehicle{
protected:
    //Vehicle(string ff, string cc);
    string fuel = "cng";
    string color = "black";
    int wheels = 0;
    string vehicle = " ";
    string Fuel(){ return fuel;}
    
    void Print(){
        cout<< "The "<< vehicle << " of color "<< color << " has "<< wheels << " wheels and runs with "<< fuel << endl;
    }
};


//Vehicle::Vehicle(string f, string c): fuel(f), color(c){}

 

class Car : public Vehicle{
public:
    //Car(bool s, string f);
    bool sunroof = false;
    void Print(){
        cout<< "The "<< this->vehicle << " of color "<< this->color << " has "<< this->wheels << " wheels and runs with "<< this->fuel << endl;
    }
};
 

class Bicycle : public Vehicle{
public:
    Bicycle(bool p);
    bool pedal = true;
};




int main(int argc, const char * argv[]) {
    
    //Vehicle v("df", "gf");
    //cout<< v.Fuel() << endl;
    
    /*Car car;
    car.fuel = "Diesel";
    car.sunroof = true;
    car.wheels = 4;
    car.vehicle = "car";*/
    
    Car x;
    x.Print();
    
    Vehicle vh;
    //cout<< vh.fuel << endl;
    
    
     
    
    return 0;
}
