/* 
 * File:   Array2D.h
 * Author: Dr. Mark E. Lehr
 * Created on September 6, 2017, 8:21 PM
 * Purpose:  2D Array class specification
 */

#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <cstdlib>
using namespace std;

template <class T>
class Array2D{
    private:
        int rows;
        int cols;
        T **data;
    public:
        Array2D(int,int);//Constructor
        ~Array2D();      //Destructor
        int getRows(){return rows;}
        int getCols(){return cols;}
        T getData(int,int);
        bool setData(int,int,T);
};

template <class T>
Array2D<T>::Array2D(int rows,int cols){
    //Allocating memory for the information
    //contained in the structure
    this->rows=rows;
    this->cols=cols;
    data=new T*[this->rows];
    for(int row=0;row<this->rows;row++){
        data[row]=new T[this->cols];
    }
}

template <class T>
Array2D<T>::~Array2D(){
    for(int row=0;row<this->rows;row++){
        delete []data[row];
    }
    delete []data;
}
     
template <class T>
T Array2D<T>::getData(int row,int col){
    if(row>=0&&row<=rows&&col>=0&&col<cols){
        return data[row][col];
    }else{
        exit(99);
    }
}

template <class T>
bool Array2D<T>::setData(int row,int col,T val){
    if(row>=0&&row<=rows&&col>=0&&col<cols){
        data[row][col]=val;
        return true;
    }else{
        return false;
    }
}


#endif /* ARRAY2D_H */

