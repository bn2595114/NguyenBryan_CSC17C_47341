/* 
 * File:   Array2D.h
 * Author: Dr. Mark E. Lehr
 * Created on September 6, 2017, 8:21 PM
 * Purpose:  2D Array class implementation
 */

#include "Array2D.h"
#include <cstdlib>
using namespace std;

Array2D::Array2D(int rows,int cols){
    //Allocating memory for the information
    //contained in the structure
    this->rows=rows;
    this->cols=cols;
    data=new int*[this->rows];
    for(int row=0;row<this->rows;row++){
        data[row]=new int[this->cols];
    }
}

Array2D::~Array2D(){
    for(int row=0;row<this->rows;row++){
        delete []data[row];
    }
    delete []data;
}
        
int Array2D::getData(int row,int col){
    if(row>=0&&row<=rows&&col>=0&&col<cols){
        return data[row][col];
    }else{
        exit(99);
    }
}

bool Array2D::setData(int row,int col,int val){
    if(row>=0&&row<=rows&&col>=0&&col<cols){
        data[row][col]=val;
        return true;
    }else{
        return false;
    }
}