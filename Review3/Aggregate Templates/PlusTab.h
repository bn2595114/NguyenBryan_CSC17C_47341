/* 
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2016, 8:54 AM
 * Specification for the Table addition operator
 */

#ifndef PLUSTAB_H
#define	PLUSTAB_H

#include "Table.h"

template <class T>
class PlusTab:public Table<T>{
    public:
        PlusTab(int r,int c):Table<T>(r,c){};
        PlusTab<T> operator+(const PlusTab<T> &);
};

template <class T>
PlusTab<T> PlusTab<T>::operator+(const PlusTab<T> &tab) {
    int r = this->getSzRow();
    int c = this->getSzCol();
    
    PlusTab add(r, c);
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            add.setData(j, i, this->getData(j, i) + tab.getData(j, i));
        }
    }
    return add;
}

#endif	/* PLUSTAB_H */