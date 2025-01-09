/******************************************************
** Program: wumpus.cpp
** Author: Nathan Do
** Date: 11/28/2023
** Description: This code represents a huntdown game where the user can win by killing the wumpus or escpaing with the gold.
** Input: How big the user wants the game to be, user decides length and width, and if they want to see the game in debug mode.
** Output: Prints the game into the terminal
******************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;


/*********************************************************************
** Function: get_users_input()
** Description: Gets the input in how big they want the game to be by the user
** Parameters: int w - holds width, int l - hold length
** Pre-Conditions: none
** Post-Conditions: width and length are deteremined by user
*********************************************************************/
void get_users_input(int &w, int &l){
do{
	cout << "How long do you want the cave to be?: ";
		while(!(cin >> w) || w > 51 || w <= 4){
			cin.clear();
			cin.ignore(10000, '\n');
		cout << endl << "Invalid Input, input a number that is less than 51 or greater than 4: ";
	}

	cout << endl << "How wide do you want the cave to be?: ";
		while(!(cin >> l) || l > 51 || l <= 4){
			cin.clear();
			cin.ignore(10000, '\n');
			cout << endl << "Invalid Input, input a number that is less than 51 or greater than 4: ";
		}
	
	if((w * l) < 7){
		cout << "Cave size is too small, minumum size of cave total is 8." << endl;
	}
} while ((w * l) < 7);
}


/*********************************************************************
** Function: debug_mode()
** Description: Gets the input on if the game wants to be viewed in debug mode by user.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns true if user wants to see game in debug mode, false if not.
*********************************************************************/
bool debug_mode(){
int user = 0;
do{
	cout << "Would you like to run this program in debug mode? Put 1 for Yes, 0 for No:  ";
	while(!(cin >> user) || user < 0 || user > 1){
		cin.clear();
		cin.ignore(10000, '\n');
		cout << endl << "Enter 1 or 0: ";
	}
}while(user < 0 || user > 1);
	if(user == 1){
		return true;
	}
	else;
		return false;
}

int main()
{
	//set the random seed
	srand(time(NULL));
	
	int wid = 5, len = 5;
	bool debug = false;
	
	Game g;

	//get two inputs: size of the cave(wid and len)

	get_users_input(wid, len);

	//get the 3rd input --> debug mode or not

	debug = debug_mode();


	//Play game
	g.play_game(wid, len, debug);


	return 0;
}