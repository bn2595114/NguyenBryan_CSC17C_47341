
#include <iostream>
#include <string>
#include <cstdlib>

#include "levels.h"
using namespace std;
Lv::Lv(){
    tier[1]=false;
    tier[2]=false;
    tier[3]=false;
    tier[4]=false;
    tier[5]=false;
    tier[6]=false;
    tier[7]=false;
    tier[8]=false;
    mon.push("Goblin");
    mon.push("Zombie");
    mon.push("Sand Rat");
    mon.push("Wolf");
    mon.push("Tiger");
    mon.push("Boar");
    mon.push("Dragon");
    mon.push("Baboon");
    monster.push("Goblin");
    monster.push("Zombie");
    monster.push("Sand Rat");
    monster.push("Wolf");
    monster.push("Tiger");
    monster.push("Boar");
    monster.push("Dragon");
    monster.push("Baboon");
    enemy=0;
    ally=0;
    pots=0;
}

void Lv::l1(){
    assert(mon.front() == "Goblin");
    mon.pop();
    assert(monster.size()==8);
    monster.pop();
    cout << "Entered Level One! " << endl;
    char reply;
    cout << "A wild goblin has appeared! " << endl;
    cout << "Ready to battle? (y/n)" << endl;
    cin >> reply;
    reply = tolower(reply);
    while((reply!='y')){
        if(tolower(reply=='n')){
            cout << "You have exited the game" << endl;
            break;
        }
        cout << "Invalid response. Please enter a valid response: " << endl;
        cin >> reply;
        reply=tolower(reply);
    }
   
    if(reply == 'y'){
        cout << endl;
        setEHP(10); //Enemy HP
        setAHP(100); // Ally HP
        hp.insert(10);
        char cont=' ';
        cout << "Engaged in combat." << endl;
        setAAtk(10); //Able to attack up to 10 damage
        setEAtk(3); //Able to attack up to 3 damage
        pots++;
        do{
            eDmg(); //Enemy taking damage
            cout << "You attacked for " << atk1 << " damage" << endl;
            
            aDmg(); //Ally taking damage
            cout << "The goblin attacked for " << atk2 << " damage" << endl;
            
            cout << "Your HP: " << ally << endl;
            cout << "Goblin's HP: " << enemy << endl;
            if(ally < 100 && pots>0){
                char rsp;
                cout << "Use a potion to recover 10 health? (y/n) ";
                cout << "You have " << getPot() << " potions" << endl;
                cin >> rsp;
                rsp = tolower(rsp);
                while(rsp!='y'){
                    if(tolower(rsp=='n'))
                       break;
                    cout << "Invalid response. Please enter a valid response: ";
                    cout << endl;
                    cin >> rsp;
                    cont = tolower(rsp);
                }
                if(rsp=='y'){
                    usePot();
                    cout << "You used a potion!" << endl;
                    cout << "Your HP is now " << ally << endl;
                }
            }
            if(enemy>0){
                cout << "Continue? (y/n)" << endl;
                cin >> cont;
                while(cont!='y'){
                    if(tolower(cont=='n')){
                       cout << "You have exited the game" << endl;
                       break;
                     }   
                    cout << "Invalid response. Please enter a valid response: ";
                    cout << endl;
                    cin >> cont;
                    cont = tolower(cont);
                }
            }
            if(ally==0){
                cout << "You ran out of HP. You lose!" << endl;
                break;
            }
        } while(cont=='y' && enemy>0);
        cout << endl;
        if(enemy == 0){
            cout << "The goblin has fainted!" << endl;
            gainPot();
            cout << "You leveled up! Your attack power has ";
            cout << "increased by 5!" << endl;
            setAAtk(aAtk+=5);
            Lv add;
            add.setAHP(ally);
            add.setAAtk(aAtk);
            add.setPot(pots);
            l.push_back(add);
            cout << endl;
            cout << "Viewing status progression..." << endl;
            prntL();
            tier[1]=true;
        }
        else{
            cout << "Game Over! You died!" << endl;
        }
    }
}

