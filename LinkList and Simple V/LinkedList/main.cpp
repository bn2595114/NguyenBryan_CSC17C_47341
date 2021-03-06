//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 21st, 2017 8:40 PM
 * Purpose:  Linked List Version 3 Objects - Procedures with ADT
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "Object.h"
#include "LinkedList.h"

//Global Constants Only, No Global Variables

//Function Prototypes Here

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare an object and place in the linked list
    Object obj(5);
    LinkedList<Object> *lnkList;
    lnkList=new LinkedList<Object>(obj);
    
    //Print the entire list
    lnkList->prntLst();
    //Add a value to the end of the list
    Object valAdd(2);
    Object valFnd1(valAdd);
    Object valFnd2(5);
    lnkList->addLst(valAdd);
    lnkList->addLst(Object(3));
    lnkList->addLst(Object(4));
    lnkList->addLst(Object(5));
    lnkList->addLst(Object(6));
    
    
    cout << "Adding links after, before, beginning, and end" << endl;
    Object temp(7);
    lnkList->addAfter(temp, 1); // Add object temp after link 1
    lnkList->addBefore(temp, 7); // Add object temp before link 7
    lnkList->addBeg(temp); // Add object in the beginning of list
    lnkList->addLst(temp); // Add object at end of list
    
    //Print the entire list after adding to it
    lnkList->prntLst();
    
    //Deallocate memory
    delete lnkList;

    //Exit
    return 0;
}