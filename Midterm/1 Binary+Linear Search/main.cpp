/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on November 7, 2017, 5:04 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int ce,cadd,csub,crel, cee,cdiv,cmul;

void fill(int*, int);
int binarySearch(int[], int, int, int);
int binarySearchT(int[], int , int , int );
int search(int[], int, int);
int searchT(int[], int, int);

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE=100;
    int a[SIZE];
    int n = sizeof(a)/ sizeof(a[0]);
    fill(a,SIZE);
    
    binarySearch(a,0,n-1,SIZE/7);
    cout << "Binary Search: " << endl;
    cout << "=: " << ce << endl;
    cout << "+: " << cadd << endl;
    cout << "-: " << csub << endl;
    cout << "crel: " << crel << endl;
    cout << "==: " << cee << endl;
    cout << "*: " << cmul << endl;
    cout << "/: " << cdiv << endl;
    cout << endl; 
    
    ce=0;cadd=0;csub=0;crel=0; cee=0;cdiv=0;cmul=0;
    search(a,SIZE,SIZE-1);
    cout << "Linear Search: " << endl;
    cout << "=: " << ce << endl;
    cout << "+: " << cadd << endl;
    cout << "-: " << csub << endl;
    cout << "crel: " << crel << endl;
    cout << "==: " << cee << endl;
    cout << "*: " << cmul << endl;
    cout << "/: " << cdiv << endl;
    
    const int S = 400000;
    int x[S];
    for(int i=0;i<S;i++)
        x[i]=rand()%10;
    int y = sizeof(x)/ sizeof(x[0]);
    int beg=time(0);
    binarySearchT(x,0,y-1,S-1);
    int end=time(0);
    cout << "BINARY SEARCH TIME: " << end-beg << endl << endl;
    
    beg=time(0);
    searchT(x,S,S-1);
    end=time(0);
    cout << "LINEAR SEARCH TIME: " << end-beg << endl;
    
    
    return 0;
}


void fill(int* ary, int size){
    for(int i=0; i<size;i++)
        ary[i]=i;
}

int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
       crel++;ce++;
        int mid = l + (r - l)/2;
        ce++;cadd++;csub++;cdiv++;
        // If the element is present at the middle itself
        if (arr[mid] == x){
            cee++;
            return mid;
        }
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x){ 
            crel++;csub++;
            return binarySearch(arr, l, mid-1, x);
        }
        // Else the element can only be present in right subarray
        cadd++;
        return binarySearch(arr, mid+1, r, x);
   }
 
   // We reach here when element is not present in array
   return -1;
}

int binarySearchT(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
       
        int mid = l + (r - l)/2;
       
        // If the element is present at the middle itself
        if (arr[mid] == x){
         
            return mid;
        }
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x){ 
          
            return binarySearch(arr, l, mid-1, x);
        }
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
   }
 
   // We reach here when element is not present in array
   return -1;
}

int searchT(int arr[], int n, int x)
{
    for (int i=0; i<n; i++)
    {
        if (arr[i] == x){
         return i;
        }
    }
    return -1;
}

int search(int arr[], int n, int x)
{
    
    for (int i=0; i<n; i++)
    {
        ce++; crel++; cadd++;
        if (arr[i] == x){
            cee++;
         return i;
        }
    }
    return -1;
}