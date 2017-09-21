/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstdlib>
#include <ctime>
#include "RowAray.h"


RowAray::RowAray(int c){
    srand(static_cast<unsigned int>(time(0)));
    size = c;
    rowData = new int[size];
    for(int i=0; i<size; i++){
        rowData[i] = rand()%90+10;
    }
}


RowAray::~RowAray(){
        delete rowData;
}










