/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on November 4, 2017, 6:08 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

float power(int, int);

int main(int argc, char*argv[]) {

    int x = -2;
    int n = 2;
    cout << power(x, n);
    

    
    return 0;
}

int power(int x, int n)
{
    int pr;
    if(n == 0)
       return 1;
    pr = power(x, n/2);       
    if (n%2 == 0)
        return pr*pr;
    else
        return x*pr*pr;
}  