//
//  main.cpp
//  Smart Pointers
//
//  Created by PavanKumar on 16/08/2020.
//  Copyright © 2020 PavanKumar. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <bitset>

using std::cout;
using std::endl;
using std::cin;
using std::string;


/*Pass by Pointer, Reference and Value*/
void add(int* k){
    *k += 10;
}

void passByValue(int i){
    int j = 1;
    printf("call-by-value: %p\n", &j);
}

void passByReference(int &i){
    int j = 1;
    printf("call-by-reference: %p\n", &j);
}

void passByPointer(int *i){
    int j = 1;
    printf("call-by-pointer: %p\n", &j);
}

struct MyStructure{
public:
    int i = 2;
    double d = 2.4;
    char a[5];
};

class MyClass {
 private:
  int* _number;

 public:
  MyClass() {
    std::cout << "Allocate memory\n";
    _number = (int *)malloc(sizeof(int));
  }
  ~MyClass() {
    std::cout << "Delete memory\n";
    free(_number);
  }
  void setNumber(int number) {
    *_number = number;
    std::cout << "Number: " << _number << "\n";
  }
};

struct test {
    private:
     int* _number;

    public:
     void setNumber(int number) {
       *_number = number;
       std::cout << "Number: " << _number << "\n";
     }
    
};

int main(int argc, const char * argv[]) {
    
    test *mc = (test *) malloc(2 * sizeof(test));
    mc[0].setNumber(42);
    free(mc);
    
    MyClass* mc2 = new(std::nothrow) MyClass();
    mc2[0].setNumber(43);
    mc2->setNumber(36);
    delete mc2;
    
    /*int val = 5;
    passByValue(val);
    passByReference(val);
    passByPointer(&val);*/
    
    /*
    MyStructure* ms = (MyStructure *) calloc(4, sizeof(MyStructure));
    //cout<< sizeof(MyStructure)<< endl;
    
    cout << ms[0].i << endl;
    
    
    int* p = (int *)malloc(2*sizeof(int)); ; //individual blocks of data can  be accessed using array
    
    p = (int *) realloc(p, 10*sizeof(int));
    
    printf("address = %p, value = %d\n", p + 0, *(p + 0));
    printf("address = %p, value = %d\n", p + 1, *(p + 1));
    printf("address = %p, value = %d\n", p + 2, *(p + 2));
    
    for(int i = 0; i < 3; i++){
        cout<< &p[i] << endl;
    }
    
    free(p);*/
    

    
    return 0;
}
