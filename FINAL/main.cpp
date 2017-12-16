/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on December 15, 2017, 12:38 PM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <queue>
#include "Stack.h"
#include "clerk.h"
#include "BinaryTree.h"
#include "Graph.h"
using namespace std;

void menu();
int getN();

void p1();
int keyHash(string);

void p2();
float h(float, Stack<char>*);
float g(float, Stack<char>*);

void p3();

void p4();
short* fill(int);
short* cpy(short*,int);
void mergeSort(short*,int,long long&);
void pmergeSort(short*,short*,int,int,long long&);
void mergeCompare(short*,short*,int,int,int,long long&);
void swp(short*,short*,long long&);
void selectionSort(short[],int,long long&);

void p5();

void p6();
int main(int argc, char** argv) {

    srand(static_cast<unsigned int>(time(0)));
    int n;
    do{
    menu();
    n = getN();
        switch(n){
            case 1: p1();break;
            case 2: p2();break;
            case 3: p3();break;
            case 4: p4();break;
            case 5: p5();break;
            case 6: p6();break;
            default:;
        };
    } while(n<7);
    return 0;
}

void menu(){
    cout << "Enter the number for the problem." << endl;
    cout << "1) Hash" << endl;
    cout << "2) Stacks" << endl;
    cout << "3) Queues" << endl;
    cout << "4) Sorting" << endl;
    cout << "5) Binary Trees" << endl;
    cout << "6) Weighted Graph" << endl;
}

int getN(){
    int n;
    cin >> n;
    return n;
}

void p1(){
	int size = 512;
	string str = "   ";
	fstream file;
	file.open( "p1.dat", ios::out );
	map<int,int> stats;
	int bitvec[size];
	for (int i = 0; i < size; i++){
		bitvec[i] = 0;
	}

	for (int i = 0; i < size; i++){
		str[0] = (char) (rand() % 26 + 65);
		str[1] = (char) (rand() % 26 + 65);
		str[2] = (char) (rand() % 26 + 65);
		int hash = keyHash(str);
		file << str << " " << hash << endl;
		bitvec[hash % size]++;
	}
        // Utilized maps to make it easier
	file << "collision array\n";
	for (int i = 0; i < size; i++){
		if (stats.count(bitvec[i]) <= 0){
			stats[bitvec[i]] = 1;
		} else {
			stats[bitvec[i]]++;
		}
		file << setw(2) << bitvec[i] << " ";
		if ((i+1)%25==0){
			file << endl;
		}
	}

	int total = 0;
	for (map<int, int>::iterator it = stats.begin(); it != stats.end(); it++){
		if (it->first != 0) {
			total += it->second;
		}
		cout << it->first << " collisions occurred #" << it->second << endl;
		file << it->first << " collisions occurred #" << it->second << endl;
	}

	cout << "Max number of collisions is: " << (--stats.end())->first << endl;
	file << "Max number of collisions is: " << (--stats.end())->first << endl;
	cout << "Total collisions: " << total << endl;
	file << "Total collisions: " << total << endl;
	float avg = (float) size / total;
	cout << "average # of collisions: " << avg << endl;
	file << "average # of collisions: " << avg << endl;
	file.close();

}

int keyHash(string str){
	stringstream ss;
	for ( int i = 0; i < 3; i++ ){
		int j = 0;
		char c = str[i];
		if (c >= 65 && c <= 67){
			j = 2;
		} else if (c >= 68 && c <= 70){
			j = 3;
		} else if (c >= 71 && c <= 73){
			j = 4;
		} else if (c >= 74 && c <= 76){
			j = 5;
		} else if (c >= 77 && c <= 79){
			j = 6;
		} else if (c >= 80 && c <= 83){
			j = 7;
		} else if (c >= 84 && c <= 86){
			j = 8;
		} else if (c >= 85 && c <= 90){
			j = 9;
		}
		ss << "" << j;
	}
        int hash;
        ss >> hash;
	return hash;

}

/////////////////////////////////////////////////////////////////////////

