//
//  main.cpp
//  Concurrency New 3
//
//  Created by PavanKumar on 02/09/2020.
//  Copyright © 2020 PavanKumar. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <chrono>
#include <atomic>
#include <array>
#include <vector>
#include <shared_mutex>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::thread;


char WEEKDAYS[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//string WEEKDAYS[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int today= 0;
//std::mutex pencil;
std::shared_mutex pencil;

void calendar_reader(int readerID){
    for (int i=0; i<7; i++) {
        pencil.lock();
        printf("Reader-%d sees today is %s\n", readerID, WEEKDAYS[today]);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        pencil.unlock();
    }
}

void calendar_writer(int writerID){
    for (int i=0; i<7; i++) {
        pencil.lock();
        today = (today + 1) % 7;
        printf("Writer-%d updated date to %s\n", writerID, WEEKDAYS[today]);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        pencil.unlock();
    }
}

int main(int argc, const char * argv[]) {
    
    std::array<std::thread, 10> readers;
    for(unsigned int i = 0; i < readers.size(); i++){
        readers[i] = thread(calendar_reader, i);
        //readers[i].join();
    }
    
    std::array<thread, 2> writers;
    for(unsigned int j = 0; j < writers.size(); j++){
        writers[j] = thread(calendar_writer, j);
        //writers[j].join();
    }
    
    for (unsigned int i=0; i<readers.size(); i++) {
        readers[i].join();
    }
    for (unsigned int i=0; i<writers.size(); i++) {
        writers[i].join();
    }
    
    
    
    return 0;
}
