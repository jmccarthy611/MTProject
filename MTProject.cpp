/**************************************************************************
*Function Name      :    MTProject
*Author             :    Loren Davies, Joe McCarthy, Tyler Myers
*Date               :    10/30/2015
*Course/Section     :    CSC 263 - 001
*Program Description:    Create an application that will keep track of game
* results for a sports team. You will input from a file(s). You will start
* by asking the user for the name of the team and then the user should be
* allowed to perform several operations.
*
*BEGIN main
* 	Call the heading function
* 	Call the menu display function
* 	WHILE(the user doesn't want to quit)
* 		SWITCH the user's choice
* 			CASE they pick season summary
* 				Call the season summary function
* 			END CASE
* 			CASE they want to search for a game
* 				Call the search function
* 				Output the game searched
* 			END CASE
* 			CASE they want to add a new file
* 				Call the insert file function
* 			END CASE
* 			CASE they want to delete a game
* 				Call the delete game function
* 			END CASE
* 			DEFAULT  invalid input
* 				Output error message
* 			END CASE
* 		END SWITCH
* 		Call the menu display function
* 	END WHILE
*END main
**************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

// Structures
struct game
{
	int Game_Number;						// Number of the game played
	string Date;							// Date of the game
	string Opponent;						// Who they played against
	string Home_Away;						// Were they home away?
	string Score;							// Final score of the game
	string Their_Score;						// Opponent's score of the game
	string Result;							// Was it a win or loss?
};

// Prototypes
void heading();
int menu_display();
void season_summary(game[], int);
int search(game[], int);
int insert_file(game[], int);
int delete_game(game[], int);
bool array_check(game[], int, int);

// Global constants
const int ARRAY_SIZE = 20; 					// Default size of the array

int main()
{
	// Local constants
	
	// Local variables
	game My_Games[ARRAY_SIZE];				// Array of the games played
	int Count = 0;							// Count for the array
	int User_Choice;						// User's choice for menu
	int Temp_Index = 0;						// Temp index returned from search()
	
	/*************************** Start main ***************************/
	
	// Call the heading function
	heading();
	
	// Call the menu display function
	User_Choice = menu_display();
	
	// WHILE(the user doesn't want to quit)
	while(User_Choice != 5)
	{
		
		// SWITCH the user's choice
		switch(User_Choice)
		{
			
			// CASE they pick season summary
			case 1:
				
				// Call the season summary function
				season_summary(My_Games, Count);
				
				// END CASE
				break;
		
			// CASE they want to search for a game
			case 2:
				
				// Call the search function
				Temp_Index = search(My_Games, Count);
				
				// Output the game searched
				cout << My_Games[Temp_Index].Game_Number << endl;
				cout << My_Games[Temp_Index].Date << endl;
				cout << My_Games[Temp_Index].Opponent << endl;
				cout << My_Games[Temp_Index].Result << endl;
				cout << My_Games[Temp_Index].Score << endl;
				cout << My_Games[Temp_Index].Their_Score << endl;
				
				// END CASE
				break;
			
			// CASE they want to add a new file
			case 3:
				
				// Call the insert file function
				Count = insert_file(My_Games, Count);
				
				// END CASE
				break;
				
			// CASE they want to delete a game
			case 4:
				
				// Call the delete game function
				Count = delete_game(My_Games, Count);
				
				// END CASE
				break;
			
			// DEFAULT invalid input
			default:
				
				// Output error message
				cout << "invalid input";
				
				// END CASE
				break;
			
		} // END SWITCH
		
		// Call the menu display function
		User_Choice = menu_display();

	} // END WHILE

} // END main

/**************************************************************************
 *Function Name      :    heading                                         *
 *Author             :    Loren Davies                                    *
 *Date               :    09/04/2015                                      *
 *Course/Section     :    CSC 263 - 001                                   *
 *Program Description:    Clears screen and sets up heading.         	  *
 *                                                                        *
 *BEGIN heading  														  *
 *	clear screen														  *
 *  output heading														  *
 *END heading                                                             *
 **************************************************************************/

void heading()
{
	// Local constants
	
	// Local variables
	
	/************************** Start heading **************************/
	
	// Clear screen
	system("cls");
	
	// Output heading
	cout << "\n\n\n";
 	cout << setw(47) << "--------------" << endl;
 	cout << setw(47) << "Season Summary" << endl;
 	cout << setw(47) << "--------------";
 	cout << "\n\n\n";

} // END heading

