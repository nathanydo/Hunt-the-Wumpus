#ifndef GOLD_H
#define GOLD_H 

#include <iostream>
#include <string>
#include "../event.h"
//Gold Interface

class Gold : public Event{

public:

//Constructor
    Gold();

/*********************************************************************
** Function: event_chara()
** Description: returns the gold event character
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return 'G'
*********************************************************************/ 
    char event_chara();

/*********************************************************************
** Function: print_percept()
** Description: prints the percept assigned to Gold
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