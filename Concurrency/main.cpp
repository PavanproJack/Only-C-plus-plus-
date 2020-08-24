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
    void operator() (string sr){   // needs to be string& sr when passes by refeence.
        /*cout << "Inside functor " << h <<  endl;
        for (int i = 0; i > -h ; i--){
            cout << "From inside Functor " << i << endl;
        }*/
        cout << "Inside functor : " << sr <<  endl;
        sr = "Correctly said!";
    }
private:
    int p;
};

int main(){
    
    cout << "No of CPU cores available : " << thread::hardware_concurrency() << endl;
    
    cout << "Main thread id : " << std::this_thread::get_id() << endl;
    
    //Functors let you create objects that "look like" a function:

    // USING RAII approach
    //MyFunctor fct;
    string s = "Hey! Nature is our mother. Protect her.";
    //thread t1((MyFunctor()), std::ref(s)); // To pass parameters by reference. Here we share memory (s here) between main and child threads.
    thread t1((MyFunctor()), std::move(s));  // Used when s is no longer used. Here we are not sharing memory anymore rather we move the value of s to child thread. so cout will show an empty s value.
    cout << "Child thread id : " << t1.get_id() << endl;
    t1.join();
    cout<< "Inside Main : " << s << endl;
    
    
    
    
    
    // USING TRY CATCH BLOCK APPROACH to ...
    /*try{
        for(int i = 0; i< 10; ++i){
            cout << "From Main " << i << endl;
        }
    }catch (const std::exception& e) { // caught by reference to base
        std::cout << " a standard exception was caught, with message '"
                  << e.what() << "'\n";
        t1.join();
    }*/
    
    
    
    /*int id = 0;
    
    auto f1 = [&id](){ cout<< "a) ID inside  lambda is : " << id << endl; };
    
    ++id;
    
    auto f2 = [&id](){ cout << id << endl; };
    
    auto f3 = [id]()  { cout << id << endl; };
    
    auto f4 = [id]() mutable { cout << ++id << endl; };
    
    f1();
    f2();
    f3();
    f4();
    
    
    
    // insert code here...
    cout << "Hello, World! of COncurrent Programming running at ID : " << std::this_thread::get_id()<< endl;
    
    unsigned int cores = std::thread::hardware_concurrency();
    
    cout << "No of cores availables to support : " << cores << endl;
    
    thread t(threadFun);
    
    t.detach();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    cout << "Exiting from main \n";
    
    */
    

    
    return 0;
}
