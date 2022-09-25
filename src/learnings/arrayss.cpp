#include<iostream>
#include "../include/learnings/arrayss.h"
#include<ctime>

// int scores[10];
int scores [] = {16, 2, 77, 40, 12071};
//  scores[3] {1};   // Need to check why this is wrong
// scores[3] = 12;
char char_array[] = {'a', 'b', 'c', 'd', 'e', 'f'};

char new_char_array[] = {"Hello World"};

int multi_dim_arr[4][3];

void declare_and_use_arrays(){
    // std::cout<< scores[12]<< std::endl;

    // check();
    // char_arrays();
    // random_arrays();
    multi_dim_arrays();
    
}

void check(){

    for(int& i : scores){
        i++;
        std::cout<< i << std::endl;
    }
    for(int j : scores){
        // i++;
        std::cout<< j << std::endl;
    }
    std::cout<< std::size(scores) << std::endl;
    std::cout<< sizeof(scores)<< std::endl;
    std::cout<< sizeof(scores[5])<< std::endl;
    std::cout<< sizeof(scores) / sizeof(scores[5]) << std::endl;
}

void char_arrays(){
    std::cout<< new_char_array << std::endl;
    std::cout<< new_char_array[10] << std::endl;
}

void random_arrays(){
    std::srand(std::time(0)); //use current time as seed for random generator
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable % 11 << '\n';
}

void multi_dim_arrays(){
    std::cout<< std::size(multi_dim_arr) << std::endl;
    std::cout<< std::size(multi_dim_arr[0]) << std::endl;
    
}













