//
//  main.cpp
//  Restart-C++
//
//  Created by PavanKumar on 28/03/2021.
//  Copyright © 2021 PavanKumar. All rights reserved.
//

#include <iostream>
#include <vector>



using std::vector;
using std::string;

int inch {56};
int length = 34;
//complex<double> z{1, 3};
auto centi = 67;
vector<int> v1{1, 2, 3, 4, 5};

struct Record{
    string hello{"motto"};
};

char v[6];
char* p;

const vector<int> vec{1, 2, 3, 4, 5, 6};

void sortit(int *l){
    ++l;
}

int d{35}, f{45};

void swap(int *x, int *y) {
   int temp;
   temp = *x; /* save the value at address x */
   *x = *y; /* put y into x */
   *y = temp; /* put x into y */
  
   return;
}





void swap(int& x, int& y) {
   int temp;
   //std::cout << x <<"\n";
   temp = x; /* save the value at address x */
   x = y; /* put y into x */
   y = temp; /* put x into y */
   return;
}


int main(int argc, const char * argv[]){
    // insert code here...
    std::cout << "Hello, World!\n";
    //auto p = new Record{"fjfhjfjdhfj"};
    int q = 34;
    char* p = &v[3];
//    std::cout<< p << std::endl;
    sortit(&q);
//    std::cout<< q << std::endl;
//    for(auto& x:vec)
//        std::cout<< x << std::endl;
    
//    std::cout<< &d << std::endl;
//    std::cout<< &f << std::endl;
//    swap(d, f);
//    std::cout<< d << std::endl;
//    std::cout<< f << std::endl;
    
    int& gh = q;
    std::cout<< q << std::endl;
    std::cout<< gh << std::endl;
    
    gh = 97;
    std::cout<< q << std::endl;
    std::cout<< gh << std::endl;
    
    return 0;
}
