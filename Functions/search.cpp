/**************************************************************************
 *Function Name      :    search
 *Author             :    Loren Davies
 *Date               :    10/21/2015
 *Course/Section     :    CSC 263 - 001
 *Program Description:    
 *
 *BEGIN search
 * 	
 *END search
 **************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

// Structures
struct game
{
	int Game_Number;					// Number of the game played
	string Date;						// Date of the game
	string Opponent;					// Who they played against
	string Home_Away;					// Were they home away?
	string Score;						// Final score of the game
	string Their_Score;					// Opponent's score of the game
	string Result;						// Was it a win or loss?
};

// Gloabal constants

// Global variables

int main()
{
	// Local constants
	
	// Local variables
	int Choice;							// What the user chooses to do at the menu
	int Game_Number;					// Game number to be searched
	string Opponent;					// Opponent to be searched
	string Date;							// Date to be searched (mm-dd-year)
	
	
	/***************************** Start main *****************************/
	
	// Prompt the user to search by game#, opponent, or date
	cout << "Search by: " << endl;
	cout << "1. Game Number" << endl;
	cout << "2. Opponent" << endl;
	cout << "3. Date" << endl;
	
	// Input choice
	cin >> Choice;
	
	// WHILE number is not in range
	while (Choice > 3 || Choice < 1)
	{
		// Prompt the user to search by game#, opponent, or date
		cout << "Search by: " << endl;
		cout << "1. Game Number" << endl;
		cout << "2. Opponent" << endl;
		cout << "3. Date" << endl;
	
		// Input Choice
		cin >> Choice;
	}
	
	// SWITCH Choice
	switch(Choice)
	{
		// CASE they pick game#
		case 1:
			
			// Input game#
			cout << "Game number: ";
			cin >> Game_Number;
			
			// FOR every item in the array
			for(int i = 0; i < SIZE; i++)
			{
				// IF game# matches the array
				if(My_Games[i].Game_Number == Game_Number)
				{
					// Return the index
					return i;
				}
			}
			
		// END CASE 1
		break;
		
		// CASE they pick opponent
		case 2:
			
			// Input opponent
			cout << "Opponent: ";
			cin >> Opponent;
			
			// FOR every item in the array
			for(int i = 0; i < SIZE; i++)
			{
				//IF opponent matchest the array
				if(My_Games[i].Opponent == Opponent)
				{
					// Return the index
					return i;
				}
			}
		
		// END CASE 2	
		break;
		
		// CASE they pick date
		case 3:
			
			// Input opponent
			cout << "Date (mm-dd-year): ";
			cin >> Date;
			
			// FOR every item in the array
			for(int i = 0; i < SIZE; i++)
			{
				//IF opponent matchest the array
				if(My_Games[i].Date == Date)
				{
					// Return the index
					return i;
				}
			}
		
		// END CASE 3	
		break;
	}
}
