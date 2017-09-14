/* 
 * File:   Array2D.h
 * Author: Dr. Mark E. Lehr
 * Created on September 6, 2017, 8:21 PM
 * Purpose:  2D Array class specification
 */

#ifndef ARRAY2D_H
#define ARRAY2D_H

class Array2D{
    private:
        int rows;
        int cols;
        int **data;
    public:
        Array2D(int,int);//Constructor
        ~Array2D();      //Destructor
        int getRows(){return rows;}
        int getCols(){return cols;}
        int getData(int,int);
        bool setData(int,int,int);
};



#endif /* ARRAY2D_H */