void Lv::l2(){
    if(tier[1]!=true)
        return;
    assert(mon.front() == "Zombie");
    mon.pop();
    assert(monster.size()==7);
    monster.pop();
    cout << "Entered Level Two! " << endl;
    char reply;
    cout << "A zombie has appeared! " << endl;
    cout << "Ready to battle? (y/n)" << endl;
    cin >> reply;
    reply = tolower(reply);
    while((reply!='y')){
        if(tolower(reply=='n')){
            cout << "You have exited the game" << endl;
            break;
        }
        cout << "Invalid response. Please enter a valid response: " << endl;
        cin >> reply;
        reply=tolower(reply);
    }
   
    if(reply == 'y'){
        cout << endl;
        setEHP(15); //Enemy HP
        hp.insert(15);
        setAHP(getAHP()); // Ally HP
        char cont=' ';
        cout << "Engaged in combat." << endl;
        setAAtk(getAAtk()); //Able to attack up to 10 damage
        setEAtk(5); //Able to attack up to 3 damage

        do{
            eDmg(); //Enemy taking damage
            cout << "You attacked for " << atk1 << " damage" << endl;
            
            aDmg(); //Ally taking damage
            cout << "The zombie attacked for " << atk2 << " damage" << endl;
            
            cout << "Your HP: " << ally << endl;
            cout << "Zombie's HP: " << enemy << endl;
            if(ally < 100 && pots>0){
                char rsp;
                cout << "Use a potion to recover 10 health? (y/n) ";
                cout << "You have " << getPot() << " potions" << endl;
                cin >> rsp;
                rsp = tolower(rsp);
                while(rsp!='y'){
                    if(tolower(rsp=='n'))
                       break;
                    cout << "Invalid response. Please enter a valid response: ";
                    cout << endl;
                    cin >> rsp;
                    cont = tolower(rsp);
                }
                if(rsp=='y'){
                    usePot();
                    cout << "You used a potion!" << endl;
                    cout << "Your HP is now " << ally << endl;
                }
            }
            if(enemy>0){
                cout << "Continue? (y/n)" << endl;
                cin >> cont;
                while(cont!='y'){
                    if(tolower(cont=='n')){
                       cout << "You have exited the game" << endl;
                       break;
                     }   
                    cout << "Invalid response. Please enter a valid response: ";
                    cout << endl;
                    cin >> cont;
                    cont = tolower(cont);
                }
            }
            if(ally==0){
                cout << "You ran out of HP. You lose!" << endl;
                break;
            }
        } while(cont=='y' && enemy>0);
        cout << endl;
        if(enemy == 0){
            cout << "The zombie has fainted!" << endl;
            gainPot();
            cout << "You leveled up! Your attack power has ";
            cout << "increased by 5!" << endl;
            setAAtk(aAtk+=5);
            Lv add;
            add.setAHP(ally);
            add.setAAtk(aAtk);
            add.setPot(pots);
            l.push_back(add);
            cout << endl;
            cout << "Viewing status progression..." << endl;
            prntL();
            tier[2]=true;
        }
        else{
            cout << "Game Over! You died!" << endl;
        }
    }
}

