//
//  subset.cpp
//  practice
//
//  Created by Long Ma on 2015-11-21.
//  Copyright © 2015 Long Ma. All rights reserved.
//

#include "subset.hpp"
#include <vector>

using namespace std;

void generateSubsets(vector<int> &S, int index, vector<int> &current, vector<vector<int> > &result) {
    if (index >= S.size()) {
        result.push_back(current);
        return;
    }
    // Ignore the current index.
    generateSubsets(S, index + 1, current, result);
    
    // Include the current index.
    current.push_back(S[index]);
    generateSubsets(S, index + 1, current, result);
    current.pop_back();
}

vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > result;
    vector<int> current;
    sort(S.begin(), S.end());
    generateSubsets(S, 0, current, result);
    sort(result.begin(), result.end());
    return result;
}

void printResult(vector<vector<int>> &result)
{
    for (auto it1 = result.begin(); it1 != result.end(); it1++) {
        for (auto it2 = it1->begin(); it2 != it1->end(); it2++) {
            printf("%d ", *it2);
        }
        printf("\n");
    }
}

void subset_main()
{
    vector<int> input;
    for (int i = 1; i != 4; i++) {
        input.push_back(i);
    }
    
    vector<vector<int>> result = subsets(input);
    printResult(result);
}














