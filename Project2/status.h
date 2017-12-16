/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   status.h
 * Author: Bryan
 *
 * Created on October 27, 2017, 9:00 PM
 */

#ifndef STATUS_H
#define STATUS_H
#include <iostream>
#include "login.h"
#include "mergeSort.h"
using namespace std;
class Status{
    protected:
        int ally, enemy, pots, aAtk, eAtk, atk1, atk2;
        queue<string> mon; //monster
        stack<string> monster; //monster's attack
    public:
        Status(){
            ally=0;
            enemy=0;
            pots=0;
            aAtk=0;
            eAtk=0;
        }
        void setEHP(int h){
            enemy=h;
        }
        int getEHP(){
            return enemy;
        }
        void setEAtk(int a){
            eAtk=a;
        }
        void eDmg(){
            atk1=rand()%aAtk+1;
            enemy-=atk1;
            if(enemy<0) enemy=0;
        }
        void setAHP(int h){
            ally=h;
        }
        int getAHP(){
            return ally;
        }
        void setAAtk(int a){
            aAtk=a;
        }
        int getAAtk(){
            return aAtk;
        }
        void aDmg(){
            atk2=rand()%eAtk+1;
            ally-=atk2;
            if(ally<0) ally=0;
        }
        void setPot(int p){
            pots=p;
        }
        void gainPot(){
            int p = rand()%10;
            if(p<5){ cout << "Enemy dropped a potion!" << endl; pots++;}
            else cout << "Enemy dropped nothing" << endl;
        }
        void usePot(){
            ally+=10;
            pots--;
            if(ally>100) ally=100;
        }
        int getPot(){
            return pots;
        } 
        
};


#endif /* STATUS_H */

