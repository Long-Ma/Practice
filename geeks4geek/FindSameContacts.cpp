//
//  FindSameContacts.cpp
//  practice
//
//  Created by Long Ma on 2015-11-21.
//  Copyright © 2015 Long Ma. All rights reserved.
//

#include "FindSameContacts.hpp"
#include <string>
#include <vector>
#include <stack>

using namespace std;

// Structure for storing contact details.
struct contact {
    string field1, field2, field3;
};

class node {
private:
    int             contactID;
    contact         contact;
    int             visited;
    vector<node*>    edges;
    
public:
    node (int _contactID, struct contact _contact)
    {
        contactID = _contactID;
        contact = _contact;
    }
    
    const int getID()
    {
        return contactID;
    }
    
    const struct contact getContact()
    {
        return contact;
    }
    
    node* getNode(int index)
    {
        return edges[index];
    }
    
    const unsigned long getNumberEdges()
    {
        return edges.size();
    }
    
    bool getVisited()
    {
        return visited;
    }
    
    void addEdge(node* _node)
    {
        edges.push_back(_node);
    }
    
    void visite()
    {
        visited = 1;
    }
};

void printGraph(vector<node*> &graph)
{
    for (auto it = graph.begin(); it != graph.end(); it++) {
        printf("Contact #%d\n", (*it)->getID());
        printf("Edges:\n");
        for (int i = 0; i != (*it)->getNumberEdges(); i++) {
            node *node = (*it)->getNode(i);
            printf("%d ", node->getID());
        }
        printf("\n");
    }
}

bool isSameContact(node *n1, node *n2)
{
    bool retval = false;
    
    contact c1 = n1->getContact();
    contact c2 = n2->getContact();
    
    if (c1.field1 == c2.field1 ||
        c1.field2 == c2.field1 ||
        c1.field3 == c2.field1 ||
        c1.field1 == c2.field2 ||
        c1.field2 == c2.field2 ||
        c1.field3 == c2.field2 ||
        c1.field1 == c2.field3 ||
        c1.field2 == c2.field3 ||
        c1.field3 == c2.field3) {
        retval = true;
    }
    
    return retval;
}

vector<node*> buildNodes(contact *arr, int n)
{
    vector<node*> result;
    
    for (int i = 0; i < n; i++) {
        node* _node = new node(i, arr[i]);
        result.push_back(_node);
    }
    
    return result;
}

vector<node*> buildGraph(contact *arr, int n)
{
    vector<node*> graph = buildNodes(arr, n);
    
    for (int i = 0; i != graph.size(); i++) {
        for (int j = 0; j != graph.size(); j++) {
            
            // Same contact, continue
            if (j == i)
                continue;
            
            if (isSameContact(graph[i], graph[j]) == true) {
                graph[i]->addEdge(graph[j]);
            }
        }
    }
    
    return graph;
}

void destroyGraph(vector<node*> graph)
{
    for (int i = 0; i < graph.size(); i++) {
        delete graph[i];
    }
}

// Use DFS to print out all similar contacts using the graph
void printSameContacts(node *current, vector<node*> &graph)
{
    stack<node*> s;
    s.push(current);
    
    printf("Current contact #%d\n", current->getID());
    
    node *_node;
    bool first = true;
    while (!s.empty()) {
        _node = s.top();
        s.pop();
        
        if (_node->getVisited() == true)
            continue;
        
        if (first) {
            first = false;
        } else {
            printf("-> Linked with #%d\n", _node->getID());
        }
        
        for (int i = 0; i < _node->getNumberEdges(); i++) {
            s.push(_node->getNode(i));
        }
        
        _node->visite();
    }
}

void findSameContacts(contact *arr, int n)
{
    vector<node*> graph = buildGraph(arr, n);
    
    // Use DFS to find all similar contacts
    for (int i = 0; i != graph.size(); i++) {
        if (graph[i]->getVisited() == true)
            continue;
        
        printSameContacts(graph[i], graph);
        printf("\n");
    }
    
    destroyGraph(graph);
}

void FSC_main()
{
    contact arr[] = {{"Gaurav", "gaurav@gmail.com", "gaurav@gfgQA.com"},
        {"Lucky", "lucky@gmail.com", "+1234567"},
        {"gaurav123", "+5412312", "gaurav123@skype.com"},
        {"gaurav1993", "+5412312", "gaurav@gfgQA.com"},
        {"raja", "+2231210", "raja@gfg.com"},
        {"bahubali", "+878312", "raja"}
    };
    
    int n = sizeof arr / sizeof arr[0];
    findSameContacts(arr, n);
}