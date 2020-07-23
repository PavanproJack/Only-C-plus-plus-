//
//  main.cpp
//  Intro2C++
//
//  Created by PavanKumar on 23/07/2020.
//  Copyright © 2020 PavanKumar. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void PrintBoard(vector<vector<int>> board){
    
    for(int i = 0; i < board.size(); i++){
        for(int k = 0; k < board[i].size(); k++){
            cout << board[i][k] ;
        }
         cout<<"\n";
    }
}

int main()
{
    vector<vector<int>> board;
    
    board = {
                {0, 1, 0, 0, 0, 0},
                {0, 1, 0, 0, 0, 0},
                {0, 1, 0, 0, 0, 0},
                {0, 1, 0, 0, 0, 0},
                {0, 0, 0, 0, 1, 0}
        
            };
    PrintBoard(board);
    return 0;
}

