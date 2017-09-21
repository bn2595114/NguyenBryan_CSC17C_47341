#include <cstdlib>
#include <ctime>
#include "Triangle.h"



Triangle::Triangle(int r){
    srand(static_cast<unsigned int>(time(0)));
    szRow = r;
    records = new RowAray*[(szRow*szRow+szRow)/2];
}

int Triangle::getData(int r, int c){
    return (rand()%90+10);
}

Triangle::~Triangle(){
    delete[] records;
}