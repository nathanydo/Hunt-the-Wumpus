#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation

Stal::Stal(){
    this->event_char = 'S';
}

void Stal::print_percept(){
    cout << "You hear water dripping" << endl;
}

void Stal::call_event(){
    cout << endl << endl << "You've entered a room of Stalactites!";
}