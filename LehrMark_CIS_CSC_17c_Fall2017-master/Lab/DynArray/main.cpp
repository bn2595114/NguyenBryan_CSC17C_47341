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

//Global Constants

//Function Prototypes
int *fillAry(int);
void prntAry(int [],int,int);
void mrkSort(int [],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int size=200;
    int *array;
    
    //Initialize the array
    array=fillAry(size);
    
    //Print the results
    prntAry(array,size,20);
    
    //Sort the array
    mrkSort(array,size);
    
    //Print the results
    prntAry(array,size,20);

    //Exit the program
    delete []array;
    return 0;
}

void mrkSort(int a[],int n){
    for(int pos=0;pos<n-1;pos++){
        for(int i=pos+1;i<n;i++){
            if(a[pos]>a[i]){
                a[pos]=a[pos]^a[i];
                a[i]=a[pos]^a[i];
                a[pos]=a[pos]^a[i];
            }
        }
    }
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n){
    //Declare variables
    int *array=new int[n];
    //Set the values
    for(int i=0;i<n;i++){
        array[i]=rand()%90+10;
    }
    return array;
}