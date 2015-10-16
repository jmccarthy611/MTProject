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
	
	string Game_Number;
	string Date;
	
	string Line;
	string Current_Line;
	
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
			fs >> Game_Number >> Date;
			
			getline(fs, Current_Line);
			
			cout << Game_Number << Date << endl;
			
		}
		
		
		
		/*cout << Game_Number << endl;
		cout << Date << endl;*/
	}
	
	
	
}
