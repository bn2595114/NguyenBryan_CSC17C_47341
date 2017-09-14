/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 30, 2017, 8:20 PM
 * Purpose:  Dynamic Array
 */

//System Libraries
#include <iostream>  //I/O streams
#include <cstdlib>   //Random Function
#include <ctime>     //Set the random number seed
using namespace std;

//User Libraries
#include "array.h"

//Global Constants

//Function Prototypes
Array *fillAry(int);
void prntAry(Array *,int);
void mrkSort(Array *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int size=200;
    Array *array;
    
    //Initialize the array
    array=fillAry(size);
    
    //Print the results
    prntAry(array,20);
    
    //Sort the array
    mrkSort(array);
    
    //Print the results
    prntAry(array,20);
    
    //Exit program and clean up
    delete []array->data;
    delete array;

    return 0;
}

void mrkSort(Array *a){
    for(int pos=0;pos<a->size-1;pos++){
        for(int i=pos+1;i<a->size;i++){
            if(a->data[pos]>a->data[i]){
                a->data[pos]=a->data[pos]^a->data[i];
                a->data[i]=a->data[pos]^a->data[i];
                a->data[pos]=a->data[pos]^a->data[i];
            }
        }
    }
}

void prntAry(Array *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->size;i++){
        cout<<a->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n){
    //Declare variables
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    //Set the values
    for(int i=0;i<n;i++){
        array->data[i]=rand()%90+10;
    }
    return array;
}