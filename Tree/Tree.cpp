/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "Tree.h"
using namespace std;

Tree::~Tree(){
    delete beg->left->left;
    delete beg->left->right;
    delete beg->right->right;
    delete beg->right->left;
    delete beg->left;
    delete beg->right;
    delete beg;
}


void Tree::insert(const int& d){
    Node* add = new Node;
    add->data = d;
    add->left = NULL;
    add->right = NULL;
    
    temp = beg;
    end = temp;
    if(temp->data > d){
        while(temp->left!=NULL){
            if((temp->left)->data <= d){
                add->left = temp->left;
                temp->left = add;
                break;
            }
            else{
                temp = temp->left;
                end = temp;
                if(end==NULL)
                end->left = add;
            }
        }  
    }
    
    temp = beg;
    end = temp;
    if(temp->data < d){
        while(temp->right!=NULL){
            if((temp->right)->data >= d){
                add->right = temp->right;
                temp->right = add;
            }
            else{
                temp = temp->right;
                end = temp;
                if(end==NULL)
                end->right = add;
            }
        }  
    }     
}

void Tree::balance(){
    int count=0;
    temp = beg;
    while(temp->right!=NULL){
        count++;
        if(count==3){
            ((beg->right)->right)->left = beg->right;
            beg->right = (beg->right)->right;
        }
        temp = temp->right;
    }
    
    while(temp->left!=NULL){
        count++;
        if(count==3){
            ((beg->left)->left)->right = beg->left;
            beg->left = (beg->left)->left;
        }
        temp = temp->right;
    }
}

void Tree::inOrder(){
    
    cout << beg->data;

    cout << 234567;
}