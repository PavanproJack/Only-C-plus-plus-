//
//  main.cpp
//  Concurrency New 2
//
//  Created by PavanKumar on 30/08/2020.
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
unsigned int potato_count = 0;

std::recursive_mutex pencil;

void add_garlic(){
    pencil.lock();
        //puts("Inside garlic lock");
        garlic_count++;
    pencil.unlock();
}
void add_potatoes(){
    pencil.lock();
        //puts("Inside potatoes lock");
        potato_count++;
    pencil.unlock();
}
void shopper(){
    for(int i = 0; i<10000; i++){
        pencil.lock();
            //puts("Inside Mail lock");
            add_garlic();
            add_potatoes();
        pencil.unlock();
    }
}
int main(int argc, const char* argv[]) {
    
    cout << "Main process id: " << getpid() << std::endl;
    cout << "Main thread id: " << std::this_thread::get_id() << endl;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    thread thread1(shopper);
    thread thread2(shopper);
    
    thread1.join();
    thread2.join();
    
    cout << "Garlic count : " << garlic_count << endl;
    cout << "Potatoes count : " << potato_count << endl;
    
    auto stop = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    
    return 0;
}
