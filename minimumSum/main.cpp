//
//  main.cpp
//  minimumSum
//
//  Created by PavanKumar on 08/08/2020.
//  Copyright © 2020 PavanKumar. All rights reserved.
//


#include <cassert>
#include <iostream>
#include <vector>
#include <sstream>

using std::endl;
using std::cout;
using std::cin;
using std::vector;


int operate(vector<int> nVector, int K){
    int sum = 0;

    for(int j = 1; j <= K; j++){
        int r = rand() % nVector.size();
        //cout << r << endl;
        nVector[r] = nVector[r] / 2;
    }
    for(auto n : nVector){
        sum = sum + n;
    }

    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    vector<int> inputVector;
    std::string input;
    cout << "Enter N and K values separated by Space" << endl;
    getline(cin, input);
    std::istringstream iss(input);
    int temp;
    while(iss >> temp){
       inputVector.push_back(temp);
    }
    
    for(int i : inputVector){
        cout<< i << endl;
    }
    
    vector<int> nVector;
    std::string nInput;
    cout << "Please enter " << inputVector[0] << "values separated by space" <<endl;
    getline(cin, nInput);
    std::istringstream iss_(nInput);
    int temp_;
    while(iss_ >> temp_){
       nVector.push_back(temp_);
    }
    for(int i : nVector){
        cout<< i << endl;
    }
    
    int j = operate(nVector, inputVector[1]);
    cout << j << endl;
    
    
    
    return 0;
}
