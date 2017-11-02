/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   levels.h
 * Author: Bryan
 *
 * Created on October 27, 2017, 5:33 PM
 */

#ifndef LEVELS_H
#define LEVELS_H
#include <list>
#include <map>
#include <set>
#include <iterator>
#include <queue>
#include <stack>
#include <assert.h>
#include "status.h"
using namespace std;
class Lv:public Status{
    private:
        set< int > hp;
        map<const int, bool> tier;
        list <Lv> l;
    public:
        Lv();
        void l1();
        void l2();
        void l3();
        void l4();
        void l5();
        void l6();
        void l7();
        void l8();
        void l9();
        void l10();
        void prntStats(){
            cout << "HP: " << ally << endl;
            cout << "Attack Power: " << aAtk << endl;
            cout << "Potions: " << pots << endl << endl;
        }
        void prntEStats(){
            cout << "HP: " << enemy << endl;
            cout << "Attack Power: " << eAtk << endl;
            cout << endl;
        }
        void prntL(){
            for(list<Lv>::iterator it = l.begin(); it!=l.end(); it++){
                Lv lv = *it;
                lv.prntStats();
            }
        }
        void prntHP(){
            cout << "Defeated Monster's Total Health Points:" << endl;
            copy(hp.begin(), hp.end(), ostream_iterator<int>(cout, "\n"));
        }
};


#endif /* LEVELS_H */

