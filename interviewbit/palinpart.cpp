//
//  palinpart.cpp
//  practice
//
//  Created by Long Ma on 2015-11-21.
//  Copyright © 2015 Long Ma. All rights reserved.
//

#include "palinpart.hpp"
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(string &A)
{
    int retval = true;
    int min = 0;
    int max = (int)A.size()-1;
    
    if (A.size() == 0)
        return false;
    
    while (min < max) {
        if (A[min] != A[max]) {
            retval = false;
            break;
        }
        
        min++;
        max--;
    }
    
    return retval;
}

void partitionHelper(vector<vector<string>> &partitions, vector<string> &part, string &A, int index)
{
    if (index == A.size()) {
        partitions.push_back(part);
        return;
    }
    
    for (int i = index; i < A.size(); i++) {
        string substring = A.substr(index, i-index+1);
        if (isPalindrome(substring) == true) {
            part.push_back(substring);
            partitionHelper(partitions, part, A, i+1);
            part.pop_back();
        }
    }
}

vector<vector<string> > partition(string &A)
{
    vector<vector<string>> result;
    vector<string> part;
    partitionHelper(result, part, A, 0);
    return result;
}

void printResult(vector<vector<string>> &result)
{
    for (auto it1 = result.begin(); it1 != result.end(); it1++) {
        for (auto it2 = it1->begin(); it2 != it1->end(); it2++) {
            printf("%s ", it2->c_str());
        }
        printf("\n");
    }
}

void palinpart_main()
{
    string A = "aabaa";
    vector<vector<string>> result = partition(A);
    printResult(result);
}



