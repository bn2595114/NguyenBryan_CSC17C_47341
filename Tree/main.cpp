/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on December 6, 2017, 8:08 PM
 */

#include <cstdlib>
#include <iostream>
#include "Tree.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Tree* tree;
    tree = new Tree(1);
    tree->insert(2);
    tree->insert(3);
    tree->insert(4);
    tree->insert(5);
    tree->insert(6);
    tree->insert(7);
    tree->inOrder();
  
    return 0;
}

