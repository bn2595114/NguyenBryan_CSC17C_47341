/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr // Edited by Bryan Nguyen
 * Created on September 1st, 2017, 7:45 PM
 */

//Libraries
#include <cstdlib>//Random number seed
#include <ctime>//Set the seed
#include <iostream>//I/O
#include <set>
#include <iterator>
#include <map>
#include <algorithm>
using namespace std;

//No Global Constants

//Function Prototypes
int *fillAry(int,int);
void prntAry(int *,int,int);
void prntMod(int *);
void swap(int *,int *);
void minPos(int *,int,int);
void mrkSort(int *,int);
void *mode(const int *,int);
int *copy(const int *,int);

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize=95;
    int modNum=10;
    int *ary=fillAry(arySize,modNum);
    
    //Print the initial array
    prntAry(ary,arySize,10);
    cout << endl;
    //Calculate the mode array
    mode(ary,arySize);
    
    //Print the modal information of the array
 // prntMod(modeAry);
    
    //Delete allocated memory
    delete []ary;
 //  delete []modeAry;
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void *mode(const int *array,int arySize){
    //Copy the array
    int *ary=copy(array,arySize);
    //Sort the ary
    mrkSort(ary,arySize);
    //Sort the copy
    map<int,int,greater<int> >a;
    set<int, greater<int> >order;
    for(int i=0;i<arySize;i++)
        a[ary[i]]++;
    for(map<int,int>::iterator it=a.begin();it!=a.end();++it){
        cout << "Number:"<< it->first
             << "   Count:" << it->second << endl;
    }
    cout << endl;
    for(map<int,int>::iterator it=a.begin();it!=a.end();++it){
        order.insert(it->second);
    }
    cout << "Max Freq: " << *order.begin() << endl;
    //Find the number of modes
    int count=0;
    for(map<int,int>::iterator it=a.begin();it!=a.end();++it){
        if(it->second == *order.begin())
            count++;
    }
    cout<<"Number of modes = "<<count<<endl;
    cout << "Modes: ";
    for(map<int,int>::iterator it=a.begin();it!=a.end();++it)
        if(*order.begin() == it->second)
            cout << it->first << " ";
    cout << endl;
    
    //Delete the allocated copy and return
    delete []ary;
}

void prntMod(int *ary){
    cout<<endl;
    cout<<"The mode array is sized as # of modes + 2"<<endl;
    cout<<"array[0]=nModes, array[1]=frequency, ";
    cout<<"array[2] to array[nModes+1]=All the modes"<<endl;
    cout<<"The number of modes = "<<
            ary[0]<<endl;
    cout<<"The max Frequency = "<<
            ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";
    for(int i=2;i<ary[0]+1;i++){
        cout<<ary[i]<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        minPos(array,n,i);
    }
}

void minPos(int *array,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(*(array+pos)>*(array+i))
            swap(array+pos,array+i);
    }
}

void swap(int *a,int *b){
    //Swap in place
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

void prntAry(int *array,int n,int perLine){
    //Output the array
    cout<<endl;
    cout<<"The Array filled with non-Random numbers to control the ";
    cout<<"Number of modes!!!"<<endl;
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n, int modNum){
    //Allocate memory
    int *array=new int[n];
    
    //Fill the array with 2 digit numbers
    for(int i=0;i<n;i++){
        *(array+i)=i%modNum;
        //*(array+i)=rand()%modNum;
    }
    
    //Exit function
    return array;
}