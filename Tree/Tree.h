/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.h
 * Author: rcc
 *
 * Created on December 6, 2017, 8:12 PM
 */
#include <cstdlib>
#ifndef TREE_H
#define TREE_H

class  Tree{
    private: 
        struct Node{
            int data;
            Node *left, *right;
        };
        Node *temp, *beg, *newNode, *end;
    public:
        Tree(const int& d){
            beg = new Node;
            beg->data = d;
            beg->left = NULL; 
            beg->right = NULL; 
        }
        ~Tree();
        void insert(const int&);
        void balance();
        void remove(const int&);
        void inOrder();
};
#endif /* TREE_H */
