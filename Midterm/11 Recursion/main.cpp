/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on November 5, 2017, 12:05 AM
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

float recur(float x);

int main(int argc, char** argv) {
    
    cout << recur(1);
    
    return 0;
}

float recur(float x){
    float tol=.000001; // 10^(-6)
    if(x>=-1 && x<=1)
    if(abs(x)<tol) return (2*x-((2*x*2*x*2*x)/6.f));
    x/=2.f;
    return ((2.f*recur(x))/(1+(recur(x)*recur(x))));
}
