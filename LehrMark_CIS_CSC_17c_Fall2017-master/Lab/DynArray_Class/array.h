/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 30, 2017, 8:20 PM
 * Purpose:  Dynamic Array Class Specification
 */

#ifndef ARRAY_H
#define ARRAY_H

class Array{
    private:
        int size;
        int *data;
    public:
        Array(int); //Constructor
        ~Array(){delete []data;}//Destructor
        void prntAry(int)const;
        void mrkSort();
};

#endif /* ARRAY_H */

