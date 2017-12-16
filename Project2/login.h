
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
#ifndef LOGIN_H
#define LOGIN_H

class Login{
    protected:
        string name;
        unsigned int password;
        unsigned int pw;
    public:
        Login();
        void read();
        string getName(){
            return name;
        }

};


#endif /* LOGIN_H */

