/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 13, 2016, 4:31 PM
 * Purpose:  Test out push values onto simple vector
 *           with a very complex object
 *           Note:  This simple vector only works with objects
 *           Also overloading the == operator in this version of Object
 *           Simple Vector using Linked List
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

//User Libraries
#include "Object.h"       //2D Object
#include "LinkedList.h"
#include "SimpleVector.h" //Simple Vector only works with Classes

//Global Constants

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Test an object
    Object a(3),b(4);
    //Object aa(a);
    //if(aa==a)cout<<"The following 2 Objects are exactly the Same!"<<endl;
    //else cout<<"The following 2 Objects are not the Same!"<<endl;
    //cout<<"One of the Objects"<<a;
    //cout<<"Copy of the above Object"<<aa;
    //if(a==b)cout<<"The following 2 Objects are exactly the Same!"<<endl;
    //else cout<<"The following 2 Objects are not the Same!"<<endl;
    //cout<<"One of the Objects"<<a;
    //cout<<"The second object is not the same"<<b;
    
    //Test an object by populating the simple vector and print
    LinkedList<Object> *aptr;
    aptr=new LinkedList<Object>(a);
    //cout<<"How many objects in the LinkedLst = "<<aptr->cntLst()<<endl;
    SimpleVector<Object> svp(a);
    //cout<<"Simple Vector Object = "<<svp[svp.size()-1];
    //cout<<"Simple Vector Object = "<<svp[0];
    
    //Push an Object and printout the last object
    //svp.push(b);
    //cout<<"Simple Vector Push   = "<<svp[svp.size()-1];

    //Fill the simple vector with 100 randomly size 2D Array Objects and
    //print the last one
    int beg=time(0);
    for(int i=0;i<100;i++){
        int rSize=rand()%10;
        Object c(rSize);
        svp.push(c);
    }
    int end=time(0);
    
    cout << "TIME: " << end-beg << endl;
    /*cout<<"Size of the Simple Vector = "
            <<" "<<svp.size()<<endl;
    cout<<"The last object in the Vector is "<<endl;
    cout<<svp[svp.size()-1];
    
    //Create another simple vector by copy constructor
    SimpleVector<Object> csvp(svp);
    cout<<"Size of the Copy Constructed Simple Vector = "
            <<" "<<csvp.size()<<endl;
    cout<<"The last object in the Vector is "<<endl;
    cout<<csvp[csvp.size()-1];
    //Exit
     */
    return 0;
}