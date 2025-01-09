#include "game.h"
#include "./game_modules/gold.h"
#include "./game_modules/stalactites.h"
#include "./game_modules/bats.h"
#include "./game_modules/wumpus.h"
#include "./game_modules/armour.h"

#include <iostream>

using namespace std;

//Game Implementation

//Constructor
Game::Game(){
	//Game constructor
	//Your code here:
	this->length = 5;
	this->width = 5;
	this->num_arrows = 3;
	this->debug_view = false;
	this->holding_gold = false;
	this->wumpus = false;
	this->bats = 0;
	this->stal = false;
	this->armour = false;
	this->armour_hits = -1;

}

//Destructor
Game::~Game(){
	//Game destructor
	//Your code here:

}


void Game::set_up(int l, int w){
	//set up the game
	this->length = l;
	this->width = w;

	this->num_arrows = 3; 	//start with 3 arrows

	// Finish the remaining...
	//Your code here:
	for(int i = 0; i < l; i++){
		vector<Room> temp;
		for(int j = 0; j < w; j++){
			Room m;
			temp.push_back(m);
		}
		this->board.push_back(temp);
	}
	// Create the game board: 2D vector of Room objects

	// randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold)
	// into the board

	for (int i = 0; i < 8; i++){
		int row_idx = -1;
		int col_idx = -1;
		do{
			row_idx = rand() % length;
			col_idx = rand() % width;
		}
		while(!this->board[row_idx][col_idx].is_empty());
	
	if (i == 0){
		this->board[row_idx][col_idx].assign(new Gold());
	}
	else if (i == 1){
		this->board[row_idx][col_idx].assign(new Wumpus());
		this->wumpus_row_idx = row_idx;
		this->wumpus_col_idx = col_idx;
	}
	else if (i == 2 || i == 3){
		this->board[row_idx][col_idx].assign(new Bats());
	}
	else if(i == 4 || i == 5){
		this->board[row_idx][col_idx].assign(new Stal());
	}
	else if(i == 6){
		this->board[row_idx][col_idx].set_has_player(true);
		this->player_row_idx = row_idx;
		this->player_col_idx = col_idx;
		this->rope_row_idx = row_idx;
		this->rope_col_idx = col_idx;
	}
	else if(i == 7){
		this->board[row_idx][col_idx].assign(new Armour());
	}
	}

}



void Game::display_game() const{
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;
	
	string line = "";
	for (int i = 0; i < this->width; ++i)
		line += "-----";

	for (int i = 0; i < this->length; ++i)
	{
		cout << line << endl;
		for (int j = 0; j < this->width; ++j)
		{
			//The first char indicates whether there is a player in that room or not
			//if the room does not have the player, print space " "
			if(this->board[i][j].get_has_player() == false){
				cout << " ";
				}
			//else, print "*"
			else {
				cout << "*";
			}
			//Fix the following
			//cout << " ";
			

			//The next two chars indicate the event in the room
			//if the room does not have an event, print "  ||" (2 spaces + ||)
			

			if(this->debug_view == true){
				char temp;
				temp = this->board[i][j].get_char();
				debug_print(temp);
			}
			else{
				cout << "  ||";
			}

	
			//else, 
				//if debug_view is true
					//print the corresponding char of the event
				//else
					//print " " (1 space)
				// print " ||" (1 space + ||)

			//Fix the following...
		}
		cout << endl;
	}
	cout << line << endl;

	//example output (when finished): 
	// --------------------
	//  B || G || B ||   ||
	// --------------------
	//    || W ||   || S ||
	// --------------------   
	//    ||   ||   || S ||
	// --------------------   
	// *  ||   ||   ||   ||
	// --------------------
}

bool Game::check_win(){
	//check if game over/win
	//Your code here:
	if(((this->player_row_idx == this->rope_row_idx) && (this->player_col_idx == this->rope_row_idx)) && this->holding_gold == true){ //chekcs to see if the player is at the starting point and is holding gold
		cout << endl << "You escaped with the gold!" << endl
			 << "You Win!";
		return true;
	}
	
	if(this->stal == true){
		cout << endl << "You died by a stalactite" << endl
			 << "Game over!" << endl;
		return true;
	}

	if(this->wumpus == true){
		return true;
	}
	//cout << "Game::check_win() is not implemented..." << endl;
	return false;
}


void Game::armour_hit(){
		if(this->armour_hits == 1){
			this->armour = false;
			cout << endl << "Your armour has broken!" << endl
				 << "Your next hit will not be protected" << endl;
		}
		else{
			this->armour_hits--;
			cout << endl << "The armour has saved you from death!" << endl 
				 <<"it has " << this->armour_hits << " hit left until it breaks!";
		}
	}

