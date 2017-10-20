/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on October 5, 2017, 5:40 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "SimpleVector.h"
/*
 * 
 */
int main(int argc, char** argv) {

    SimpleVector<int>x(2);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    cout << "ADDING LINKS: " << endl;
    x.getElementAt();
    
    cout << endl << "REMOVING LINKS: " << endl;
    x.pop_off();
    x.getElementAt();
    
    return 0;
}

