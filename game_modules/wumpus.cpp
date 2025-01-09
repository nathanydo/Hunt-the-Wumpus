#include "wumpus.h"

#include <iostream>

using namespace std;

Wumpus::Wumpus(){
    this->event_char = 'W';
}

//Wumpus Implementation

void Wumpus::print_percept(){
    cout << "You smell a terrible stench" << endl;
}

void Wumpus::call_event(){
    cout << endl << endl <<  "Oh no! You've walked into the Wumpus's Cave!" << endl
         << "The Wumpus has awoken! It eats the player!";
}