/**************************************************************************
*Function Name      :    menu_display
*Author             :    Joe McCarthy
*Date               :    10/16/2015
*Course/Section     :    CSC 263 - 001
*Program Description:    
*
*BEGIN menu_display
* 	Call heading function
* 	Output menu
* 	Input user choice
* 	RETURN choice to main
*END menu_display
**************************************************************************/

int menu_display()
{
	// Local constants
	
	// Local variables
	int Choice;
	
	/*************************** Start menu_display ***************************/
	
	// Call heading function
	heading();
	
	// Output menu
	cout << setw(45) << "Menu Display" << endl;
	cout << setw(50) << "1) Season summary" << endl;
	cout << setw(53) << "2) Search for a game" << endl;
	cout << setw(52) << "3) Input a new file" << endl;
	cout << setw(49) << "4) Delete a game" << endl;
	cout << setw(41) << "5) Quit\n" << endl;
	cout << setw(36) << "-> ";
	
	// Input user choice
	cin >> Choice;

	// RETURN choice to main
	return Choice;

} // END menu_display

/**************************************************************************
*Function Name      :    season_summary
*Author             :    Joe McCarthy
*Date               :    10/16/2015
*Course/Section     :    CSC 263 - 001
*Program Description:    
*
*BEGIN season_summary(My_Games array, Count coming from main)
* 	Call heading function
* 	FOR(Every index in the array)
* 		IF it's the first time through the loop
* 			Output a row of stars
* 		END IF
* 		Output the information about all the games
* 	END FOR
*	System pause
*END season_summary
**************************************************************************/

void season_summary(game My_Games[], int Count)
{
	// Local constants
	
	// Local variables
	
	/*************************** Start season_summary ***************************/
	
	// Call heading function
	heading();
	
	// FOR(Every index in the array)
	for(int i = 0; i < Count; i++)
	{
		
		// IF it's the first time through the loop
		if(i == 0)
		{
			
			// Output a row of stars
			cout << "*************************" << endl;
			
		} // END IF
		
		// 	Output the information about all the games
		cout << "Game number: " << My_Games[i].Game_Number << endl;
		cout << "Date: " << My_Games[i].Date << endl;
		cout << "Opponent: " << My_Games[i].Opponent << endl;
		cout << "Home or Away: " << My_Games[i].Home_Away << endl;
		cout << "Score: " << My_Games[i].Score << endl;
		cout << "Their score: " << My_Games[i].Their_Score << endl;
		cout << "Result: " << My_Games[i].Result << endl;
		cout << "*************************" << endl;
	
	} // END FOR
	
	// Pause screen
	system("PAUSE");
	
} // END season_summary

/**************************************************************************
 *Function Name      :    search
 *Author             :    Tyler Myers
 *Date               :    10/21/2015
 *Course/Section     :    CSC 263 - 001
 *Program Description:    
 *
 *BEGIN search(My_Games array and Count from main)
 * 	Prompt the user to search by game#, opponent, or date
 * 	Input choice
 * 	WHILE number is not in range
 * 		Prompt the user to search by game#, opponent, or date
 * 		Input Choice
 * 	END WHILE
 * 	SWITCH Choice
 * 		CASE they pick game#
 * 			Input game#
 * 			FOR every item in the array
 * 				IF game# matches the array
 * 					RETURN the index
 * 				END IF
 * 			END FOR
 * 		END CASE
 * 		CASE they pick opponent
 * 			Input opponent
 * 			FOR every item in the array
 * 				IF opponent matches the array
 * 					RETURN the index
 * 				END IF
 * 			END FOR
 * 		END CASE
 * 		CASE they pick date
 * 			Input opponent
 * 			FOR every item in the array
 * 				IF opponent matches the array
 * 					Return the index
 * 				END IF
 * 			END FOR
 * 		END CASE
 * 		DEFAULT invalid input
 * 			Output error message
 * 		END CASE
 * 	END SWITCH
 *END search
 **************************************************************************/

