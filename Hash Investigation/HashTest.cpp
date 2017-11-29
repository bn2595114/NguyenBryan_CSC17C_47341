/*
 **************************************************************************
 *                                                                        *
 *           General Purpose Hash Function Algorithms Test                *
 *                                                                        *
 * Author: Arash Partow - 2002                                            *
 * URL: http://www.partow.net                                             *
 * URL: http://www.partow.net/programming/hashfunctions/index.html        *
 *                                                                        *
 * Copyright notice:                                                      *
 * Free use of the General Purpose Hash Function Algorithms Library is    *
 * permitted under the guidelines and in accordance with the most current *
 * version of the Common Public License.                                  *
 * http://www.opensource.org/licenses/cpl1.0.php                          *
 *                                                                        *
 **************************************************************************
*/


#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include "GeneralHashFunctions.h"
using namespace std;

int main(int argc, char* argv[])
{
   string key = "abcdefghijklmnopqrstuvwxyz1234567890";

   cout << "General Purpose Hash Function Algorithms Test" <<endl;
   cout << "By Arash Partow - 2002        " <<endl;
   cout << "Key:     " <<key<<endl<<endl;
   cout << " 1. RS-Hash Function Value:   " <<setw(15)<< RSHash(key)   <<endl;
   cout << " 2. JS-Hash Function Value:   " <<setw(15)<< JSHash(key)   <<endl;
   cout << " 3. PJW-Hash Function Value:  " <<setw(15)<< PJWHash(key)  <<endl;
   cout << " 4. ELF-Hash Function Value:  " <<setw(15)<< ELFHash(key)  <<endl;
   cout << " 5. BKDR-Hash Function Value: " <<setw(15)<< BKDRHash(key) <<endl;
   cout << " 6. SDBM-Hash Function Value: " <<setw(15)<< SDBMHash(key) <<endl;
   cout << " 7. DJB-Hash Function Value:  " <<setw(15)<< DJBHash(key)  <<endl;
   cout << " 8. DEK-Hash Function Value:  " <<setw(15)<< DEKHash(key)  <<endl;
   cout << " 9. FNV-Hash Function Value:  " <<setw(15)<< FNVHash(key)  <<endl;
   cout << "10. BP-Hash Function Value:   " <<setw(15)<< BPHash(key)   <<endl;
   cout << "11. AP-Hash Function Value:   " <<setw(15)<< APHash(key)   <<endl;
   cout << endl << endl;
   
   
  
  
   map<unsigned int,int>x;
   
   
   
   int count=0;
   int hits=0;
    string test; 
    ifstream infile;
    string file = "Collision.txt";
    infile.open(file.c_str());
    
    getline(infile,test);
    while(getline(infile,test)){
        count++;
        x[RSHash(test)]++;
        if(x[RSHash(test)]>1)
            hits++;
        if(hits)
            break;
    }
    infile.close();
   int collisions=0;
   int high=-1;
   for(map<unsigned int,int>::iterator it=x.begin(); it!=x.end(); ++it)
   {
       cout << it->first << ":  " << it->second << endl;
       if(it->second>1)
           collisions+=(it->second)-1;
       if((it->second)>high)
           high = it->second;
   }
   cout << endl;
   
   map<unsigned int, int>y;
   cout << endl << endl;
   int count1=0;
   int hits1=0;
   string tst;
   infile.open(file.c_str());
   while(getline(infile,tst)){
        count1++;
        y[RSHash(tst)]++;
        if(y[RSHash(tst)]>1)
            hits1++;
    }
   int collisions1=0;
   for(map<unsigned int,int>::iterator it=y.begin(); it!=y.end(); ++it)
   {
       cout << it->first << ":  " << it->second << endl;
       if(it->second>1)
           collisions1+=(it->second)-1;
       if((it->second)>high)
           high = it->second;
   }
   cout << endl;
   cout << "Number of Elements: " << count1 << endl;
   cout << "Number of elements until first collision: " << count << endl;
   cout << "Collision: " << collisions/365.f << endl;
   cout << endl;
   
   cout << "Number of Elements: " << count1 << endl;
   cout << "Number of collisions: " << collisions1 << endl;
   cout << "Collisions: " << collisions1/365.f << endl;
   
   
   return 0;
}