void Game::move_up() {
	//move player up
	//Your code here:
	if(this->player_row_idx == 0){
		cout << endl << "Player cannot go up." << endl << endl;
		return;
	}
	else{
		this->board[this->player_row_idx][this->player_col_idx].set_has_player(false);  //sets the present index to not have player
		this->board[this->player_row_idx - 1][this->player_col_idx].set_has_player(true);  //sets the next index on the row to have player
																							// All movement functions are the same.
		this->player_row_idx = this->player_row_idx - 1;
	}

	return;

}


void Game::move_down() {
	//move player down
	//Your code here:
	if(this->player_row_idx == this->length - 1){
		cout << endl << "Player cannot go down." << endl << endl;
		return;
	}
	else{
		this->board[this->player_row_idx][this->player_col_idx].set_has_player(false);		
		this->board[this->player_row_idx + 1][this->player_col_idx].set_has_player(true);
		
		this->player_row_idx = this->player_row_idx + 1;
	}

	return;
}


void Game::move_left() {
	//move player left
	//Your code here:
	if(this->player_col_idx == 0){
		cout << endl << "Player cannot go left." << endl << endl;
		return;
	}
	else{
		
		this->board[this->player_row_idx][this->player_col_idx].set_has_player(false);
		this->board[this->player_row_idx][this->player_col_idx - 1].set_has_player(true);
		
		this->player_col_idx = this->player_col_idx - 1;
	}

	return;

}


void Game::move_right() {
	//move player right
	//Your code here:
	if(this->player_col_idx == this->width - 1){
		cout << endl << "Player cannot go right." << endl << endl;
		return;
	}
	else{
		
		this->board[this->player_row_idx][this->player_col_idx].set_has_player(false);
		this->board[this->player_row_idx][this->player_col_idx + 1].set_has_player(true);
		
		this->player_col_idx = this->player_col_idx + 1;
	}

	return;
}


char Game::get_dir(){
	//get direction of arrow:
	char dir;
	//Note: error checking is needed!! 
	//Your code here:
	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	

	cout << "Enter direction: " << endl;
	while(!(cin >> dir) || (dir != 'w' && dir != 'a' && dir != 's' && dir != 'd' && dir != 'f')){ //checks to see if input is valid
	cout << endl << "Invalid Direction: ";
	cin.clear();
	cin.ignore(256, '\n');
	}
	return dir;
}



void Game::wumpus_move(){
	//after a missed arrow, 75% chance that the wumpus is moved to a different room

	//How to get 75%? 
	//Hint: generate a random number from 0-3, if the number is not 0, then move

	//Your code here:
	int move = rand() % 4; //create a random number between 0-3
	int row_idx = -1;
	int col_idx = -1;

	if(move != 0){ //to create 75% chance, if not 0 move the wumpus
	do{
		row_idx = rand() % length;
		col_idx = rand() % width;
	}while(!this->board[row_idx][col_idx].is_empty());
	this->board[wumpus_row_idx][wumpus_col_idx].make_room_empty();
	this->board[row_idx][col_idx].assign(new Wumpus());
	this->wumpus_row_idx = row_idx;
	this->wumpus_col_idx = col_idx;
	cout << "The Wumpus has relocated!" << endl;
	}
	else;
	return;
}


void Game::fire_arrow(){
	// The player may fire arrow...
	char dir = get_dir();
	//Your code here:
if(this->num_arrows == 0){
	cout << endl << "You have no arrows left!" << endl;
	return;
}
	Game::fire(dir);
	if(this->wumpus == true){
	cout << endl << "The arrow has hit the Wumpus!" << endl
		 << "You win!";
	}
	else{
		cout << endl << "The arrow has missed the Wumpus!" << endl;
		Game::wumpus_move();  //function moves wumpus if the arrow misses
		this->num_arrows--;
	}
	return;
}


void Game::fire(char dir){
	switch(dir){
			case 'w':
				Game::fire_up();
				break;
			case 's':
				Game::fire_down();
				break;
			case 'a':
				Game::fire_left();
				break;
			case 'd':
				Game::fire_right();
				break;
			}
}


void Game::fire_up(){
	for(int i = 1; i < 4; i++){
		if((this->player_row_idx - i) < 0){		//checks to see if index is within the game space
			return;
		}
		else if(this->board[this->player_row_idx - i][this->player_col_idx].get_char() == 'W'){
			this->wumpus = true;
			return;
		}
	}
}

void Game::fire_down(){
	for(int i = 1; i < 4; i++){
		if((this->player_row_idx + i) > this->length - 1){		//checks to see if index is within the game space
			return;
		}
		else if(this->board[this->player_row_idx + i][this->player_col_idx].get_char() == 'W'){
			this->wumpus = true;
			return;
		}
	}
}