void p2(){
	Stack<char> *stack = new Stack<char>;
	printf("correct value | my value\n");
	printf("rad\tcosh\tsinh\tsin val\t\tcos val\n");
	for (float rad = -1; rad <= 1.1; rad += .1){
		float angRad = rad;
		float sval = h(angRad, stack);
		float cval = g(angRad, stack);
		int len = stack->getSize();
		int cc = 0, sc = 0;
		for (int i = 0; i < len; i++){
			if (stack->pop() == 'c'){
				cc++;
			} else{
				sc++;
			}
		}
		printf("%3.2f\t%d\t%d\t%6.4f|%6.4f\t%6.4f|%6.4f\n",angRad,cc,sc,sinh(angRad),sval,cosh(angRad),cval);
	}
	delete stack;
}

float h(float angR, Stack<char> *stack) { //sinh
	stack->push('s');
	float tol = 1e-6;
	if(angR>-tol && angR < tol)return angR+angR*angR*angR/6;
	return 2*h(angR/2,stack) * g(angR/2,stack);
}

float g(float angR, Stack<char> *stack){ //cosh
	stack->push( 'c' );
	float tol = 1e-6;
	if (angR>-tol && angR < tol)return 1+angR*angR/2;
	float b=h(angR/2,stack);
	return 1+2*b*b;
}


////////////////////////////////////////////////////////////////////////////


void p3(){
	queue<int> customers;
	vector<Clerk> clerks;

	for (int i = 0; i < 3; i++){
		Clerk clerk;
		clerk.busy = false;
		clerk.startTime = 0;
		clerk.served = 0;
		clerks.push_back(clerk);
	}
	int wait = 0;
	bool waiting = true;
	int runTime = 60 * 60;
	int clerktimes[] = {60, 120, 80};
	int totalCust = 0;
	cout << "how many hours do you want to run: ";
	cin >> runTime;
	runTime*= 60*60;

	for (int sec = 0; sec <= runTime; sec += 5) {
		bool free = false;

		for (int i = 0; i < clerks.size(); i++) {
			int delta = (i > 2 ? 60 : clerktimes[i]);
			if ( clerks[i].busy ) { 
				if (clerks[i].startTime + delta == sec) {
					clerks[i].busy = false;
					clerks[i].startTime = 0;
					clerks[i].served++;
					free = true;
				}
			}
		}
		if (sec%15 == 0) {
			customers.push( 1 ); 
			totalCust++;
		}
		waiting = true;
		if (customers.size() > 0){
			for (int i = 0; i < clerks.size(); i++){
				if (!( clerks[i].busy ) && customers.size( ) > 0) {
					waiting = false;
					clerks[i].busy = true;
					clerks[i].startTime = sec; 
					customers.pop();
				}
			}
			wait += (waiting ? 5*customers.size() : 0);
		}
		if(sec % 10 == 0 && false){
			for (int i = 0; i < clerks.size( ); ++i){
				cout << setw(6) << sec << setw(3) << i+1 << setw(3) << (clerks[i].busy ? "T" : "F") << endl;
			}
		}
		if (customers.size( ) > 5 && !free) {
			Clerk clerk;
			clerk.busy = false;
			clerk.startTime = 0;
			clerk.served = 0;
			clerks.push_back(clerk);
		}
		
		if(customers.size() == 0 && clerks.size() > 3){
			clerks.pop_back();
		}
	}

	cout << "the number of customers is " << --totalCust << endl;
	for(int i = 0; i < clerks.size(); i++){
		cout << "clerk " << i + 1 << " served " << clerks[i].served << endl;
		
	}
	cout << "average wait is " << (wait/60.0f) / totalCust<< " minutes" << endl;
        cout << "Longer service time -> more clerks" << endl;
        cout << "Less arrival time -> less clerks and more centered on clerk 1" << endl;
}

///////////////////////////////////////////////////////////////////////////////

void p4() {
	int size = 100000;
	short *master = fill( size );
	short *arr = cpy( master, size );
	long s, e;
	long long count = 0;
	
	s = time(0);
	mergeSort(arr, size, count);
	e = time(0);
	cout << "merge sort operations: " << count << endl;
	cout << "merge sort time: " << (e-s) << endl;
	delete [] arr;
	arr = cpy(master, size);

        count = 0;
        s = time(0);
        selectionSort(arr, size, count);
        e = time(0);
        cout << "selection sort operations: " << count << endl;
        cout << "selection sort time: " << (e-s) << endl;
	
	delete [] arr;
	delete [] master;
}

