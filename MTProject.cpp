/**************************************************************************
*Function Name      :    MTProject
*Author             :    Loren Davies
*Date               :    10/16/2015
*Course/Section     :    CSC 263 - 001
*Program Description:    Reads line from txt file, and adds it to
* structure. Then call function to add it to array.
*
*BEGIN main
* 
*END main
**************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
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

// Prototypes
int insert_file(game[], int);
int menu_display();
void season_summary(game[], int);
void heading();
int search(game[], int);
int insert_game(game[], int);

// Gloabal constants
const int SIZE = 20; 					// Default size of the array

// Global variables

int main()
{
	// Local constants
	
	// Local variables
	game My_Games[SIZE];				// Array of the games played
	game Temp[SIZE];					// Temp array for games played
	game Temp_Game; 					// Temp game structure
	int Count = 0;						// Count for the array
	int User_Choice;					// User's choice for menu
	int Temp_Index = 0;					// Temp index returned from search()
	
	/*************************** Start main ***************************/
	
	// Load text file to array
	Count = insert_file(My_Games, Count);
	
	// Heading function
	heading();
	
	// Menu display function
	User_Choice = menu_display();
	
	while(User_Choice != 5)
	{
		switch(User_Choice)
		{
			case 1:
				season_summary(My_Games, Count);
				break;
		
			case 2:
				Temp_Index = search(My_Games, Count);
				cout << My_Games[Temp_Index].Game_Number << endl;
				cout << My_Games[Temp_Index].Date << endl;
				cout << My_Games[Temp_Index].Opponent << endl;
				cout << My_Games[Temp_Index].Result << endl;
				cout << My_Games[Temp_Index].Score << endl;
				cout << My_Games[Temp_Index].Their_Score << endl;
				break;
			
			case 3:
				Count = insert_file(My_Games, Count);
				break;
				
			default:
				cout << "invalid input";
				
			
		}//end switch
		User_Choice = menu_display();
	}//end while
	
}//end main

/**************************************************************************
*Function Name      :    insert_file
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

int insert_file(game My_Games[], int Count)
{
	// Local constants

	// Local variables
	string File_Name;					// File name the user inputs
	string Current_Line;				// Line being read
	string Game_Number;					// Number of the game played
	game game;							// Game structure
	ifstream fs;						// Input stream

	/***************************** Start insert_file *****************************/

	// Input file name
	cout << "File name: ";
	cin >> File_Name;

	// Open file
	fs.open(File_Name.c_str());

	// IF there's a problem opening the file
	if (fs.fail())
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
		while (!fs.eof())
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
			if (game.Home_Away != "H" && game.Home_Away != "A")
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

            // FOR every item in the array
            for(int i = 0; i < SIZE; i++)
            {
                // IF game# matches the array
                if(My_Games[i].Game_Number = atoi(Game_Number.c_str()))
                {
                    // Output game# already exists
                    cout << "Game Number: " << Game_Number << " already exists" << endl ;
                }
                else
                {
                    // Call array_insert function
                    My_Games[Count] = game;
                    Count++;
                }
            }
            
            
        }
        return Count;
}

/**************************************************************************
*Function Name      :    season summary
*Author             :    Joe McCarthy
*Date               :    10/16/2015
*Course/Section     :    CSC 263 - 001
*Program Description:    
*
*BEGIN menu_display
* 	
*END menu_display
**************************************************************************/

void season_summary(game My_Games[], int Count)
{
	// Local constants
	
	// Local variables
	
	/*************************** Start season_summary ***************************/
	
	// Call heading function
	heading();
	
	for(int i = 0; i < Count; i++)
	{
		cout << My_Games[i].Game_Number << endl;
		cout << My_Games[i].Date << endl;
		
	}
	
}

/**************************************************************************
*Function Name      :    menu_display
*Author             :    Joe McCarthy
*Date               :    10/16/2015
*Course/Section     :    CSC 263 - 001
*Program Description:    
*
*BEGIN menu_display
* 	
*END menu_display
**************************************************************************/

int menu_display()
{
	// Local constants
	
	// Local variables
	int Choice;
	
	/*************************** Start menu_display ***************************/
	
	cout << "Choose one of the following options: " << endl;
	cout << "1) Season summary\n" << endl;
	cout << "2) Search for a game\n" << endl;
	cout << "3) Enter a new game\n" << endl;
	cout << "4) Delete a game\n" << endl;
	cout << "5) Quit\n" << endl;
	cout << "-> " << endl;
	
	cin >> Choice;

	return Choice;
}

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
	
	// clear screen
	system("cls");
	
	// output heading
	cout << "\n\n\n";
 	cout << setw(47) << "--------------" << endl;
 	cout << setw(47) << "Season Summary" << endl;
 	cout << setw(47) << "--------------";
 	cout << "\n\n\n";
}

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

int search(game My_Games[], int Count)
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


