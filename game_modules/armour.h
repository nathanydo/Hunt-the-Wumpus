#ifndef ARMOUR_H
#define ARMOUR_H


#include "../event.h"
#include <iostream>


class Armour : public Event{

public:

//Default Constructor
Armour();

/*********************************************************************
** Function: print_percept()
** Description: prints the percept assigned to Armour
** Parameters: none
** Pre-Conditions: character is next to Armour tile
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