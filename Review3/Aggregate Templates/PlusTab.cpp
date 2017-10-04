

#include "PlusTab.h"

PlusTab PlusTab::operator+(const PlusTab &tab) {
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