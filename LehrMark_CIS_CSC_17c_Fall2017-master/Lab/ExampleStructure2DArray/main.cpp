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

//Function Prototypes
Array2D* filAray(int,int);
void prntAry(Array2D *);
void destroy(Array2D *);

//Execution Begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variable
    int nRows=5;
    int nCols=10;
    Array2D *example;
    
    //Initialize the values
    example=filAray(nRows,nCols);
    
    //Print the values
    prntAry(example);
    
    //Deallocate Memory
    destroy(example);

    //Exit the program
    return 0;
}

void destroy(Array2D *array){
    for(int row=0;row<array->rows;row++){
        delete []array->data[row];
    }
    delete []array->data;
    delete array;
}

void prntAry(Array2D *array){
    cout<<endl;
    for(int row=0;row<array->rows;row++){
        for(int col=0;col<array->cols;col++){
            cout<<array->data[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

Array2D* filAray(int rows,int cols){
    //Allocating memory for the structure
    Array2D *array=new Array2D;
    //Allocating memory for the information
    //contained in the structure
    array->rows=rows;
    array->cols=cols;
    array->data=new int*[array->rows];
    for(int row=0;row<array->rows;row++){
        array->data[row]=new int[array->cols];
    }
    //Fill the Structure data with random numbers
    for(int row=0;row<array->rows;row++){
        for(int col=0;col<array->cols;col++){
            array->data[row][col]=rand()%90+10;
        }
    }
    return array;
}