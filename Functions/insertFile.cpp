#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

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
	
	int Count = 0;
	
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
			getline(fs, Current_Line);
			
			Game_Number = Current_Line.substr(Count, Count + 1);
			
			
			
			cout << Game_Number;
		}
		
	}
	
	
	
}