void Lv::l3(){
    if(tier[2]!=true)
        return;
    assert(mon.front() == "Sand Rat");
    mon.pop();
    assert(monster.size()==6);
    monster.pop();
    cout << "Entered Level Three! " << endl;
    char reply;
    cout << "A wild sand rat has appeared! " << endl;
    cout << "Ready to battle? (y/n)" << endl;
    cin >> reply;
    reply = tolower(reply);
    while((reply!='y')){
        if(tolower(reply=='n')){
            cout << "You have exited the game" << endl;
            break;
        }
        cout << "Invalid response. Please enter a valid response: " << endl;
        cin >> reply;
        reply=tolower(reply);
    }
   
    if(reply == 'y'){
        cout << endl;
        setEHP(25); //Enemy HP
        hp.insert(25);
        setAHP(getAHP()); // Ally HP
        char cont=' ';
        cout << "Engaged in combat." << endl;
        setAAtk(getAAtk()); //Able to attack up to 10 damage
        setEAtk(7); //Able to attack up to 3 damage
        do{
            eDmg(); //Enemy taking damage
            cout << "You attacked for " << atk1 << " damage" << endl;
            
            aDmg(); //Ally taking damage
            cout << "The sand rat attacked for " << atk2 << " damage" << endl;
            
            cout << "Your HP: " << ally << endl;
            cout << "Sand Rat's HP: " << enemy << endl;
            if(ally < 100 && pots>0){
                char rsp;
                cout << "Use a potion to recover 10 health? (y/n) ";
                cout << "You have " << getPot() << " potions" << endl;
                cin >> rsp;
                rsp = tolower(rsp);
                while(rsp!='y'){
                    if(tolower(rsp=='n'))
                       break;
                    cout << "Invalid response. Please enter a valid response: ";
                    cout << endl;
                    cin >> rsp;
                    cont = tolower(rsp);
                }
                if(rsp=='y'){
                    usePot();
                    cout << "You used a potion!" << endl;
                    cout << "Your HP is now " << ally << endl;
                }
            }
            if(enemy>0){
                cout << "Continue? (y/n)" << endl;
                cin >> cont;
                while(cont!='y'){
                    if(tolower(cont=='n')){
                       cout << "You have exited the game" << endl;
                       break;
                     }   
                    cout << "Invalid response. Please enter a valid response: ";
                    cout << endl;
                    cin >> cont;
                    cont = tolower(cont);
                }
            }
            if(ally==0){
                cout << "You ran out of HP. You lose!" << endl;
                break;
            }
        } while(cont=='y' && enemy>0);
        cout << endl;
        if(enemy == 0){
            cout << "The goblin has fainted!" << endl;
            gainPot();
            cout << "You leveled up! Your attack power has ";
            cout << "increased by 5!" << endl;
            setAAtk(aAtk+=5);
            Lv add;
            add.setAHP(ally);
            add.setAAtk(aAtk);
            add.setPot(pots);
            l.push_back(add);
            cout << endl;
            cout << "Viewing status progression..." << endl;
            prntL();
            tier[3]=true;
        }
        else{
            cout << "Game Over! You died!" << endl;
        }
    }
}

void Lv::l4(){
    if(tier[3]!=true)
        return;
    assert(mon.front() == "Wolf");
    mon.pop();
    assert(monster.size()==5);
    monster.pop();
    cout << "Entered Level Four! " << endl;
    char reply;
    cout << "A Wolf has appeared! " << endl;
    cout << "Ready to battle? (y/n)" << endl;
    cin >> reply;
    reply = tolower(reply);
    while((reply!='y')){
        if(tolower(reply=='n')){
            cout << "You have exited the game" << endl;
            break;
        }
        cout << "Invalid response. Please enter a valid response: " << endl;
        cin >> reply;
        reply=tolower(reply);
    }
   
    if(reply == 'y'){
        cout << endl;
        setEHP(40); //Enemy HP
        hp.insert(40);
        setAHP(getAHP()); // Ally HP
        char cont=' ';
        cout << "Engaged in combat." << endl;
        setAAtk(getAAtk()); //Able to attack up to 10 damage
        setEAtk(9); //Able to attack up to 3 damage
        
        do{
            eDmg(); //Enemy taking damage
            cout << "You attacked for " << atk1 << " damage" << endl;
            
            aDmg(); //Ally taking damage
            cout << "The Wolf attacked for " << atk2 << " damage" << endl;
            
            cout << "Your HP: " << ally << endl;
            cout << "Wolf's HP: " << enemy << endl;
            if(ally < 100 && pots>0){
                char rsp;
                cout << "Use a potion to recover 10 health? (y/n) ";
                cout << "You have " << getPot() << " potions" << endl;
                cin >> rsp;
                rsp = tolower(rsp);
                while(rsp!='y'){
                    if(tolower(rsp=='n'))
                       break;
                    cout << "Invalid response. Please enter a valid response: ";
                    cout << endl;
                    cin >> rsp;
                    cont = tolower(rsp);
                }
                if(rsp=='y'){
                    usePot();
                    cout << "You used a potion!" << endl;
                    cout << "Your HP is now " << ally << endl;
                }
            }
            if(enemy>0){
                cout << "Continue? (y/n)" << endl;
                cin >> cont;
                while(cont!='y'){
                    if(tolower(cont=='n')){
                       cout << "You have exited the game" << endl;
                       break;
                     }   
                    cout << "Invalid response. Please enter a valid response: ";
                    cout << endl;
                    cin >> cont;
                    cont = tolower(cont);
                }
            }
            if(ally==0){
                cout << "You ran out of HP. You lose!" << endl;
                break;
            }
        } while(cont=='y' && enemy>0);
        cout << endl;
        if(enemy == 0){
            cout << "The Wolf has fainted!" << endl;
            gainPot();
            cout << "You leveled up! Your attack power has ";
            cout << "increased by 5!" << endl;
            setAAtk(aAtk+=5);
            Lv add;
            add.setAHP(ally);
            add.setAAtk(aAtk);
            add.setPot(pots);
            l.push_back(add);
            cout << endl;
            cout << "Viewing status progression..." << endl;
            prntL();
            tier[4]=true;
        }
        else{
            cout << "Game Over! You died!" << endl;
        }
    }
}

