//
//  JumpingNumber.cpp
//  practice
//
//  Created by Long Ma on 2015-11-22.
//  Copyright © 2015 Long Ma. All rights reserved.
//

#include "JumpingNumber.hpp"
#include <vector>
#include <queue>

using namespace std;

vector<int> getAdjacent(int x)
{
    vector<int> result;
    
    if (x < 9) {
        result.push_back(x+1);
    }
    
    if (x == 0)
        return result;
    
    int lastDigit = x % 10;
    
    if (lastDigit != 9)
        result.push_back(x*10 + lastDigit + 1);
    
    if (lastDigit != 0)
        result.push_back(x*10 + lastDigit - 1);
    
    return result;
}

// Use BFS to find all jumping nodes
vector<int> getJumping(int x)
{
    vector<int> result;
    queue<int> q;
    
    q.push(0);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        result.push_back(current);
        vector<int> adjacent = getAdjacent(current);
        for (int i = 0; i != adjacent.size(); i++) {
            if (adjacent[i] <= x) {
                q.push(adjacent[i]);
            }
        }
    }
    
    return result;
}

void jm_main()
{
    int x = 2000;
    vector<int> result = getJumping(x);
    sort(result.begin(), result.end()); // Not required, but easier to visualize
    for (int i = 0; i != result.size(); i++) {
        printf("%d ", result[i]);
    }
}