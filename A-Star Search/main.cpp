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


using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;


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
    vector<state> row;
    for(auto i : line){
        //row.push_back(i==0? state::Empty : state::Obstacle);
        cout<< i;
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
            //board.push_back(row);
        }
    }
    return board;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    string boardPath = "map.board";
    ReadBoardFile(boardPath);
    return 0;
}































