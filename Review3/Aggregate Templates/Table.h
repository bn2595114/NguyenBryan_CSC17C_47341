/* 
 * File:   Table.h
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2016, 8:54 AM
 * Specification for the Table
 */

#ifndef TABLE_H
#define	TABLE_H

#include "AbsTabl.h"

template <class T>
class Table:public AbsTabl<T>{
    public:
        Table(int,int);
        Table(const Table &);
        virtual ~Table();
        int getSzRow()const {return this->szRow;}
        int getSzCol()const {return this->szCol;}
        T getData(int,int)const;
        void setData(int,int,T);
};

template <class T>
Table<T>::Table(int r,int c){
    this->szRow = r;
    this->szCol = c;
    this->columns = new RowAray<T>*[c]; // POINTER MAY BE OUT OF THE <T>
    for(int i=0; i<c; i++){
        this->columns[i] = new RowAray<T>(r);
    }
}

template <class T>
void Table<T>::setData(int r, int c, T val) {
        this->columns[c]->setData(r,val);
}

template <class T>
Table<T>::Table(const Table<T> &tab) {  // Table<T> might be wrong
    this->szRow = tab.getSzRow();
    this->szCol = tab.getSzCol();
    
    this->columns = new RowAray<T>*[this->szCol]; //Pointer might be out of <T>
    
    for (int i = 0; i < this->szCol; i++) {
        this->columns[i] = new RowAray<T>(this->szRow);
        for (int j = 0; j < this->szRow; j++) {
            this->columns[i]->setData(j, tab.getData(j, i));
        }
    }
} 

template <class T>
Table<T>::~Table(){
    for(int i=0; i<this->szCol; i++){
        delete this->columns[i];
    }
    delete[] this->columns;
}

template <class T>
T Table<T>::getData(int r, int c) const{
    return (this->columns[c])->getData(r);
}


#endif	/* TABLE_H */