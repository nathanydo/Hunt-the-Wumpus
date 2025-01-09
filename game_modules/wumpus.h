#ifndef WUMPUS_H
#define WUMPUS_H 

#include "../event.h"
#include <iostream>
//Wumpus Interface

using namespace std;

class Wumpus : public Event{

public:
//Default constructor
Wumpus();

/*********************************************************************
** Function: print_percept()
** Description: prints the percept assigned to Wumpus
** Parameters: none
** Pre-Conditions: character is next to wumpus tile
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