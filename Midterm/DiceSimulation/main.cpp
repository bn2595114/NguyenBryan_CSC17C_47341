
//Libraries
#include <cstdlib>//Random number seed
#include <ctime>//Set the seed
#include <iostream>//I/O
using namespace std;

void rng(int*, int);
void count(int*,int,float&,float&,float&,float&);
void swap(int*, int*);
void minPos(int*, int,int);
void mrkSort(int*,int);

int main(int argc, char*argv[]) {

    srand(static_cast<unsigned int>(time(0)));
    float pair=0, twoPair=0, three=0, four=0;
    int SIZE=4;
    int* roll = new int[4];
    cout << "DICE ROLLING SIMULATION" << endl;
    cout << "ROLLING 1,000,000 TIMES" << endl << endl;
    for(int i=0; i<1000000;i++){
        rng(roll, SIZE);
        count(roll,SIZE,pair,twoPair,three,four);
    }
    cout << "PAIRS: " << pair << endl;
    cout << "TWO PAIRS: " << twoPair << endl;
    cout << "THREE OF A KIND: " << three << endl;
    cout << "FOUR OF A KIND: " << four << endl << endl;
    
    cout << "PERCENTAGE OF PAIRS: " << (pair/1000000)*100 << endl;
    cout << "PERCENTAGE OF TWO PAIRS: " << (twoPair/1000000)*100 << endl;
    cout << "PERCENTAGE OF THREE OF A KIND: " << (three/1000000)*100 << endl;
    cout << "PERCENTAGE OF FOUR OF A KIND: " << (four/1000000)*100 << endl;
    delete[] roll;
    return 0;
}

void rng(int* ary, int size){
    for(int i=0; i<size;i++)
        ary[i] = rand()%6+1;
}

void count(int* ary, int size, float& pr, float& tpr, float& thr, float& four){
    mrkSort(ary, size);
    int count=1;
    int count1=1;
    for(int i=0; i<size-1; i++){
        if(ary[i]==ary[i+1])
            count++;
        else{
            if(count>1)
            count1=count;
            count=1;
        }
    }
    if(count==2 && count1==2)
        tpr++;
    if(count==3 || count1==3)
        thr++;
    if(count==4)
        four++;
    if((count==2) && (count1!=2))
        pr++;
    if((count!=2) && (count1==2))
        pr++;
}


//copy paste from here on down
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