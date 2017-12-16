
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "login.h"
#include "GeneralHashFunctions.h"

Login::Login(){

}

void Login::read(){
    
    string hash;
    cout << "Enter (new) username: ";
    cin >> name;
    cout << "Enter (new) password: ";
    cin >> hash;
    pw = RSHash(hash);

    string test;
    stringstream s;
    string x;
    string file = name;
    ifstream look;
    ofstream write, players;
    if(look){
        look.open(file.c_str());
     
            getline(look,x);
            if(x.empty()){
                cout << "Account not found. Creating account..." << endl;
                write.open(file.c_str());
                write << pw << endl;
                write.close();
                players.close();
            }
            else{
            s << x;
            s >> password;
        
            if(pw == password){
                cout << "You have logged in." << endl << endl;
            }
            else{
                while(pw != password){
                    cout << "Invalid password. Re-enter your password ";
                    cout << "or enter -1 to exit." << endl;
                    cin >> test;
                    if(test == "-1")
                        exit(0);
                    pw = RSHash(test);
                    cout << endl << endl;
                    if(pw == password)
                        cout << "You have logged in" << endl;
                }
            }
        look.close();
         }
    }
}