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
#include <exception>

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

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &open, vector<vector<state>> &grid){
    cout<<x<<"\n"<<y;
    open.push_back(vector<int>{x, y, g, h});
    grid[x][y] = state::Closed;
    
}

int Heuristic(int x1, int y1, int x2, int y2){
    return (abs(x2 - x1) + abs(y2 - y1));
}

bool CheckValidCell(int x, int y, vector<vector<state>> grid){
    if(grid[x][y] == state::Empty)
        return true;
    else
        return false;
}

void ExpandNeighbors(vector<int> &current, vector<vector<int>> &open, vector<vector<state>> &grid, int goal[2]){
    //const int delta[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    const vector<vector<int>> delta1 = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int x = current[0];
    int y = current[1];
    int g = current[2];
    int h = Heuristic(x, y, goal[0], goal[1]);
    
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

vector<vector<state>> Search(vector<vector<state>> &grid, int start[2], int goal[2]){
    
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
        try{
          grid[x][y] = state::Path;
        }
        catch (std::exception& e){
          cout << e.what() << '\n';
        }
        
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

int main(int argc, const char * argv[]) {
    string boardPath = "map.board";
    vector<vector<state>> board = ReadBoardFile(boardPath);
    int start[2] = {1, 0};
    int goal[2] = {3, 2};
    
    vector<vector<state>> solution = Search(board, start, goal);
    PrintBoard(solution);
    cout<< "\n";
    
    return 0;
}