int search(game My_Games[], int Count)
{
	// Local constants
	
	// Local variables
	int Choice;							// What the user chooses to do at the menu
	int Game_Number;					// Game number to be searched
	string Opponent;					// Opponent to be searched
	string Date;						// Date to be searched (mm-dd-year)
	
	
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
		
	} // END WHILE
	
	// SWITCH Choice
	switch(Choice)
	{
		// CASE they pick game#
		case 1:
			
			// Input game#
			cout << "Game number: ";
			cin >> Game_Number;
			
			// FOR every item in the array
			for(int i = 0; i < ARRAY_SIZE; i++)
			{
			
				// IF game# matches the array
				if(My_Games[i].Game_Number == Game_Number)
				{
				
					// Return the index
					return i;
				
				} // END IF
			
			} // END FOR
			
			// END CASE
			break;
		
		// CASE they pick opponent
		case 2:
			
			// Input opponent
			cout << "Opponent: ";
			cin >> Opponent;
			
			// FOR every item in the array
			for(int i = 0; i < ARRAY_SIZE; i++)
			{
				
				// IF opponent matches the array
				if(My_Games[i].Opponent == Opponent)
				{
					
					// Return the index
					return i;
				
				} // END IF
			
			} // END FOR
		
			// END CASE
			break;
		
		// CASE they pick date
		case 3:
			
			// Input opponent
			cout << "Date (mm-dd-year): ";
			cin >> Date;
			
			// FOR every item in the array
			for(int i = 0; i < ARRAY_SIZE; i++)
			{
				
				// IF opponent matches the array
				if(My_Games[i].Date == Date)
				{
					
					// Return the index
					return i;
					
				} // END IF
			
			} // END FOR
		
			// END CASE 3	
			break;
		
		// DEFAULT invalid input	
		default:
			
			// Ouput error message
			cout << "Invalid input!";
			
			// END CASE
			break;
			
	} // END SWITCH
	
} // END search

/**************************************************************************
*Function Name      :    insert_file
*Author             :    Loren Davies
*Date               :    10/16/2015
*Course/Section     :    CSC 263 - 001
*Program Description:    Reads line from txt file, and adds it to
* structure. Then call function to add it to array.
*
*BEGIN insert_file(My_Games array, Count from main)
* 	Input file name
* 	Open file
* 	IF there's a problem opening the file
* 		Output error message
* 	ELSE file did open properly
* 		Read first line, but do nothing with it
* 		WHILE it isn't the end of the file
* 			Input Game_Number
* 			Parse and add Game_Number to game
* 			Input Date
* 			Input Opponent
* 			Input Home_Away
* 			IF Home_Away doesn't equal A or H
* 				Add Home_Away to Opponent
* 				Input Home_Away
* 			END IF
* 			Input Score
* 			Input Their_Score
* 			Input Result
* 			IF the game isn't a duplicate
* 				Add game to array
* 				FOR(Every spot in the array)
* 					Copy value from array to Temp
* 					Set J equal to index
* 					WHILE(J is greater than 0 and Num_Array is greater than Temp)
* 						Shift the array
* 						Decrement J
* 					END WHILE
* 					Set Array at index J to Temp
* 				END FOR
* 				Increment Count
* 			END IF
* 		END WHILE
* 		RETURN Count to main
* 	END IF
*END insert_file
**************************************************************************/

int insert_file(game My_Games[], int Count)
{
	// Local constants

	// Local variables
	string File_Name;					// File name the user inputs
	string Current_Line;				// Line being read
	string Game_Number;					// Number of the game played
	game Game;							// Game structure
	game Temp;							// Temp structure used for sorting
	int J;								// Index used for sorting
	ifstream fs;						// Input stream

	/***************************** Start insert_file *****************************/

	// Input file name
	cout << setw(40) << "File name: ";
	cin >> File_Name;

	// Open file
	fs.open(File_Name.c_str());

	// IF there's a problem opening the file
	if(fs.fail())
	{
		// Output error message
		cout << "No such file!" << endl;
	}

	// ELSE file did open properly
	else
	{
		// Read first line, but do nothing with it
		getline(fs, Current_Line, '\n');

		// WHILE it isn't the end of the file
		while (!fs.eof())
		{	
			// Input Game_Number
			getline(fs, Game_Number, ' ');
			
			// Parse and add Game_Number to game
			Game.Game_Number = atoi(Game_Number.c_str());

			// Input Date
			getline(fs, Game.Date, ' ');

			// Input Opponent
			getline(fs, Game.Opponent, ' ');

			// Input Home_Away
			getline(fs, Game.Home_Away, ' ');

			// IF Home_Away doesn't equal A or H
			if (Game.Home_Away != "H" && Game.Home_Away != "A")
			{
				// Add Home_Away to Opponent
				Game.Opponent += " " + Game.Home_Away;

				// Input Home_Away
				getline(fs, Game.Home_Away, ' ');
			}

			// Input Score
			getline(fs, Game.Score, ' ');

			// Input Their_Score
			getline(fs, Game.Their_Score, ' ');

			// Input Result
			getline(fs, Game.Result, '\n');
				
			// IF the game isn't a duplicate		
			if(array_check(My_Games, Count, Game.Game_Number))
			{
				// Add game to array
				My_Games[Count] = Game;
				
				// FOR(Every spot in the array)
				for(int i = 1; i <= Count; i++)
				{
					// Copy value from array to Temp
					Temp = My_Games[i];
		
					// Set J equal to index
					J = i;
		
					// WHILE(J is greater than 0 and Num_Array is greater than Temp)
					while(J > 0 && My_Games[J - 1].Game_Number > Temp.Game_Number)
					{
						// Shift the array
						My_Games[J] = My_Games[J - 1];
			
						// Decrement J
						J--;
					}
		
					// Set Array at index J to Temp
					My_Games[J] = Temp;
		
				} // END FOR
					
            	// Increment Count
				Count++;
			
			} // END IF
	
		} // END WHILE
		
		// RETURN Count to main
		return Count;
	
	} // END IF

} // END insert_file

