//
//  quick_sort_slist.cpp
//  practice
//
//  Created by Weijia Li on 2015-11-15.
//  Copyright © 2015 Weijia Li. All rights reserved.
//

#include "quick_sort_slist.hpp"
#include <vector>
#include <iostream>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printVector(vector<ListNode*> &tmp)
{
    for (auto it = tmp.begin(); it < tmp.end(); it++) {
        printf("%d ", (*it)->val);
    }
    printf("\n");
}

int partition(vector<ListNode*> &tmp, int left, int right)
{
    int pIndex = left;
    int pivot = tmp[right]->val;
    
    for (int i = left; i < right; i++) {
        if (tmp[i]->val <= pivot) {
            if (pIndex != i)
                swap(tmp[i], tmp[pIndex]);
            
            pIndex++;
        }
    }
    
    swap(tmp[right], tmp[pIndex]);
    return pIndex;
}

void quickSortHelper(vector<ListNode*> &tmp, int left, int right)
{
    if (left >= right)
        return;
    
    int pivot = partition(tmp, left, right);
    quickSortHelper(tmp, left, pivot-1);
    quickSortHelper(tmp, pivot+1, right);
}

ListNode* quickSort(ListNode *A)
{
    vector<ListNode*> tmp;
    ListNode* node = A;
    
    while (node != NULL) {
        tmp.push_back(node);
        node = node->next;
    }
    
    quickSortHelper(tmp, 0, (int)tmp.size()-1);
    printVector(tmp);
    
    // Rebuild list here
    ListNode* prevNode = *tmp.begin();
    A = prevNode;
    auto it = tmp.begin() + 1;
    for (; it != tmp.end()-1; it++) {
        prevNode->next = *it;
        prevNode = prevNode->next;
    }
    
    prevNode->next = *it;
    return A;
}

void _main()
{
    ListNode *prevNode = new ListNode(0);
    ListNode *head = prevNode;
    for (int i = 0; i < 20; i++) {
        int n = abs(rand());
        ListNode *node = new ListNode(n);
        prevNode->next = node;
        prevNode = node;
    }
    
    quickSort(head);
}
