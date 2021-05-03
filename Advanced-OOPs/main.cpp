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

#define PI 3.141529

class Vehicle{
public:
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

class byke : protected Car{
public:
    float charging = 90.0;
    void Print(){
        cout << this->fuel<< endl;
    }
};
 

class Bicycle : private byke{
public:
    bool pedal = true;
    void Print(){
        cout<< this->color<<endl;
    }
};

class Animal{
public:
    string color = "white";
    string name = "Pavan";
    int age = 0;
};

class Snake : public Animal{
public:
    int length = 10;
    string MakeSound(){
        return "chchchch Sound" ;
    }
};

class Cat : public Animal{
public:
    float height = 12.2;
    string MakeSound(){
        return "Meow Sound" ;
    }
};

/***************Friend Class Declaration*/

class Square{
public:
    Square(float ss) : side(ss){}
    
private:
    friend class Rectangle;
    float side = 23.7;
};

class Rectangle{
public:
    Rectangle(Square sd) : width(sd.side), height(sd.side){}
    float Area(){
        return width * height;
    }
private:
    float width = 12.45;
    float height = 13.37;
};

/***************** PolyMorphism *************/
// Operator Overloading...

class Point{
private:
    int x = 0;
    int y = 2;
public:
    Point(int x_, int y_) : x(x_), y(y_){}
    
    void operator > (Point p2){
        if((this->x + this->y) < (p2.x + p2.y)){
            cout << "Sum Exceedes"<< endl;
        }else{
            cout<< "Sum ....."<< endl;
        }
    }
};

// Polymorphism: Overriding ---- Virtual Fnctions and Abstract Base Classes

class Animal_{  // Abstract base class - for implementing a Pure virtual function
public:
    virtual string Talk() const = 0;
    int size = 0;
};
class Cat_ : public Animal_{
public:
    string Talk() const{
        cout << "I make Meowww sound..." << endl;
        return string("Meow.....");
    }
};
class Dog_ : public Animal_{
    string Talk() const{
        cout << "I make bovvv-ovv sound..." << endl;
        return string("bovvv-ovv.....");
    }
};

// Virtual Functions

class Shape {
    public:
        Shape() {}
        virtual double Area() const = 0;
        virtual double Perimeter() const = 0;
};

class Rectangle_ : public Shape{
    public:
        Rectangle_(double ww, double hh) : width(ww), height(hh){}
        virtual double Area() const{ return width * height; }
        virtual double Perimeter() const{ return 2 * ( width + height); }
        
    private:
        double width{0};
        double height{0};
    
};

class Circle_ : public Shape{
    public:
        Circle_(double rr) : radius(rr){}
        virtual double Area() const{ return PI * radius * radius; }
        virtual double Perimeter() const{ return 2 * ( radius * PI); }
        
    private:
        double radius{0};
         
};

class Publish_
{
private:
    int t{0};
public:
    Publish_(int arg);
    ~Publish_();
    int getValue();
};

Publish_::Publish_(int arg)
{
    t = arg;
}

int Publish_::getValue(){
    return t;
}

Publish_::~Publish_()
{
}





int main(int argc, const char * argv[]) {
    
    //Vehicle v("df", "gf");
    //cout<< v.Fuel() << endl;
    
    /*Car car;
    car.fuel = "Diesel";
    car.sunroof = true;
    car.wheels = 4;
    car.vehicle = "car";*/
    
    /*Car x;
    x.Print();
    Bicycle byk;
    byk.Print();
    byke bk;
    bk.Print();*/
    
    /*Snake sm;
    Cat ct;
    
    cout<< "My Length is : " << sm.length << "and I make sound "<< sm.MakeSound()<<endl;
    
    cout<< "My Height is : " << ct.height << "and I make sound "<< ct.MakeSound()<<endl;
    
    Square sq(4.0);
    Rectangle rt(sq);
    
    cout<< rt.Area()<< endl;*/
    
    /*Point p1(30, 32), p2(12, 34);
    
    p1 > p2;*/
    

    Circle_ cv(2);
    cout<< cv.Area()<< endl;
    
    Rectangle_ rv(23, 45.56);
    cout<< rv.Perimeter() << endl;
    
    Publish_ tv = Publish_(56);
    cout << tv.getValue() << endl;
    
 
    
    
    
    
    
     
    
    return 0;
}
