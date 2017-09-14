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

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int size=200;
    
    //Initialize the array
    Array array(size);
    
    //Print the results
    array.prntAry(20);
    
    //Sort the array
    array.mrkSort();
    
    //Print the results
    array.prntAry(20);
    
    //Exit program and clean up
    return 0;
}