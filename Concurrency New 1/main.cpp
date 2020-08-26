//
//  main.cpp
//  Concurrency New 1
//
//  Created by PavanKumar on 26/08/2020.
//  Copyright © 2020 PavanKumar. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::thread;

bool chopping = true;

void kitchenCleaner(){
    while(true){
        cout << "Thread 5 cleaned the kitchen" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void vegetableChopper(const char* name){
    unsigned int choopedVegetables = 0;
    while(chopping){
        choopedVegetables++;
    }
    cout << name <<" Chopped vegetables count : " << choopedVegetables << endl;
}

void looper(){
    cout << "Process Id again: " << getpid() << endl;
    cout << "Thread id : " << std::this_thread::get_id() << endl;
    //while(true) continue;
}

int main(int argc, const char* argv[]) {
    
    cout << "Main process id: " << getpid() << std::endl;
    cout << "Main thread id: " << std::this_thread::get_id() << endl;
    
    thread thread5(kitchenCleaner);
    thread5.detach();  // Explicitly informs the main to exit without waiting for thread5 to complete
    
    thread thread3(vegetableChopper, "Thread3");
    thread thread4(vegetableChopper, "Thread4");
    
    cout << "Thread 3 and thread 4 are chopping vegetables" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    chopping = false;
    
    thread3.join(); // Explicitly informs the main to wait for thread3 to complete and then exit
    thread4.join();
    
    /*thread thread1(looper);
    thread thread2(looper);
    
    while(true){
        cout << "I am living in main thread now" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }*/
    
    return 0;
}
