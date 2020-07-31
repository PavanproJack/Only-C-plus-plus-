//
//  main.cpp
//  A-Star Search
//
//  Created by PavanKumar on 29/07/2020.
//  Copyright © 2020 PavanKumar. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>

#include <vector>
#include <string>
#include "pass_by_ref.cpp"

using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;
using std::abs;

enum class state{
    Empty,
    Obstacle
};

vector<vector<state>> Search(vector<vector<state>> board, int start[2], int goal[2]){
    
    vector<vector<state>> path{};
    cout<<"No Path found"<<endl;
    return path;
}

vector<state> parseNewLine(string line){
    istringstream newLine(line);
    vector<state> row;
    int n;
    char c;
    while(newLine >> n  >>  c){
        row.push_back(n==0? state::Empty : state::Obstacle);
    }
    return row;
}

vector<vector<state>> ReadBoardFile(string path){
    
    vector<vector<state>> board;
    ifstream ifs;
    ifs.open(path, ifstream::in);
    if (ifs.is_open()){
        string line;
        while(getline(ifs, line)){
            vector<state> row = parseNewLine(line);
            board.push_back(row);
        }
    }
    return board;
}

string CellString(state cell){
    return (cell == state::Obstacle ? "⛰️  " : "0  ");
}

void PrintBoard(vector<vector<state>> board){
    for(auto i :  board){
        for(auto v : i){
            cout<< CellString(v);
        }
        cout<<"\n";
    }
}

int Heuristic(int x1, int y1, int x2, int y2){
    return (abs(x2 - x1) + abs(y2 - y1));
}

int MultiplyByTwo(int &i)
{
    
//In the code above, a is passed by reference to the function MultiplyByTwo since the argument to MultiplyByTwo is a reference: &i. This means that i becomes another name for whatever variable that is passed into the function. When the function changes the value of i, then the value of a is changed as well.
    i = 2 * i;
    return i;
}


int main(int argc, const char * argv[]) {
    string boardPath = "map.board";
    vector<vector<state>> board = ReadBoardFile(boardPath);
    int start[2] = {0, 0};
    int goal[2] = {4, 5};
    
    vector<vector<state>> solution = Search(board, start, goal);
    PrintBoard(solution);
    //TestHeuristic();
    /*int a = 5;
    std::cout << "The int a = " << a << "\n";
    int b = MultiplyByTwo(a);
    std::cout << "The int b = " << b << "\n";
    std::cout << "The int a now = " << a << "\n";*/
    
    return 0;
}
