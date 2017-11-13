/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on November 9, 2017, 12:57 AM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int ce,cadd,csub,crel,clo,cee;

void swap(int *, int *);
void selectionSort(int[], int);
void swapT(int *, int *);
void selectionSortT(int[], int);
void printArray(int[], int);

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE=100;
    int arr[SIZE];
    for(int i=0;i<SIZE;i++)
        arr[i]=rand()%10;
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    
    cout<<"Equality="<<ce<<endl;
    cout<<"Relation="<<crel<<endl;
    cout<<"Subtraction="<<csub<<endl;
    cout<<"Additions="<<cadd<<endl;
    cout << "==" << cee << endl;
    cout<<"Composite="<<ce+crel+csub+cadd+cee<<endl << endl;

    const int S=40000;
    int a[S];
    for(int i=0;i<S;i++)
        a[i]=rand()%10;
    int y=sizeof(a)/sizeof(a[0]);
    int beg=time(0);
    selectionSortT(a,y);
    int end=time(0);
    
    cout << "Selection Sort Time: " << end-beg << endl;
    return 0;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    ce+=3;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        ce++; crel++;csub++;ce++;cadd++;
        // Find the minimum element in unsorted array
        min_idx = i;
        ce++;
        for (j = i+1; j < n; j++){
            ce++;cadd++;crel++;ce++;cadd++;
          if (arr[j] < arr[min_idx]){
              crel++;
            min_idx = j;
            ce++;
          }
        }
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
 
void selectionSortT(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swapT(&arr[min_idx], &arr[i]);
    }
}

void swapT(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}