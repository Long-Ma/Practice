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

/*
 * Given a number x, find it's connected vertices by
 * keeping x constant. i.e.
 * if x = 12, then its connected vertices are 121 and 123
 */
void pushAdjacent(queue<int> &q, int x, int max)
{
    if (x < 9)
        q.push(x+1);
    
    if (x == 0)
        return;
    
    int lastDigit = x % 10;
    
    if (lastDigit != 9) {
        int tmp = 10*x + lastDigit + 1;
        if (tmp < max)
            q.push(tmp);
    }
    
    if (lastDigit != 0) {
        int tmp = 10*x + lastDigit - 1;
        if (tmp < max)
            q.push(tmp);
    }
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
        pushAdjacent(q, current, x);
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