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

    cout << "Doubling the array size(starting at 2):" << endl;
    SimpleVector<int>x(2);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    cout << "SIZE: " <<  x.size() << endl;
    
    for(int i=0; i<x.size(); i++)
        if(x.getElementAt(i)!=0)
        cout << x.getElementAt(i);
    
    cout << endl;
    cout << "Halving the array size(starting at 8): " << endl;
    
    SimpleVector<int>y(8);
    y.pop_off();
    cout << "SIZE: " << y.size();
    
    return 0;
}

