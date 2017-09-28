
#include <cstdlib>
#include <ctime>
#include "Table.h"

Table::Table(unsigned int r, unsigned int c){
    szRow = r;
    szCol = c;
    columns = new RowAray*[c];
    for(int i=0; i<c; i++){
        columns[i] = new RowAray(r);
    }
}

Table::Table(const Table& tab){
    szRow = tab.getSzRow();
    szCol = tab.getSzCol();
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