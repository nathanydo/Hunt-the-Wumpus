#include "bats.h"

#include <iostream>

using namespace std;

//Bats Implementation

Bats::Bats(){
    this->event_char = 'B';
}

void Bats::print_percept(){
    cout << "You here wings flapping" << endl;
}

void Bats::call_event(){
    cout << endl << endl << "You've encountered Super Bats!" << endl
         << "You're movements are opposite for 5 turns" << endl;
}