void Lv::l5(){
    if(tier[4]!=true)
        return;
    assert(mon.front() == "Tiger");
    mon.pop();
    assert(monster.size()==4);
    monster.pop();
    cout << "Entered Level Five! " << endl;
    char reply;
    cout << "A wild tiger has appeared! " << endl;
    cout << "Ready to battle? (y/n)" << endl;
    cin >> reply;
    reply = tolower(reply);
    while((reply!='y')){
        if(tolower(reply=='n')){
            cout << "You have exited the game" << endl;
            break;
        }
        cout << "Invalid response. Please enter a valid response: " << endl;
        cin >> reply;
        reply=tolower(reply);
    }
   
    if(reply == 'y'){
        cout << endl;
        setEHP(50); //Enemy HP
        hp.insert(50);
        setAHP(getAHP()); // Ally HP
        char cont=' ';
        cout << "Engaged in combat." << endl;
        setAAtk(getAAtk()); //Able to attack up to 10 damage
        setEAtk(11); //Able to attack up to 3 damage
 
        do{
            eDmg(); //Enemy taking damage
            cout << "You attacked for " << atk1 << " damage" << endl;
            
            aDmg(); //Ally taking damage
            cout << "The tiger attacked for " << atk2 << " damage" << endl;
            
            cout << "Your HP: " << ally << endl;
            cout << "Tiger's HP: " << enemy << endl;
            if(ally < 100 && pots>0){
                char rsp;
                cout << "Use a potion to recover 10 health? (y/n) ";
                cout << "You have " << getPot() << " potions" << endl;
                cin >> rsp;
                rsp = tolower(rsp);
                while(rsp!='y'){
                    if(tolower(rsp=='n'))
                       break;
                    cout << "Invalid response. Please enter a valid response: ";
                    cout << endl;
                    cin >> rsp;
                    cont = tolower(rsp);
                }
                if(rsp=='y'){
                    usePot();
                    cout << "You used a potion!" << endl;
                    cout << "Your HP is now " << ally << endl;
                }
            }
            if(enemy>0){
                cout << "Continue? (y/n)" << endl;
                cin >> cont;
                while(cont!='y'){
                    if(tolower(cont=='n')){
                       cout << "You have exited the game" << endl;
                       break;
                     }   
                    cout << "Invalid response. Please enter a valid response: ";
                    cout << endl;
                    cin >> cont;
                    cont = tolower(cont);
                }
            }
            if(ally==0){
                cout << "You ran out of HP. You lose!" << endl;
                break;
            }
        } while(cont=='y' && enemy>0);
        cout << endl;
        if(enemy == 0){
            cout << "The tiger has fainted!" << endl;
            gainPot();
            cout << "You leveled up! Your attack power has ";
            cout << "increased by 5!" << endl;
            setAAtk(aAtk+=5);
            Lv add;
            add.setAHP(ally);
            add.setAAtk(aAtk);
            add.setPot(pots);
            l.push_back(add);
            cout << endl;
            cout << "Viewing your status progression..." << endl;
            prntL();
            tier[5]=true;
        }
        else{
            cout << "Game Over! You died!" << endl;
        }
    }
}