void mergeSort(short *a, int size, long long &count) {
    short *temp = new short[ size ];
	count++;
    pmergeSort(a, temp, 0, size - 1, count);
}

void pmergeSort(short *a, short *temp, int left, int right, long long &count) {
	count++;
    if(left < right) {
        int center = (left + right) / 2;
		count++;
        pmergeSort(a, temp, left, center, count);
        pmergeSort(a, temp, center + 1, right, count);
        mergeCompare(a, temp, left, center, right, count);
    }
}

void mergeCompare(short *a, short *temp, int left, int center, int right, long long &count) {
    int leftBegin = left;
    int leftEnd = center;
    int rightBegin = center + 1;
    int rightEnd = right;
    int i = 0;
	count+=5;
	
    while ((leftBegin <= leftEnd) && (rightBegin <= rightEnd)) { 
		count+=3;
        if(a[leftBegin] <= a[rightBegin]) {
            temp[i] = a[leftBegin];
            leftBegin++;
			count+=2;
        } else{
            temp[i] = a[rightBegin]; 
            rightBegin++;
			count+=2;
        }
        i++;
		count++;
    }

    while (leftBegin <= leftEnd) { 
        temp[i] = a[leftBegin];
        i++;
        leftBegin++;
		count+=4;
    }

    while (rightBegin <= rightEnd) { 
        temp[i] = a[rightBegin];
        i++;
        rightBegin++;
		count+=4;
    }

	count++;
    for (int j = left; j <= rightEnd; j++) {
        a[j] = temp[ j - left];
		count+=3;
    }
}


short* fill(int size){
	short *t = new short[size];
	for (int i = 0; i < size; i++){
		t[i] = rand() % size;
	}
	return t;
}

short* cpy(short *arr, int size) {
	short *temp = new short[size];
	for (int i = 0; i < size; i++){
		temp[i] = arr[i];
	}
	return temp;
}

void swp(short *xp, short *yp, long long& count)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    count+=3;
}
 
void selectionSort(short arr[], int n, long long& count)
{
    int i, j, min_idx;
    count++;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        count++;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        count += 7;
        swp(&arr[min_idx], &arr[i], count);
    }
}

//////////////////////////////////////////////////////////////////////////

void p5() {
	int size = 512;
	BinaryTree<string> *tree = new BinaryTree<string>;
	cout << "Tree contains\n";
	string str = "   ";

	for (int i = 0; i < size; i++) {
		str[0] = (char) (rand() % 26 + 65);
		str[1] = (char) (rand() % 26 + 65);
		str[2] = (char) (rand() % 26 + 65);
		tree->insert( str );
	}
        cout << endl;
	cout << "At most it will take " << ceil( log( size ) / log( 2 ) ) +1
             << " turns to find for the tree";
        cout << endl;

        
        cout << "For Hash..." << endl;
        p1();
	delete tree;
}

//////////////////////////////////////////////////////////////////////

void p6(){
    Graph g(7);
    vector<string> names;
    names.push_back("SFO");
    names.push_back("ORD");
    names.push_back("JFK");
    names.push_back("DFW");
    names.push_back("MIA");
    names.push_back("LAX");
    names.push_back("BOS");
    g.addNames(names);
    g.addEdge("SFO","BOS",2703);
    g.addEdge("SFO","ORD",1847);
    g.addEdge("ORD","BOS",866);
    g.addEdge("ORD","JFK",741);
    g.addEdge("JFK","BOS",188);
    g.addEdge("SFO","DFW",1463);
    g.addEdge("DFW","ORD",801);
    g.addEdge("DFW","MIA",1122);
    g.addEdge("MIA","JFK",1091);
    g.addEdge("MIA","BOS",1257);
    g.addEdge("SFO","LAX",338);
    g.addEdge("LAX","DFW",1234);
    g.addEdge("LAX","MIA",2341);
    g.kMST();
    g.shortestPath("BOS","LAX");
}