
#include <cstdlib>

#include "Table.h"

Table::Table(unsigned int r, unsigned int c){
    szRow = r;
    szCol = c;
    columns = new RowAray*[c];
    for(int i=0; i<c; i++){
        columns[i] = new RowAray(r);
    }
}

void Table::setData(int r, int c, int val) {
        columns[c]->setData(r,val);
}


Table::Table(const Table &tab) {
    szRow = tab.getSzRow();
    szCol = tab.getSzCol();
    
    columns = new RowAray*[szCol];
    
    for (int i = 0; i < szCol; i++) {
        columns[i] = new RowAray(szRow);
        for (int j = 0; j < szRow; j++) {
            columns[i]->setData(j, tab.getData(j, i));
        }
    }
}

Table::~Table(){
    for(int i=0; i<szCol; i++){
        delete columns[i];
    }
    delete[] columns;
}

int Table::getData(int r, int c) const{
    return columns[c]->getData(r);
}