void Lv::l6(){
    if(tier[5]!=true)
        return;
    assert(mon.front() == "Boar");
    mon.pop();
    assert(monster.size()==3);
    monster.pop();
    cout << "Entered Level Six! " << endl;
    char reply;
    cout << "A wild boar has appeared! " << endl;
    cout << "Ready to battle? (y/n)" << endl;
    cin >> reply;
    reply = tolower(reply);
    while((reply!='y')){
        if(tolower(reply=='n')){
            cout << "You have exited the game" << endl;
            break;
        }
        cout << "Invalid response. Please enter a valid response: " << endl;
        cin >> reply;
        reply=tolower(reply);
    }
   
    if(reply == 'y'){
        cout << endl;
        setEHP(67); //Enemy HP
        hp.insert(67);
        setAHP(getAHP()); // Ally HP
        char cont=' ';
        cout << "Engaged in combat." << endl;
        setAAtk(getAAtk()); //Able to attack up to 10 damage
        setEAtk(14); //Able to attack up to 3 damage
 
        do{
            eDmg(); //Enemy taking damage
            cout << "You attacked for " << atk1 << " damage" << endl;
            
            aDmg(); //Ally taking damage
            cout << "The boar attacked for " << atk2 << " damage" << endl;
            
            cout << "Your HP: " << ally << endl;
            cout << "Boar's HP: " << enemy << endl;
            if(ally < 100 && pots>0){
                char rsp;
                cout << "Use a potion to recover 10 health? (y/n) ";
                cout << "You have " << getPot() << " potions" << endl;
                cin >> rsp;
                rsp = tolower(rsp);
                while(rsp!='y'){
                    if(tolower(rsp=='n'))
                       break;
                    cout << "Invalid response. Please enter a valid response: ";
                    cout << endl;
                    cin >> rsp;
                    cont = tolower(rsp);
                }
                if(rsp=='y'){
                    usePot();
                    cout << "You used a potion!" << endl;
                    cout << "Your HP is now " << ally << endl;
                }
            }
            if(enemy>0){
                cout << "Continue? (y/n)" << endl;
                cin >> cont;
                while(cont!='y'){
                    if(tolower(cont=='n')){
                       cout << "You have exited the game" << endl;
                       break;
                     }   
                    cout << "Invalid response. Please enter a valid response: ";
                    cout << endl;
                    cin >> cont;
                    cont = tolower(cont);
                }
            }
            if(ally==0){
                cout << "You ran out of HP. You lose!" << endl;
                break;
            }
        } while(cont=='y' && enemy>0);
        cout << endl;
        if(enemy == 0){
            cout << "The boar has fainted!" << endl;
            gainPot();
            cout << "You leveled up! Your attack power has ";
            cout << "increased by 5!" << endl;
            setAAtk(aAtk+=5);
            Lv add;
            add.setAHP(ally);
            add.setAAtk(aAtk);
            add.setPot(pots);
            l.push_back(add);
            cout << endl;
            cout << "Viewing your status progression..." << endl;
            prntL();
            tier[6]=true;
        }
        else{
            cout << "Game Over! You died!" << endl;
        }
    }
}

void Lv::l7(){
    if(tier[6]!=true)
        return;
    assert(mon.front() == "Dragon");
    mon.pop();
    assert(monster.size()==2);
    monster.pop();
    cout << "Entered Level Seven! " << endl;
    char reply;
    cout << "A wild dragon has appeared! " << endl;
    cout << "Ready to battle? (y/n)" << endl;
    cin >> reply;
    reply = tolower(reply);
    while((reply!='y')){
        if(tolower(reply=='n')){
            cout << "You have exited the game" << endl;
            break;
        }
        cout << "Invalid response. Please enter a valid response: " << endl;
        cin >> reply;
        reply=tolower(reply);
    }
   
    if(reply == 'y'){
        cout << endl;
        setEHP(77); //Enemy HP
        hp.insert(77);
        setAHP(getAHP()); // Ally HP
        char cont=' ';
        cout << "Engaged in combat." << endl;
        setAAtk(getAAtk()); //Able to attack up to 10 damage
        setEAtk(18); //Able to attack up to 3 damage
 
        do{
            eDmg(); //Enemy taking damage
            cout << "You attacked for " << atk1 << " damage" << endl;
            
            aDmg(); //Ally taking damage
            cout << "The dragon attacked for " << atk2 << " damage" << endl;
            
            cout << "Your HP: " << ally << endl;
            cout << "Dragon's HP: " << enemy << endl;
            if(ally < 100 && pots>0){
                char rsp;
                cout << "Use a potion to recover 10 health? (y/n) ";
                cout << "You have " << getPot() << " potions" << endl;
                cin >> rsp;
                rsp = tolower(rsp);
                while(rsp!='y'){
                    if(tolower(rsp=='n'))
                       break;
                    cout << "Invalid response. Please enter a valid response: ";
                    cout << endl;
                    cin >> rsp;
                    cont = tolower(rsp);
                }
                if(rsp=='y'){
                    usePot();
                    cout << "You used a potion!" << endl;
                    cout << "Your HP is now " << ally << endl;
                }
            }
            if(enemy>0){
                cout << "Continue? (y/n)" << endl;
                cin >> cont;
                while(cont!='y'){
                    if(tolower(cont=='n')){
                       cout << "You have exited the game" << endl;
                       break;
                     }   
                    cout << "Invalid response. Please enter a valid response: ";
                    cout << endl;
                    cin >> cont;
                    cont = tolower(cont);
                }
            }
            if(ally==0){
                cout << "You ran out of HP. You lose!" << endl;
                break;
            }
        } while(cont=='y' && enemy>0);
        cout << endl;
        if(enemy == 0){
            cout << "The dragon has fainted!" << endl;
            gainPot();
            cout << "You leveled up! Your attack power has ";
            cout << "increased by 5!" << endl;
            setAAtk(aAtk+=5);
            Lv add;
            add.setAHP(ally);
            add.setAAtk(aAtk);
            add.setPot(pots);
            l.push_back(add);
            cout << endl;
            cout << "Viewing your status progression..." << endl;
            prntL();
            tier[7]=true;
        }
        else{
            cout << "Game Over! You died!" << endl;
        }
    }
}

