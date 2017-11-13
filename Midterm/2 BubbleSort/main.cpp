// C program for implementation of selection sort
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int ce,cadd,csub,crel,clo,cee;

void swap(int *, int *);
// An optimized version of Bubble Sort
void bubbleSort(int[], int);
void bubbleSortT(int[], int);
/* Function to print an array */
void printArray(int[], int);

// Driver program to test above functions
int main()
{
    const int SIZE=10;
    srand(static_cast<unsigned int>(time(0)));
    int arr[10];
    for(int i=0; i<SIZE;i++)
        arr[i]=rand()%100;
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
   // printf("Sorted array: \n");
    //printArray(arr, n);
    
    cout<<"Equality="<<ce<<endl;
    cout<<"Relation="<<crel<<endl;
    cout<<"Subtraction="<<csub<<endl;
    cout<<"Additions="<<cadd<<endl;
    cout << "==" << cee << endl;
    cout<<"Composite="<<ce+crel+csub+cadd+cee<<endl << endl;
    
    const int SIZET=20000;
    int a[SIZET];
    for(int i=0;i<SIZET;i++)
        a[i]=rand()%10;
    int x = sizeof(a)/sizeof(a[0]);
    int beg=time(0);
    bubbleSortT(a,x);
    int end=time(0);
    cout << "TIME: " << end-beg << "sec" << endl;
    return 0;
}

void swap(int *xp, int *yp)
{
    ce+=3;
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
       ce++; crel++;csub++;cadd++;ce++;
     swapped = false;
     ce++;
     for (j = 0; j < n-i-1; j++)
     {
         ce++;csub+=2;cadd++;ce++;
        if (arr[j] > arr[j+1])
        {
            crel++;cadd++;
           swap(&arr[j], &arr[j+1]);
           swapped = true;
           ce++;
        }
     }
     // IF no two elements were swapped by inner loop, then break
     if (swapped == false){
         cee++;
        break;
     }
   }
}

void bubbleSortT(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
 
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}