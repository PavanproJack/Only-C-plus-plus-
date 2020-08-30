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
#include <mutex>
#include <chrono>
#include <atomic>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::thread;

bool chopping = true;
unsigned int garlic_count = 0;
std::mutex pencil;

std::atomic<unsigned int> garlic_new_count(0);


void newShoppingList(const char* Threadname){
    //pencil.lock();
        for(int i = 0; i < 2000; i++){
            //std::this_thread::sleep_for(std::chrono::milliseconds(500));
            pencil.lock();
                garlic_count++;
            pencil.unlock();
            //cout<< Threadname << " : accessed the garlic_count just now" << endl;
        }
    //pencil.unlock();
}

void shoppingList(){
    for(int i = 0; i < 80000; i++){
        //garlic_count++;
        garlic_new_count++;
    }
}

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
    
    auto start = std::chrono::high_resolution_clock::now();
    
    // Atomic objects to prevent Data Races
    thread thread10(shoppingList);
    thread thread11(shoppingList);
    thread10.join();
    thread11.join();
    cout<< "Total Garlic Count is : " << garlic_new_count << endl;
    
    //Mutual Exclusion (Mutexes)
    
    thread thread8(newShoppingList, "Thread8");
    thread thread9(newShoppingList, "Thread9");
    
    thread8.join();
    thread9.join();
    
    cout<< "Total Garlic Count is : " << garlic_count << endl;
    
    //Data Races Start here
    thread thread6(shoppingList);
    thread thread7(shoppingList);
    
    thread6.join();
    thread7.join();
    cout<< "Total Garlic Count is : " << garlic_count << endl;
    
    thread thread5(kitchenCleaner);
    thread5.detach();  // Explicitly informs the main to exit without waiting for thread5 to complete
    
    thread thread3(vegetableChopper, "Thread3");
    thread thread4(vegetableChopper, "Thread4");
    
    cout << "Thread 3 and thread 4 are chopping vegetables" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    chopping = false;
    
    thread3.join(); // Explicitly informs the main to wait for thread3 to complete and then exit
    thread4.join();
    
    thread thread1(looper);
    thread thread2(looper);
    
    while(true){
        cout << "I am living in main thread now" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    
    
    auto stop = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    
    return 0;
}
