//
//  main.cpp
//  Pointers
//
//  Created by PavanKumar on 05/08/2020.
//  Copyright © 2020 PavanKumar. All rights reserved.
//

#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;
using std::string;

class pointerArray{
public:
    pointerArray(int size);
    void initializeArray();
    void resizeArray(int size);
    void viewMyArray();
    
private:
    int size;
    int* arr;
};

pointerArray :: pointerArray(int sz) : size(sz){}

void pointerArray::initializeArray(){
    //arr = new int[size];
    int arr[size];
    for(int i = 0; i < size; i++){
        //*(arr + i) = i;
        arr[i] = i;
    }
    cout << "Double Array Created: " << sizeof(arr) << endl;
}

void pointerArray::viewMyArray(){
    cout << size << endl;
    for(int j = 0; j < sizeof(arr) ; j++) {
        cout << j << " : " << arr[j] << endl;
    }
}

void pointerArray::resizeArray(int size){
    
    if(size == this->size){
        cout<< "I don't want to do this bcz....." << endl;
        return;
    }
    double* newArr = new double[size];
    for(int j = 0; j < size ; j++) {
        newArr[j] = arr[j];
    }
    //this->size = size;
    
    cout << "Array Resized to " << sizeof(newArr) << endl;
   
}

class deref{
public:
    deref(double ang) : angle(ang){}
    void calcAngles(){
        sine = std::sin(angle);
        cosin = std::cos(angle);
    }

private:
    double angle{0.0};
    double sine{0};
    double cosin{0};
};

/* Swap Functionality with C++ Templates */

template <typename T>
void swap(T &var1, T &var2) {
    var1 += var2;           // add variable2 to variable 1
    var2  = var1 - var2;    // subtract variable 2 from variable 1 to get new variable 2
    var1 -= var2;           // subtract new variable 2 from new variable 1 to get newest variable 1
}

/*void addSpaces(const char* &str) {
    char *temp = new char(sizeof(str)*2);
    char *start = temp;

    while (*str != '\0') {
        *temp++ = *str++;
        *temp++ = ' ';
    }
    str = start;
}*/

int main(int argc, const char * argv[]) {
    
    
    char* kst = new(std::nothrow) char('C');
    char str[] = "AAA";

    
    int* ktr = NULL;
    ktr = new(std::nothrow) int;
    
    if(!ktr){
        cout<< "Memory Allocation Failed" << endl;
    }
    else{
        *ktr = 31;
        cout<< "Value at the address: pointer is : " << *ktr << endl;
        cout<< "Pointing to the address : " << ktr << endl;
    }
    
    float* arrays = new(std::nothrow) float[10];
    if(!arrays){
        cout<< "Memory allocation to this array failed" << endl;
    }
    else{
        for(int i = 0; i < 10; i++){
                arrays[i] = i * i;
                cout<<" Address is: " << &arrays[i] << endl;
                cout<<" Value is: " << arrays[i] << endl;
        }
    }
    double* pointer = nullptr;
    pointer = new double(23);
    
    for(int i = 0; i<4; i++ ){
        *pointer = ++ *pointer ;
        cout << "Value at the address: pointer is : " << *pointer << endl;
    }
    
    delete pointer;
    delete ktr;
    delete[] arrays;
    
    //cout << "New Value at the address: pointer is : " << *pointer << endl;
    
    /*std::string str = "Hello World";
    const char* ptr = str.c_str();
    std::cout<<"string is: "<<ptr<<std::endl;
    addSpaces(ptr);
     
    std::cout<<"string is: "<<ptr<<std::endl;*/
    
    //cout<< str<< endl;
    
    //deref df(30);
    //df.calcAngles();
    
    /*float first_var = 18.10;
    float second_var = 20.22;
    
    std::cout << "Calling function swap() -----> " << "\n";
    swap(first_var, second_var);
    
    std::cout << "first_var : " << first_var << "\n";
    std::cout << "second_var : " << second_var << "\n";*/
    
    /*int var1 = 8;
    double var2 = 8.2;

    int &ref1 = var1;
    double &ref2 = var2;

    std::cout << ref1 << "\n";
    std::cout << ref2 << "\n";

    // modify variables
    var1 = 3;
    var2 = 9.5;

    std::cout << ref1 << "\n";
    std::cout << ref2 << "\n";*/
    
    /*pointerArray pA(4);
    pA.initializeArray();
    pA.viewMyArray();
    pA.resizeArray(13);
    pA.viewMyArray();*/
    
    /*
    int* ptr = nullptr;
    ptr = new int;
    
    int g = 334;
    *ptr = g;
    
    // *ptr = 8;
    cout<< ptr << endl;
    
    delete ptr;
    
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
     for(int i = 0; i<10; i++){
         cout<< "values " << i << "address is : "  << pNumbers + i << endl;
     }
     
     double testScores[5], sum = 0;
     double* p_tScore;
     p_tScore = testScores;
     double Q;
     for(int i = 0; i<5; i++){
         cout<< "Enter score "<< i << endl;
         cin >> Q;
         //cout << "Q value is : " << Q;
         *(p_tScore + i) = Q;
         sum = sum + *(p_tScore + i);
     }
     for(int j : testScores){
         cout << j << endl;
     }
     */
    return 1;
}
