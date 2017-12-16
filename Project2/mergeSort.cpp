
#include <cstdlib>
#include <iostream>
#include "mergeSort.h"
using namespace std;
MergeSort::MergeSort(){
    a->size=0;
    a->sortit=NULL;
    a->working=NULL;
}

void MergeSort::merge(int beg, int nlow, int nhigh){
    //Create a merged array
    int span=nhigh-beg;    //Span the range to merge
    int cntl=beg,cnth=nlow;//Independent counters to merge the split
    //Fill the array
    for(int i=0;i<span;i++){
        if(cntl==nlow){//Low done fill with the higher end of array
            a->working[i]=a->sortit[cnth++];
        }else if(cnth==nhigh){//High done fill with lower end of array
            a->working[i]=a->sortit[cntl++];
        }else if(a->sortit[cntl]<a->sortit[cnth]){
            a->working[i]=a->sortit[cntl++];//Fill with lower end
        }else{
            a->working[i]=a->sortit[cnth++];//Fill with higher end
        }
    }
    //Copy back from the working array to the sorted array
    for(int i=0;i<span;i++){
        a->sortit[beg+i]=a->working[i];
    }
}

void MergeSort::mergeSort(int beg, int end){
    int center=(beg+end)/2;//Split the task down the middle
    if((center-beg)>1)mergeSort(beg,center);//Got to be an array to split
    if((end-center)>1)mergeSort(center,end);//Got to be an array to split
    merge(beg,center,end);//Merge the sorted arrays into 1 larger sorted array
}
 

void MergeSort::fill(int n){
        //Allocate memory
    Data *data=new Data;
    data->size=n;
    data->sortit=new int[n];
    data->working=new int[n];
    for(int i=0;i<n;i++){
        data->sortit[i]=rand()%100+1;
    }
    a = data;
}

void MergeSort::print(int perLine){
    //First print the unsorted array
    cout<<endl;
    for(int i=0;i<a->size;i++){
        cout<<a->sortit[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

MergeSort::~MergeSort(){
    delete[] a->sortit;
    delete[] a->working;
    delete a;
}