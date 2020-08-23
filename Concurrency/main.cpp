//
//  main.cpp
//  Concurrency
//
//  Created by PavanKumar on 19/08/2020.
//  Copyright © 2020 PavanKumar. All rights reserved.
//

#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::thread;

void threadFun(){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    cout<< "Finished this thread \n";
}

void function_(){
    cout<< "Hello Pavan! This is our first C++ Concurrent Program" << endl;
}

class MyFunctor{
public:
    /*MyFunctor(int k = 34) : p(k){
        cout << "p value is : " << p << endl;
    }*/
    int mult(int x) {
        return x * p;
    }
    void operator() (string sr){
        /*cout << "Inside functor " << h <<  endl;
        for (int i = 0; i > -h ; i--){
            cout << "From inside Functor " << i << endl;
        }*/
        cout << "Inside functor: " << sr <<  endl;
    }
private:
    int p;
};

int main(){
    
    //Functors let you create objects that "look like" a function:

    // USING RAII approach
    //MyFunctor fct;
    string s = "Hey Nature is our mother. Protect her";
    thread t1((MyFunctor()), s);
    
    // USING TRY CATCH BLOCK APPROACH to ...
    try{
        for(int i = 0; i< 10; ++i){
            cout << "From Main " << i << endl;
        }
    }catch (const std::exception& e) { // caught by reference to base
        std::cout << " a standard exception was caught, with message '"
                  << e.what() << "'\n";
        t1.join();
    }
    
    cout<< "Inside Main \n";
    t1.join();
    
    return 0;
}