void Lv::l8(){
    if(tier[7]!=true)
        return;
    assert(mon.front() == "Baboon");
    mon.pop();
    assert(monster.size()==1);
    monster.pop();
    cout << "Entered Level Eight! " << endl;
    char reply;
    cout << "A wild baboon has appeared! " << endl;
    cout << "Ready to battle? (y/n)" << endl;
    cin >> reply;
    reply = tolower(reply);
    while((reply!='y')){
        if(tolower(reply=='n')){
            cout << "You have exited the game" << endl;
            break;
        }
        cout << "Invalid response. Please enter a valid response: " << endl;
        cin >> reply;
        reply=tolower(reply);
    }
   
    if(reply == 'y'){
        cout << endl;
        setEHP(84); //Enemy HP
        hp.insert(84);
        setAHP(getAHP()); // Ally HP
        char cont=' ';
        cout << "Engaged in combat." << endl;
        setAAtk(getAAtk()); //Able to attack up to 10 damage
        setEAtk(20); //Able to attack up to 3 damage
 
        do{
            eDmg(); //Enemy taking damage
            cout << "You attacked for " << atk1 << " damage" << endl;
            
            aDmg(); //Ally taking damage
            cout << "The baboon attacked for " << atk2 << " damage" << endl;
            
            cout << "Your HP: " << ally << endl;
            cout << "Baboon's HP: " << enemy << endl;
            if(ally < 100 && pots>0){
                char rsp;
                cout << "Use a potion to recover 10 health? (y/n) ";
                cout << "You have " << getPot() << " potions" << endl;
                cin >> rsp;
                rsp = tolower(rsp);
                while(rsp!='y'){
                    if(tolower(rsp=='n'))
                       break;
                    cout << "Invalid response. Please enter a valid response: ";
                    cout << endl;
                    cin >> rsp;
                    cont = tolower(rsp);
                }
                if(rsp=='y'){
                    usePot();
                    cout << "You used a potion!" << endl;
                    cout << "Your HP is now " << ally << endl;
                }
            }
            if(enemy>0){
                cout << "Continue? (y/n)" << endl;
                cin >> cont;
                while(cont!='y'){
                    if(tolower(cont=='n')){
                       cout << "You have exited the game" << endl;
                       break;
                     }   
                    cout << "Invalid response. Please enter a valid response: ";
                    cout << endl;
                    cin >> cont;
                    cont = tolower(cont);
                }
            }
            if(ally==0){
                cout << "You ran out of HP. You lose!" << endl;
                break;
            }
        } while(cont=='y' && enemy>0);
        cout << endl;
        if(enemy == 0){
            cout << "The baboon has fainted!" << endl;
            gainPot();
            cout << "You leveled up! Your attack power has ";
            cout << "increased by 5!" << endl;
            setAAtk(aAtk+=5);
            Lv add;
            add.setAHP(ally);
            add.setAAtk(aAtk);
            add.setPot(pots);
            l.push_back(add);
            cout << endl;
            cout << "Viewing your status progression..." << endl;
            prntL();
            tier[8]=true;
        }
        else{
            cout << "Game Over! You died!" << endl;
        }
    }
}
