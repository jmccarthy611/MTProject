# MTProject
CSC 263
Mid Semester Project

# Project Description:
Create an application that will keep track of game results for a sports team. You will input from a file(s). You will start by
asking the user for the name of the team and then the user should be allowed to perform several operations.

Option 1: The user will be able to display a summary of the season.

Option 2: The user will also be able to search for an individual game by game number, opponent, or date. If the search did not 
fidnd any results then you display an appropraite message. If there was more than one game against the same opponent then
display all games that opponent.

Option 3: The user should be a ble to enter more data. All data will be read from a file. The user can have data in multiple
files. There should neverbe two games with the same game numer or date. If the user tries to input a duplicate game number or
date then ignore that entry and display an error message. Don't assume the game numbers will be input the correct sequence 
(i.e. game 2 might come before game 1). However, the games should be displayed in the correct sequence.

Option 4: Delete a game from the list of games.

Option 5. Quit the program.

All displays should be well organized and user friendly. You are required to create a UML diagram to describe all functions
that will be used. All function will be included in the same file as the main function. Your program should implemet an array
of structures.

The input file should be organized as follows. A header line with category labels(you may change the labels to something 
similiar). The following lines will contain the game info.

For example:

Game #, Date, Opponent, Home/Away, Our Score, Their Score, Win/Loss/Tie

1 11-5-15 St. Johns H 78 73 W

3 11-8-15 Georgetown A 87 86 W

4 1-2-16 Washington St H 87 89 L
