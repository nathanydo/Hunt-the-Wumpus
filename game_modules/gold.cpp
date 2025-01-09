#include "gold.h"
#include "../event.h"

#include <iostream>

using namespace std;

//Gold Implementation

Gold::Gold(){
    this->event_char = 'G';
}


char Gold::event_chara(){
    return 'G';
}

void Gold::print_percept(){
    cout << "You see a glimmer nearby" << endl;
}

void Gold::call_event(){
   this->event_char = ' ';
   cout << endl << endl << "You've picked up the gold!" << endl;
}
