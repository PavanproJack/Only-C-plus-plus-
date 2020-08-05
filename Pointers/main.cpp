//
//  main.cpp
//  Pointers
//
//  Created by PavanKumar on 05/08/2020.
//  Copyright © 2020 PavanKumar. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    
    float num = 32;
    float* ptr;
    ptr = &num;
    //std::cout << sizeof(ptr)<<std::endl;
    
    double values[10];
    double* d_ptr = values;
    //cout<< d_ptr << endl;
    //cout<< values << endl;
    
    double numbers[5];
    // Array name automatically contains the address of the first element of the array.
    double* pNumbers = numbers;
    // Loop through the next addresses.
    /*for(int i = 0; i<10; i++){
        cout<< "values " << i << "address is : "  << pNumbers + i << endl;
    }*/
    
    
    
    return 0;
}
