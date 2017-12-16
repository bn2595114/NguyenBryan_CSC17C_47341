/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on October 23, 2017, 11:29 PM
 */


#include <cstdlib>
#include <ctime>
#include "levels.h"
#include "login.h"
#include "mergeSort.h"
#include "Tree.h"
#include "Graph.h"
using namespace std;

void itpre(Node*);
int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));
    
    cout << "Sorting numbers..." << endl;
    MergeSort a;
    a.fill(10);
    a.print(5);
    a.mergeSort(0,10);
    a.print(5);

    cout << "Converting levels into nodes..." << endl;
    Node *root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(5);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(6);
    itpre(root);
    cout << endl;
    
    cout << "Calculating Lucky Rounds" << endl;
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(2);
    cout << endl << endl;
    
    Lv game;
    game.read();
    game.l1();
    game.l2();
    game.l3();
    game.l4();
    game.l5();
    game.l6();
    game.l7();
    game.l8();
    game.prntHP();
    game.outWin();
    game.rank();
    return 0;
}

void itpre(Node* root){
        if (root == NULL)
       return;
 
    stack<Node *> nodeStack;
    nodeStack.push(root);
 
    while (nodeStack.empty() == false)
    {
        struct Node *node = nodeStack.top();
        printf ("%d ", node->data);
        nodeStack.pop();
 
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}