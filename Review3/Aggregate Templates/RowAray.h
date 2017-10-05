/* 
 * File:   RowAray.h
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2016, 8:54 AM
 * Specification for the RowAray
 */

#ifndef ROWARAY_H
#define	ROWARAY_H

#include <cstdlib>
#include "AbsRow.h"

template <class T>
class RowAray:public AbsRow<T>{
    public:
        RowAray(T);
        virtual ~RowAray(){delete[] this->rowData;};
        T getSize()const{return this->size;}
        T getData(int i)const{
            if(i>=0&&i<this->size)return this->rowData[i];
            else return 0;}
        void setData(int p,T v){this->rowData[p]=v;};
};

template <class T>
RowAray<T>::RowAray(T n){
    this->size = n;
    this->rowData = new T[this->size];
    for(int i=0; i<(this->size); i++){
        this->rowData[i] = rand()%90+10;
    }
}





#endif	/* ROWARAY_H */