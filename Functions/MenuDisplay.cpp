#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
	// Local constants
	
	// Local variables
	
	cout << "Choose one of the following options: " << endl;
	cout << "1) Season summary\n" << endl;
	cout << "2) Search for a game\n" << endl;
	cout << "3) Enter a new game\n" << endl;
	cout << "4) Delete a game\n" << endl;
	cout << "5) Quit\n" << endl;

	cin >> choice;

	return choice;
