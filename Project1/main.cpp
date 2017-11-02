/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on October 23, 2017, 11:29 PM
 */


#include <cstdlib>
#include <ctime>
#include "levels.h"

using namespace std;

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));
    
    Lv game;

    game.l1();
    game.l2();
    game.l3();
    game.l4();
    game.l5();
    game.l6();
    game.l7();
    game.l8();
    game.prntHP();
    return 0;
}

