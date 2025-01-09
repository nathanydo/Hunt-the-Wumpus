#ifndef EVENT_H
#define EVENT_H 

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event
{

protected:
char event_char;

public:

//Default constructor
Event();

/*********************************************************************
** Function: get_event_char()
** Description: returns the event_char member
** Parameters: none
** Pre-Conditions: event_char is initialized
** Post-Conditions: return event_char assigned to the room
*********************************************************************/ 
char get_event_char() const;

/*********************************************************************
** Function: print_percept()
** Description: a virtual function that is called when a specific event is triggered
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: prints the percept assigned to the specified event
*********************************************************************/ 
virtual void print_percept() = 0;

/*********************************************************************
** Function: call_event()
** Description: a virtual function that is called when the user triggers the event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: prints the specific event
*********************************************************************/ 
virtual void call_event() = 0;

};
#endif