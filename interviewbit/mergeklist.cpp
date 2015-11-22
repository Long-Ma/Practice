//
//  mergeklist.cpp
//  practice
//
//  Created by Long Ma on 2015-11-19.
//  Copyright © 2015 Long Ma. All rights reserved.
//

#include "mergeklist.hpp"
#include <map>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeklist_approach1(vector<ListNode*> &A)
{
    ListNode *result;
    multimap<int, ListNode*> sortedNodes;
    
    for (auto it = A.begin(); it != A.end(); it++) {
        ListNode* node = *it;
        
        while (node != NULL) {
            sortedNodes.insert(make_pair(node->val, node));
            node = node->next;
        }
    }
    
    map<int, ListNode*>::iterator it = sortedNodes.begin();
    result = it->second;
    it++;
    
    ListNode *tmp = result;
    for (; it != sortedNodes.end(); it++) {
        ListNode *node = it->second;
        tmp->next = node;
        tmp = node;
    }
    
    it--;
    it->second->next = NULL;
    return result;
}

struct CompareNode {
    bool operator()(ListNode* const & p1, ListNode* const & p2) {
        return p1->val > p2->val;
    }
};

ListNode* mergeklist_approach2(vector<ListNode*> &A)
{
    priority_queue<ListNode*, vector<ListNode*>, CompareNode> q;
    
    for (auto it = A.begin(); it != A.end(); it++) {
        ListNode* node = *it;
        
        while (node != NULL) {
            q.push(node);
        }
    }
    
    ListNode *head = q.top();
    ListNode *tmp = head;
    q.pop();
    while (!q.empty()) {
        ListNode *node = q.top();
        q.pop();
        
        tmp->next = node;
        tmp = node;
    }
    
    tmp->next = NULL;
    return head;
}









































