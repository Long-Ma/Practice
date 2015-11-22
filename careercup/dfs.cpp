//
//  dfs.cpp
//  practice
//
//  Created by Long Ma on 2015-11-17.
//  Copyright © 2015 Long Ma. All rights reserved.
//

#include "dfs.hpp"
#include <stack>
#include <vector>

// Given a matrix of 0 and 1. start at (0,0) and traverse to (m, n). Print out all
// possible ways.

#define M 10
#define N 10

using namespace std;

int matrix[M][N];

struct pos {
    int row;
    int col;
};

void backtrack(vector<struct pos> &path, struct pos &lastFork)
{
    vector<struct pos>::iterator it;
    for (it = path.begin(); it != path.end(); it++) {
        if (it->row == lastFork.row && it->col == lastFork.col)
            break;
    }
    
    path.erase(it+1, path.end());
}

void dfs()
{
    stack<struct pos> s;
    vector<vector<struct pos>> paths;
    vector<struct pos> path;
    
    struct pos position = {0,0};
    s.push(position);
    while (!s.empty()) {
        struct pos currentPos = s.top();
        s.pop();
        
        int row = currentPos.row;
        int col = currentPos.col;
        path.push_back(currentPos);
        
        // if we have reached the destination
        if (row == M-1 && col == N-1) {
            paths.push_back(path);
            path.clear();
            
            // We want to backtrack to a previous fork
            if (!s.empty())
                backtrack(path, s.top());
            
            continue;
        }
        
        // Dead end
        if ((row == M - 1 && col < N - 1) || (row < M - 1 && col == N - 1)) {
            path.clear();
            
            // We want to backtrack to a previous fork
            if (!s.empty())
                backtrack(path, s.top());
            
            continue;
        }
        
        // Move right, down and diagonal right. If no path, move on.
        if (col < N - 1 && matrix[row][col+1] == 1) {
            currentPos.col++;
            s.push(currentPos);
        } else if (row < M -1 && matrix[row+1][col] == 1) {
            currentPos.row++;
            s.push(currentPos);
        } else if (row < M - 1 && col < N - 1 && matrix[row+1][col+1] == 1) {
            currentPos.row++;
            currentPos.col++;
            s.push(currentPos);
        }
        
    }
}















