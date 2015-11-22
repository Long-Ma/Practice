//
//  nextpointer.cpp
//  practice
//
//  Created by Long Ma on 2015-11-21.
//  Copyright © 2015 Long Ma. All rights reserved.
//

#include "nextpointer.hpp"
#include <queue>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode* A)
{
    int num = 2;
    queue<TreeLinkNode*> q;
    
    if (A == NULL || (A->left == NULL && A->right == NULL))
        return;
    
    q.push(A->left);
    q.push(A->right);
    A->next = NULL;
    
    while (!q.empty()) {
        TreeLinkNode *node = NULL;
        TreeLinkNode *prevNode = NULL;
        for (int i = 0; i < num; i++) {
            node = q.back();
            q.pop();
            
            if (prevNode != NULL)
                prevNode->next = node;
            
            prevNode = node;
            
            if (A->left != NULL || A->right != NULL) {
                q.push(A->left);
                q.push(A->right);
            }
        }
        
        node->next = NULL;
        num = num << 1;
    }
}
