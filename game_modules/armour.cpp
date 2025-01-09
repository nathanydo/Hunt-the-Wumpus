#include "armour.h"

#include <iostream>

using namespace std;

Armour::Armour(){
    this->event_char = 'A';
}

void Armour::print_percept(){
    cout << "You feel the power" << endl;
}

void Armour::call_event(){
    cout << endl << endl << "You've encoutnered Battle Armour!" << endl
         << "You feel you can take an extra life" << endl;
}