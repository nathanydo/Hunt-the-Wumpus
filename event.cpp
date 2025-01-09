#include "event.h"

#include <iostream>

using namespace std;

//Event Implementation

Event::Event(){
    this->event_char = ' ';
}

char Event::get_event_char() const{
    return event_char;
}


