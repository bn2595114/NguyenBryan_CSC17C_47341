/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 6, 2017, 8:21 PM
 * Purpose:  Example use of a 2 D array Structure
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Array2D.h"

//Global Constants

//Function Prototype
void filAray(Array2D<float> &);
void prntAry(Array2D<float> &);

//Execution Begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variable
    int nRows=5;
    int nCols=10;
    Array2D<float> example(nRows,nCols);
    
    //Initialize the values
    filAray(example);
    
    //Print the values
    prntAry(example);

    //Exit the program
    return 0;
}

void prntAry(Array2D<float> &array){
    cout<<endl;
    for(int row=0;row<array.getRows();row++){
        for(int col=0;col<array.getCols();col++){
            cout<<array.getData(row,col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void filAray(Array2D<float> &array){
    //Fill the Structure data with random numbers
    for(int row=0;row<array.getRows();row++){
        for(int col=0;col<array.getCols();col++){
            array.setData(row,col,rand()%90+10.1f);
        }
    }
}