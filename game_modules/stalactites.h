#ifndef STALACTITES_H
#define STALACTITES_H 

#include <iostream>
#include "../event.h"

using namespace std;
//Stalactites Interface

class Stal : public Event{

public:

//Constructor
Stal();

/*********************************************************************
** Function: print_percept()
** Description: prints the percept assigned to Stalactites
** Parameters: none
** Pre-Conditions: character is next to Stalactites tile
** Post-Conditions: prints out warning
*********************************************************************/ 
void print_percept();

/*********************************************************************
** Function: call_event()
** Description: prints the triggered event
** Parameters: none
** Pre-Conditions: character is on event tile
** Post-Conditions: print out event
*********************************************************************/ 
void call_event();
};
#endif
