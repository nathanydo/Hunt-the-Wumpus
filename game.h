#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"

using namespace std;

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:
	vector<vector<Room> > board;
	//other member variables:
	int length; 			//length of the board
	int width;  			//width of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not


	//feel free to add more variables...
	bool holding_gold;
	int player_row_idx;
	int player_col_idx;
	int rope_row_idx;
	int rope_col_idx;
	int wumpus_row_idx;
	int wumpus_col_idx;

	int bats;
	bool stal;
	bool wumpus;
	bool armour;
	int armour_hits;


public:

	//suggested functions:
//Default Constructor
	Game();

//Destructor
	~Game();

/*********************************************************************
** Function: Game::set_up()
** Description: Sets up the game by putting the events and character in randoms positions in 
** the given grid size the user puts.
** Parameters: int l - length given by user, int w - width given by user.
** Pre-Conditions: User has determeind length and width of game
** Post-Conditions: Returns where each element is placed randomly along with the player on the game
*********************************************************************/
	void set_up(int, int);

/*********************************************************************
** Function: Game::display_game() const
** Description: Displays the 2D vector that holds the game.
** Parameters: none
** Pre-Conditions: the function set_up needs to be called before this function
** Post-Conditions: displays the game in the terminal
*********************************************************************/
	void display_game() const;

/*********************************************************************
** Function: Game::check_win()
** Description: Checks too see if the user has won/lost
** Parameters: none
** Pre-Conditions: The user has performed his/hers action.
** Post-Conditions: Prints if the user has won/lost the game.
*********************************************************************/
	bool check_win();

/*********************************************************************
** Function: Game::get_dir()
** Description: gets the direction of the arrow to be fire at
** Parameters: none
** Pre-Conditions: It is the users turn to move, firing arrow will be one option.
** Post-Conditions: returns the dir of where the user wants to shoot the arrow
*********************************************************************/ 
	char get_dir();

/*********************************************************************
** Function: Game::armour_hits()
** Description: if player has armour, saves the player from 2 hits
** Parameters: none
** Pre-Conditions: player needs to have armour
** Post-Conditions: decrements armout hits by 1 till it is 0
*********************************************************************/ 
	void armour_hit();

/*********************************************************************
** Function: Game::wumpus_move()
** Description: If the arrow misses the wumpus, wumpus has a chance to move.
** Parameters: none
** Pre-Conditions: arrow has been shot and missed
** Post-Conditions: wumpus locations is somwhere different in the 2d array
*********************************************************************/ 
	void wumpus_move();

/*********************************************************************
** Function: Game::fire_arrow()
** Description: fires the arrow in a direction
** Parameters: none
** Pre-Conditions: user selects to fire an arrow
** Post-Conditions: fires arrow in a direction
*********************************************************************/ 
	void fire_arrow();

/*********************************************************************
** Function: Game::fire()
** Description: fires the arrow in a direction
** Parameters: char dir - stores the users input for direction of arrow
** Pre-Conditions: fire_arrow is called
** Post-Conditions: fires an arrow in a direction
*********************************************************************/ 
	void fire(char);

/*********************************************************************
** Function: Game::fire_up()
** Description: fires the arrow up
** Parameters: none
** Pre-Conditions: User decides which direction to shoot arrow
** Post-Conditions: an arrow is shot up, if hits wumpus, returns wumpus true
*********************************************************************/ 
	void fire_up();

/*********************************************************************
** Function: Game::fire_down()
** Description: fires the arrow down
** Parameters: none
** Pre-Conditions: User decides which direction to shoot arrow
** Post-Conditions: an arrow is shot down, if hits wumpus, returns wumpus true
*********************************************************************/ 
	void fire_down();

/*********************************************************************
** Function: Game::fire_left()
** Description: fires the arrow left
** Parameters: none
** Pre-Conditions: User decides which direction to shoot arrow
** Post-Conditions: an arrow is shot left, if hits wumpus, returns wumpus true
*********************************************************************/ 
	void fire_left();

/*********************************************************************
** Function: Game::fire_right()
** Description: fires the arrow right
** Parameters: none
** Pre-Conditions: User decides which direction to shoot arrow
** Post-Conditions: an arrow is shot right, if hits wumpus, returns wumpus true
*********************************************************************/ 
	void fire_right();

/*********************************************************************
** Function: Game::move_up()
** Description: Lets the user move the character in the game up a square
** Parameters: none
** Pre-Conditions: Game has been printed to the user and user turn is current.
** Post-Conditions: moves the character up.
*********************************************************************/
	void move_up();

/*********************************************************************
** Function: Game::move_down()
** Description: Lets the user move the character in the game down a square
** Parameters: none
** Pre-Conditions: Game has been printed to the user and user turn is current.
** Post-Conditions: moves the character down.
*********************************************************************/
	void move_down();

/*********************************************************************
** Function: Game::move_left()
** Description: Lets the user move the character in the game left a square
** Parameters: none
** Pre-Conditions: Game has been printed to the user and user turn is current.
** Post-Conditions: moves the character left.
*********************************************************************/
	void move_left();

/*********************************************************************
** Function: Game::move_right()
** Description: Lets the user move the character in the game right a square
** Parameters: none
** Pre-Conditions: Game has been printed to the user and user turn is current.
** Post-Conditions: moves the character right.
*********************************************************************/
	void move_right();
/*********************************************************************
** Function: Game::move()
** Description: Handles the players action when it is the users turn
** Parameters: char c - users input for what to do
** Pre-Conditions: user has to put a valid input
** Post-Conditions: returns the decisions to the code from user
*********************************************************************/ 
	void move(char);

/*********************************************************************
** Function: Game::bat_move()
** Description: If user hits a bat, the users movements are opposite for 5 turns
** Parameters: char c - users input for movement
** Pre-Conditions: user has to hit a bat
** Post-Conditions: prints the opposite movement the user puts.
*********************************************************************/ 
	void bat_move(char);

/*********************************************************************
** Function: Game::get_input()
** Description: Gets the users input and returns it to functions
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: User input is stored in char c
*********************************************************************/ 
	char get_input();

/*********************************************************************
** Function: Game::play_game()
** Description: This function calls the functions in a specific order to play the game
** Parameters: int w - users input for width, int l - users input for length, bool d - users input for debug mode
** Pre-Conditions: User has inputed their size of the game and if they want to view debug mode
** Post-Conditions:prints the game
*********************************************************************/ 
	void play_game(int, int, bool);

	//feel free (and you will need) to add more functions...

/*********************************************************************
** Function: Game::debug_print()
** Description: If user chooses debug mode, prints all event locations on the game
** Parameters: none
** Pre-Conditions: debug mode needs to be chosen
** Post-Conditions: prints the events within the game
*********************************************************************/ 
	void debug_print(char) const;

/*********************************************************************
** Function: Game::print_percepts()
** Description: Prints the perecepts of each event when the user is at a square next to them.
** Parameters: char - the character assigned to the event
** Pre-Conditions: character index has to be next to an event.
** Post-Conditions: prints out the percept associated to the event.
*********************************************************************/ 
	void print_percepts();

/*********************************************************************
** Function: Game::hit_event()
** Description: Calls for whatever event the user hits.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: user gets hit with an event
*********************************************************************/ 
	void hit_event();





};
#endif