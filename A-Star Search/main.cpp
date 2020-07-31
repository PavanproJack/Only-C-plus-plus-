

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
#include <algorithm>

using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;
using std::abs;
using std::sort;

enum class state{
    Empty,
    Obstacle,
    Closed,
    Path
};


bool CheckValidCell(int x, int y, vector<vector<state>> grid){
    if(grid[x][y] == state::Empty)
        return true;
    else
        return false;
}

bool Compare(vector<int> openNode1, vector<int> openNode2){
    int f_node1 = openNode1[2] + openNode1[3];
    int f_node2 = openNode2[2] + openNode2[3];
    if(f_node1 > f_node2)
        return true;
    else
        return false;
}

void CellSort(vector<vector<int>> *v){
    sort(v->begin(), v->end(), Compare);
}

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &open, vector<vector<state>> &grid){
    
    open.push_back(vector<int>{x, y, g, h});
    //grid[x][y] = state::Closed;
    
}

int Heuristic(int x1, int y1, int x2, int y2){
    return (abs(x2 - x1) + abs(y2 - y1));
}

void ExpandNeighbors(vector<int> &current, vector<vector<int>> &open, vector<vector<state>> &grid, int goal[2]){
    //const int delta[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    const vector<vector<int>> delta1 = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int x = current[0];
    int y = current[1];
    int g = current[2];
    //int h = Heuristic(x, y, goal[0], goal[1]);
    
    for(auto i : delta1){
        int x2 = x + i[0];
        int y2 = y + i[1];
        if(CheckValidCell(x, y, grid)){
            int g2 = g + 1;
            int h2 = Heuristic(x, y, goal[0], goal[1]);
            AddToOpen(x2, y2, g2, h2, open, grid);
        }
    }
    
}

vector<vector<state>> Search(vector<vector<state>> grid, int start[2], int goal[2]){
    
    vector<vector<int>> open{};
    int x = start[0];
    int y = start[1];
    int g = 0;
    int h = Heuristic(x, y, goal[0], goal[1]);
    
    AddToOpen(x, y, g, h, open, grid);
    
    while(open.size()>0){
        CellSort(&open);
        auto current = open.back();
        open.pop_back();
        x = current[0];
        y = current[1];
        //grid[x][y] = state::Path;
        if((x == goal[0]) && (y == goal[1])){
            cout<< "Goal Reached";
            return grid;
        }
        else{
            ExpandNeighbors(current, open, grid, goal);
        }
    }
    return vector<vector<state>>{};
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
    cout<<board.size();
    for(auto i :  board){
        for(auto v : i){
            cout<< CellString(v);
        }
        cout<<"\n";
    }
}

int MultiplyByTwo(int &i){
    
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


