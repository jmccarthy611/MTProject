/**************************************************************************
 *Function Name      :    insertFile
 *Author             :    Loren Davies
 *Date               :    10/16/2015
 *Course/Section     :    CSC 263 - 001
 *Program Description:    Reads line from txt file, and adds it to
 * structure. Then call function to add it to array.
 *
 *BEGIN insertFile
 * 	Input file name
 *	Open file
 *	IF there's a problem opening a file
 *		Output error message
 *	ELSE file did open properly
 *		Read first line, but do nothing with it
 *		WHILE it isn't the end of the file
 *			Input Game_Number add to game
 *			Input Date add to game
 *			Input Opponent add to game
 *			Input Home_Away add to game
 *			IF Home_Away doesn't equal A or H
 *				Add Home_Away to Opponent
 *				Input Home_Away add to game
 *			END IF
 *			Input Score add to game
 *			Input Their_Score add to game
 *			Input Result add to game
 *			Parse and add Game_Number to Game
 *		END WHILE
 *END insertFile
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
	string File_Name;					// File name the user inputs
	string Current_Line;				// Line being read
	string Game_Number;					// Number of the game played
	game game;							// Game structure
	ifstream fs;						// Input stream
	
	/***************************** Start main *****************************/
	
	// Input file name
	cout << "File name: ";
	cin >> File_Name;
	
	// Open file
	fs.open(File_Name.c_str());
	
	// IF there's a problem opening the file
	if(fs.fail())
	{
		// Output error message
		cout << "File DNE";
	}
	
	// ELSE file did open properly
	else
	{
		// Read first line, but do nothing with it
		getline(fs, Current_Line);
		
		// WHILE it isn't the end of the file
		while(!fs.eof())
		{
			// Input Game_Number
			getline(fs, Game_Number, ' ');
			
			// Input Date
			getline(fs, game.Date, ' ');
			
			// Input Opponent
			getline(fs, game.Opponent, ' ');
			
			// Input Home_Away
			getline(fs, game.Home_Away, ' ');
			
			// IF Home_Away doesn't equal A or H
			if(game.Home_Away != "H" && game.Home_Away != "A")
			{
				// Add Home_Away to Opponent
				game.Opponent += " " + game.Home_Away;
				
				// Input Home_Away
				getline(fs, game.Home_Away, ' ');	
			}
			
			// Input Score
			getline(fs, game.Score, ' ');
			
			// Input Their_Score
			getline(fs, game.Their_Score, ' ');
			
			// Input Result
			getline(fs, game.Result, '\n');
			
			// Parse and add Game_Number to game
			game.Game_Number = atoi(Game_Number.c_str());
			
			// Call array_insert function
			//array_insert(game);
		}
	}
}
