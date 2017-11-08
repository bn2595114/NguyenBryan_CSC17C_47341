/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 7, 2017, 11:29 AM
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <ctime>
using namespace std;

float c(float x);
float s(float x);

int main(int argc, char** argv) {
    float x=M_PI/4;
    cout << c(x);
    return 0;
}

float c(float x){
    double tol = .000001;
    if(abs(x)<tol) return (1/(2*x) + (2*x)/6);
    x/=2;
    return (0.5 * c(x)*s(x));
}

float s(float x){
    double tol = .000001;
    if(abs(x)<tol) return (1 + (2*x)*(2*x)/2);
    x/=2;
    float a = s(x);
    float b = c(x);
    return ((b*b*a*a)/(b*b-a*a));
}