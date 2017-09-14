/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 30, 2017, 8:20 PM
 * Purpose:  Dynamic Array Class Implementation
 */

#include "array.h"
#include <iostream>
#include <cstdlib>
using namespace std;


Array::Array(int n){
    size=n;
    data=new int[size];
    //Set the values
    for(int i=0;i<n;i++){
        data[i]=rand()%90+10;
    }
}

void Array::prntAry(int perLine)const{
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void Array::mrkSort(){
    for(int pos=0;pos<size-1;pos++){
        for(int i=pos+1;i<size;i++){
            if(data[pos]>data[i]){
                data[pos]=data[pos]^data[i];
                data[i]=data[pos]^data[i];
                data[pos]=data[pos]^data[i];
            }
        }
    }
}
