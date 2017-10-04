/* 
 * File:   RowAray.h
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2016, 8:54 AM
 * Specification for the RowAray
 */

#ifndef ROWARAY_H
#define	ROWARAY_H

#include "AbsRow.h"

template <class T>
class RowAray:public AbsRow<T>{
    public:
        RowAray(unsigned int);
        virtual ~RowAray();
        int getSize()const{return size;}
        int getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,int);
};

#endif	/* ROWARAY_H */