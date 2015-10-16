#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

// Structures
struct game
{
	int Game_Number;
	string Date;
	string Opponent;
	string Home_Away;
	string Score;
	string Their_Score;
	string Result;
};

int main()
{
	// Local constants
	
	// Local variables
	string File_Name;
	string Current_Line;
	
	string Game_Number;
	string Date;
	string Opponent;
	string Home_Away;
	string Score;
	string Their_Score;
	string Result;
	
	game game;
	
	
	ifstream fs;				// Input stream
	
	
	
	
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
			getline(fs, Game_Number, ' ');
			getline(fs, Date, ' ');
			getline(fs, Opponent, ' ');
			getline(fs, Home_Away, ' ');
			
			if(Home_Away != "H" && Home_Away != "A")
			{
				Opponent += " " + Home_Away;
				getline(fs, Home_Away, ' ');	
			}
			
			getline(fs, Score, ' ');
			getline(fs, Their_Score, ' ');
			getline(fs, Result, '\n');
			
			game.Game_Number = atoi(Game_Number.c_str());
			game.Date = Date;
			game.Opponent = Opponent;
			game.Home_Away = Home_Away;
			game.Score = Score;
			game.Their_Score = Their_Score;
			game.Result = Result;
			
			array_insert(game);
		}
		
		
		
	}
	
	
	
}
