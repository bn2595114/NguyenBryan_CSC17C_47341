#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
#include "Table.h"

Table::Table(int r, int c){
    srand(static_cast<unsigned int>(time(0)));
    szRow = r;
    szCol = c;
    records = new RowAray*[szRow];
    for(int i=0; i<szRow; i++){
        records[i] = new RowAray(szCol);
    }
}

int Table::getData(int r, int c){
  //  records[r][c] = rand()%90+10;
    //return (records[r][c].getData(rand()%48)); CANT FIGURE THIS OUT
    return rand()%90+10;
}







Table::~Table()
{
    for(int i=0; i<szRow; i++)
    {
        delete[] records[i];
    }
    
        delete[] records;
}