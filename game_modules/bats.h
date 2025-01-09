#ifndef BATS_H
#define BATS_H 

#include "../event.h"
#include <iostream>
//Bats Interface

class Bats : public Event{
private:

public:

//Constructor
Bats();

/*********************************************************************
** Function: print_percept()
** Description: prints the percept assigned to Bats
** Parameters: none
** Pre-Conditions: character is next to Bats tile
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