
#include <cstdlib>
#include "RowAray.h"

RowAray::RowAray(unsigned int n){
    size = n;
    rowData = new int[size];
    for(int i=0; i<size; i++){
        rowData[i] = rand()%90+10;
    }
}

RowAray::~RowAray(){
    delete[] rowData;
}

void RowAray::setData(int pos, int val) {
        rowData[pos] = val;
}