void Game::fire_left(){
	for(int i = 1; i < 4; i++){
		if((this->player_col_idx - i) < 0){		//checks to see if index is within the game space
			return;
		}	
		else if(this->board[this->player_row_idx][this->player_col_idx - i].get_char() == 'W'){
			this->wumpus = true;
			return;
	}
}
}


void Game::fire_right(){
	for(int i = 1; i < 4; i++){
		if((this->player_col_idx + i) > this->width - 1){ 		//checks to see if index is within the game space
			return;
		}
		else if(this->board[this->player_row_idx][this->player_col_idx + i].get_char() == 'W'){
			this->wumpus = true;
			return;
		}
	}
}


void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		Game::fire_arrow();
		return;
	}
	if(this->bats !=0){ 		//if bats were activated, this will run instead of normal movement
		Game::bat_move(c);
		this->bats--;
		return;
	}
	else{
		switch(c){
		case 'w':
			Game::move_up();
			break;
		case 'a':
			Game::move_left();
			break;
		case 's':
			Game::move_down();
			break;
		case 'd':
			Game::move_right();
			break;
		}
	}	
}


void Game::bat_move(char c){
	switch(c){
		case 'w':
			Game::move_down();
			return;
		case 's':
			Game::move_up();
			return;
		case 'a':
			Game::move_right();
			return;
		case 'd':
			Game::move_left();
			return;
	}
}


char Game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:
	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	while(!(cin >> c) || (c != 'w' && c != 'a' && c != 's' && c != 'd' && c != 'f')){  //checks for valid input
	cout << endl << "Invalid Direction: ";
	cin.clear();
	cin.ignore(256, '\n');
	}

	
	return c;
}


//Note: you need to modify this function
void Game::play_game(int w, int l, bool d){


	Game::set_up(w, l);
	this->debug_view = d;

	char input, arrow_input;
	
	while (Game::check_win() == false){
		//print game board
		Game::display_game();

		//display percerts around player's location
		//Your code here:
		Game::print_percepts();
		//Player move...
		//1. get input
		input = Game::get_input();

		//2. move player
		Game::move(input);

		//3. may or may not encounter events
		//Your code here:
		Game::hit_event();

	}
	return;

}


void Game::debug_print(char temp) const{
	if (temp == ' '){
		cout << "  ||";
	}
	else if(temp == 'G'){
		cout << "G ||";
		}
	else if(temp == 'W'){
		cout << "W ||";
	}
	else if(temp == 'B'){
		cout << "B ||";
	}
	else if(temp == 'S'){
		cout << "S ||";
	}
	else if(temp == 'A'){
		cout << "A ||";
	}
}


void Game::print_percepts(){
	bool above, below, left, right;

	if(player_row_idx != 0){	//checks to see if player is on top border
		above = this->board[player_row_idx - 1][player_col_idx].is_empty();
		this->board[player_row_idx - 1][player_col_idx].print_warnings(above);
	}
	if(player_row_idx != length - 1){ //checks to see if player is on bottom border
		below = this->board[player_row_idx + 1][player_col_idx].is_empty();
		this->board[player_row_idx + 1][player_col_idx].print_warnings(below);
	}
	if(player_col_idx != 0){ //checks to see if the player is on left border
		left = this->board[player_row_idx][player_col_idx - 1].is_empty();
		this->board[player_row_idx][player_col_idx - 1].print_warnings(left);
	}
		
	if(player_col_idx != width - 1){ //checks to see if the player is on right border
		right = this->board[player_row_idx][player_col_idx + 1].is_empty();
		this->board[player_row_idx][player_col_idx + 1].print_warnings(right);
	}

}


void Game::hit_event(){
	if(this->board[player_row_idx][player_col_idx].get_char() == 'G'){ //for gold event
		this->board[player_row_idx][player_col_idx].events();
		this->holding_gold = true;
	}
	if(this->board[player_row_idx][player_col_idx].get_char() == 'W'){ //for Wumpus event
		this->board[player_row_idx][player_col_idx].events();
		if(this->armour == true){
		Game::armour_hit();
		return;
		}
		this->wumpus = true;
	}
	if(this->board[player_row_idx][player_col_idx].get_char() == 'B'){ //for Bats event
		this->board[player_row_idx][player_col_idx].events();
		this->bats = 5;
	}
	if(this->board[player_row_idx][player_col_idx].get_char() == 'S'){ //for Stalctite event
		this->board[player_row_idx][player_col_idx].events();
		this->stal = (rand() % 2) != 0;
		if(this->armour == true && this->stal == true){
			Game::armour_hit();
			this->stal = false;
		}

	}
	if(this->board[player_row_idx][player_col_idx].get_char() == 'A'){ //for Armour event
		this->board[player_row_idx][player_col_idx].events();
		this->armour = true;
		this->armour_hits = 2;
	}
	
}