/**************************************************************************
 *Function Name      :    delete_game
 *Author             :    Tyler Myers
 *Date               :    10/30/2015
 *Course/Section     :    CSC 263 - 001
 *Program Description:    
 *
 *BEGIN delete_game(My_Games array, Count from main)
 *	Call the search function
 *	Ask the user if they really want to delete
 *	Input choice
 *	WHILE(there's invalid input)
 *		Output error message
 *		Ask the user if they really want to delete
 *		Input choice
 *	END WHILE
 *	IF(User chooses to delete)
 *		WHILE temp is less than Count
 *			Shift My_Games
 *			Increment Temp
 *		END WHILE
 *		Decrement Count
 *	END IF
 *	RETURN Count to main
 *END delete_game
 **************************************************************************/

int delete_game(game My_Games[], int Count)
{
	// Local constants
	
	// Local variables
	int Temp = 0;							// Index to be deleted from the array	
	int Choice;								// User's choice
	
	/***************************** Start delete_game *****************************/
	
	// Call the search function
	Temp = search(My_Games, Count);
	
	// Ask the user if they really want to delete
	cout << "Are you sure you want to delete this game?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	
	// Input Choice
	cin >> Choice;
	
	// WHILE(there's invalid input)
	while (Choice > 2 || Choice < 1)
	{
		
		// Ouput error message
		cout << "Invalid input!" << endl;
		
		// Prompt the user to search by game#, opponent, or date
		cout << "Are you sure you want to delete this game?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
	
		// Input Choice
		cin >> Choice;
		
	} // END WHILE
	
	// IF(User chooses to delete)
	if(Choice == 1)
	{
		
		// WHILE temp is less than Count
	 	while(Temp < Count)
		{
			
			// Shift My_Games
			My_Games[Temp] = My_Games[Temp + 1];
			
			// Increment Temp
			Temp++;
			
		} // END WHILE
		
		// Decrement Count
		Count -= 1;	
		
	} // END IF

	// RETURN Count to main
	return Count;
	
} // END delete_game

/**************************************************************************
 *Function Name      :    array_check
 *Author             :    Loren Davies
 *Date               :    10/30/2015
 *Course/Section     :    CSC 263 - 001
 *Program Description:    
 *
 *BEGIN array_check(My_Games array, Count, Game_Number from insert_file)
 * 	IF My_Games is empty
 * 		RETURN true to main
 * 	END IF
 * 	FOR(Every Game in My_Games and Flag is not true)
 * 		IF there's a duplicate game
 * 			Set the flag to true
 * 		END IF
 * 	END FOR
 * 	RETURN !Flag to insert_file
 *END array_check
 **************************************************************************/

bool array_check(game My_Games[], int Count, int Game_Number)
{
	// Local constants
	
	// Local variables
	bool Flag = false;							// Flag, if true then there is a duplicate game
	
	/***************************** Start array_check *****************************/
	
	// IF the My_Games is empty
	if(Count == 0)
	{
		
		// RETURN true to main
		return true;
		
	} // END IF
	
	// FOR(Every Game in My_Games and Flag is not true)
	for(int i = 0; (i < Count) && (Flag != true); i++)
	{
		
		// IF there's a duplicate game
		if(My_Games[i].Game_Number == Game_Number)
		{
			
			// Set the flag to true
			Flag = true;
			
		} // END IF
			
	} // END FOR
	
	// RETURN !Flag to insert_file
	return !Flag;
	
} // END array_check
