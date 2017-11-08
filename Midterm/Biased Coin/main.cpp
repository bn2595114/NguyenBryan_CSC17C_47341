/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 7, 2017, 11:53 AM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

bool fill(int*, int);
void count(int&);
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    int SIZE= 10;
    int a[SIZE];
    int c=0;
    for(int i=0; i<1000000; i++){
        count(c);
    }
    cout << "# of times that 5 random bits all fall within filled section: ";
    cout << c/5 << endl;
    cout <<endl<<(c/1000000.f);
    return 0;
}

bool fill(int* a, int size){
    for (int i=0; i<size; i++)
        a[i] = false;
    int z,b,c;
    z = rand()%10;
    b = rand()%10;
    while(b==z)
        b = rand()%10;
    c = rand()%10;
    while(c==b || c==z)
        c = rand()%10;
    a[z] = true;
    a[b] = true;
    a[c] = true;
    return a;
}

void count(int&c){
    int SIZE = 10;
    int a[SIZE];
    int f=0;
    fill(a,SIZE);
    for(int i=0; i<5; i++){
        if(a[rand()%10]==true)
            f++;
    };
    if(f==5) c++;
}