#ifndef ROOM_H
#define ROOM_H 

#include "event.h"
#include <iostream>

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private: 

Event* e;
bool has_player;

	
public:
//Default Constructor
Room();

//Destructor
~Room();

//Setter for has_player member
void set_has_player(const bool);

//Getter for has_player member
bool get_has_player() const;

/*********************************************************************
** Function: make_room_emtpy()
** Description: deletes the event in the room and sets it to null
** Parameters: none
** Pre-Conditions: room has an event
** Post-Conditions: room has nothing
*********************************************************************/ 
void make_room_empty();

/*********************************************************************
** Function: is_empty()
** Description: checks to see if the room has an event
** Parameters: none
** Pre-Conditions: rooms is either nullptr or has event
** Post-Conditions: return true if room has no event, false if has event
*********************************************************************/ 
bool is_empty() const;

/*********************************************************************
** Function: assign()
** Description: assign an event to a room
** Parameters: Event* - event poitner that goes to a certain event
** Pre-Conditions: room has been created
** Post-Conditions: room has an event
*********************************************************************/ 
void assign(Event*);

/*********************************************************************
** Function: get_char()
** Description: gets the char assigned to the room if it has event
** Parameters: none
** Pre-Conditions: room is created and has an event character
** Post-Conditions: returns the event character assigned to the room
*********************************************************************/ 
char get_char() const;

/*********************************************************************
** Function: print_warnings()
** Description: prints the percept assigned to the room
** Parameters: bool event - if event is false, returns the percept assigned to that event
** Pre-Conditions: Rooms are assigned with events
** Post-Conditions: returns the warning to that event
*********************************************************************/ 
void print_warnings(bool);

/*********************************************************************
** Function: events()
** Description: calls the print results of the event the user hits
** Parameters: none
** Pre-Conditions: character is in a room with an event
** Post-Conditions: calls the event function assigned to each event
*********************************************************************/ 
void events();



};

#endif