#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()
#include <cctype>
// Daniel Harrison
// OCCC C++
// Tic-Tac-Toe

using namespace std;

// Prototypes:

void displayBoard(char** board, int size); // Display the ticTacToe Board
bool drawBoard(char** board, int size); // returns that the game is a draw if no win matches are found
char ** playGame(char** board, string player, int num, int size);
bool horizontalWin(char** board, int size); // checks for a horizontal win
bool verticalWin(char** board, int size); // checks for a vertical win
bool topLeftToBottomRightWin(char** board, int size); // checks for a diagonal win from top left to bottom right
bool topRightToBottomLeftWin(char** board, int size); // checks for a diagonal win from top right to bottom left
bool validNumber(string sizeString); // Validates dimension variable size

int main() {

	// Intialize the variables
	int size, goesFirst, goesSecond;

	int p1 = 0, p2 = 0, draw = 0; // holds the win count
	string playerOne, playerTwo; // holds the names
	string firstPlayer, secondPlayer; // holds new name for who goes first
	string sizeString;
	// Decides who goes first using this code!
	srand(time(0)); // seeds the random number generator with current time so everytime program loads, 1 or 2 is chosen at random
	goesFirst = rand() % 2 + 1; // Generate a random number between 1 and 2


	do { // Prompt for size of board. If invalid, prompt again...

		cout << "Enter board dimensions between 3 to 9: ";
		cin >> sizeString; // sets user input to a string variable to check if it == 3 to 9
		cout << endl;

		while (!validNumber(sizeString)) { // if sizeString is not a number 3 to 9, keep prompting for user input
			cout << "Enter board dimensions between 3 to 9: ";
			cin >> sizeString;
			cout << endl;
		}
		size = stoi(sizeString); // convert from string to int and set int size equal to that value

	} while (size < 3 || size > 9);

	// Intialize the board array
	char** board = new char* [size]; 
	for (int i = 0; i < size; i++) {
		board[i] = new char[size];
		for (int j = 0; j < size; j++) {
			board[i][j] = ' ';
		}
	}

	cout << "Enter name for player one: ";
	cin >> playerOne; // assigns symbol X
	int num1 = 1; 

	cout << "Enter name for player two: ";
	cin >> playerTwo; // assigns symbol O
	int num2 = 2;

	//Might need some work here
	if (goesFirst == 1) { // if goesFirst equals 1 (playerOne) then player one goes first
		goesSecond = 2;
		firstPlayer = playerOne;
		secondPlayer = playerTwo;
	}
	else { // else goesSecond equals 1 (playerTwo goes second)
		goesSecond = 1;
		firstPlayer = playerTwo;
		secondPlayer = playerOne;
	}
	// initialize variables
	bool flag = false;
	bool playAgain = false;
	char retry = ' ';

	do {
		// reset variables
		flag = false;
		playAgain = false;
		retry = ' ';

		// Clear the board
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				board[i][j] = ' ';
			}
		}

		displayBoard(board, size); // display the current tic-tac-toe board
		do { // do while for the game to continue

			board = playGame(board, firstPlayer, num1, size); // Player one plays

			if (horizontalWin(board, size) == false) {

				cout << firstPlayer << " won the game\n"; // display the firstPlayer won the game
				if (firstPlayer == playerOne)
					p1++; // add a win to the p1 (playerOne) counter
				else
					p2++; // add a win to the p2 (playerTwo) counter

				displayBoard(board, size); // display the current tic-tac-toe board
				flag = true; // variable to break out of do-while loop
				break;
			}
			if (verticalWin(board, size) == false) {

				cout << firstPlayer << " won the game\n"; // display the firstPlayer won the game
				if (firstPlayer == playerOne)
					p1++; // add a win to the p1 (playerOne) counter
				else
					p2++; // add a win to the p2 (playerTwo) counter
				displayBoard(board, size); // display the current tic-tac-toe board
				flag = true; // variable to break out of do-while loop
				break;
			}
			if (topLeftToBottomRightWin(board, size) == false) {

				cout << firstPlayer << " won the game\n"; // display the firstPlayer won the game
				if (firstPlayer == playerOne)
					p1++; // add a win to the p1 (playerOne) counter
				else
					p2++; // add a win to the p2 (playerTwo) counter
				displayBoard(board, size); // display the current tic-tac-toe board
				flag = true; // variable to break out of do-while loop
				break;
			}
			if (topRightToBottomLeftWin(board, size) == false) {

				cout << firstPlayer << " won the game\n"; // display the firstPlayer won the game
				if (firstPlayer == playerOne)
					p1++; // add a win to the p1 (playerOne) counter
				else
					p2++; // add a win to the p2 (playerTwo) counter
				displayBoard(board, size); // display the current tic-tac-toe board
				flag = true; // variable to break out of do-while loop
				break;
			}
			if (drawBoard(board, size)) {
				draw++;
				cout << "Game is a DRAW!, no WINNER!!!\n"; // display game is a draw
				displayBoard(board, size); // display the current tic-tac-toe board
				flag = true; // variable to break out of do-while loop
				break;
			}

			displayBoard(board, size);
			board = playGame(board, secondPlayer, num2, size); // Player two plays

			if (horizontalWin(board, size) == false) {

				cout << secondPlayer << " won the game\n"; // display the secondPlayer won the game
				if (secondPlayer == playerTwo)
					p2++; // add a win to the p2 (playerTwo) counter
				else
					p1++; // add a win to the p1 (playerOne) counter
				displayBoard(board, size); // display the current tic-tac-toe board
				flag = true; // variable to break out of do-while loop
				break;
			}
			if (verticalWin(board, size) == false) {

				cout << secondPlayer << " won the game\n"; // display the secondPlayer won the game
				if (secondPlayer == playerTwo)
					p2++; // add a win to the p2 (playerTwo) counter
				else
					p1++; // add a win to the p1 (playerOne) counter
				displayBoard(board, size); // display the current tic-tac-toe board
				flag = true; // variable to break out of do-while loop
				break;
			}
			if (topLeftToBottomRightWin(board, size) == false) {

				cout << secondPlayer << " won the game\n"; // display the secondPlayer won the game
				if (secondPlayer == playerTwo)
					p2++; // add a win to the p2 (playerTwo) counter
				else
					p1++; // add a win to the p1 (playerOne) counter
				displayBoard(board, size); // display the current tic-tac-toe board
				flag = true; // variable to break out of do-while loop
				break;
			}
			if (topRightToBottomLeftWin(board, size) == false) {

				cout << secondPlayer << " won the game\n"; // display the secondPlayer won the game
				if (secondPlayer == playerTwo)
					p2++; // add a win to the p2 (playerTwo) counter
				else
					p1++; // add a win to the p1 (playerOne) counter
				displayBoard(board, size); // display the current tic-tac-toe board
				flag = true; // variable to break out of do-while loop
				break;
			}
			if (drawBoard(board, size)) {
				draw++; // adds one to draw counter
				cout << "Game is a DRAW!, no WINNER!!!\n"; // display game is a draw
				displayBoard(board, size); // display the current tic-tac-toe board
				flag = true; // variable to break out of do-while loop
				break;
			}
			displayBoard(board, size); // display the current tic-tac-toe board

		} while (flag != true); // while flag is false, current game continues -> do-while loop

		do{ // do while to play again
			cout << "Do you want to play again: (Y) for YES, (N) for NO! ";
			cin >> retry;

			retry = toupper(retry); // capitalize variable retry

		} while (retry != 'Y' && retry != 'N');

		if (retry == 'Y') { // if yes is selected...
			if (firstPlayer == playerOne) // switches who goes first
			{
				firstPlayer = playerTwo;
				secondPlayer = playerOne;
			}
			else
			{
				firstPlayer = playerOne;
				secondPlayer = playerTwo;
			}
			playAgain = false;
		}
		else
			playAgain = true;

	} while (playAgain != true);

	cout << endl;
	// Display amount of wins per player + draw amount
	cout << playerOne << " won " << p1 << " games and " << playerTwo << " won " << p2 << " games! Draw Count: " << draw << endl;
}

void displayBoard(char** board, int size) {
	//Display the updated board
	cout << endl;
	for (int c = 0; c < size; c++)
	{
		cout << "      " << c + 1;
	}
	cout << endl;
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << "     ";
		for (int j = 0; j < size; j++) {

			if (j == 0 || j == (size))
				cout << "  " << board[i][j];
			else
				cout << " |  " << board[i][j];
		}
		cout << endl;
		if (i != size - 1) {
			cout << "     ";
			for (int l = 0; l < size; l++)
			{
				cout << "-----";
			}
		}
		cout << endl;
	}
} 

bool drawBoard(char** board, int size) 
{
	for (int i = 0; i < size; i++) { // For loop to check if the board is full

		for (int j = 0; j < size; j++)
			if (board[i][j] == ' ')
				return false;
	}
	return true;
}

char** playGame(char** board, string player, int num, int size) {
	// Initialize variables
	int row, columns;
	char c;
	if (num == 1) // num variable used to set whoever goes first to 'X' and whoever goes second to 'O'
		c = 'X'; 
	else
		c = 'O';

	cout << player << "(" << c << ")" << "->BLANKED SPACES ONLY, Enter two numbers : first for row, second for column : ";
	cin >> row >> columns; // store the row,column input user typed inputs

	row = row - 1; // -1 bc elements start at 0
	columns = columns - 1; // -1 bc elements start at 0

	while (row > size || row < 0 || columns > size || columns < 0)
	{
		cout << "Enter numbers 1 to " << size << " only!\n";
		cin >> row >> columns;
		row = row - 1; // -1 bc elements start at 0
		columns = columns - 1; // -1 bc elements start at 0
	}

	while (board[row][columns] != ' ')
	{
		cout << player << "(" << c << ")" << "->BLANKED SPACES ONLY, Enter two numbers : first for row, second for column : ";
		cin >> row >> columns; // store the row,column input user typed inputs

		row = row - 1; // -1 bc elements start at 0
		columns = columns - 1; // -1 bc elements start at 0
	}

	if (num == 1) // I need to make sure num if constant per player so I could instead use the playersName instead of Num (will work on this!)
		board[row][columns] = 'X';
	else
		board[row][columns] = 'O';

	return board;
}

bool horizontalWin(char** board, int size) {
	// initialize variables
	char temp = ' ';
	char firstTemp = ' ';
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		
		// Clear variables before starting another [j] loop
		count = 0;
		firstTemp = ' ';
		temp = ' ';

		for (int j = 0; j < size; j++)
		{ 
				if (j == 0) {
					firstTemp = board[i][j]; // set to char in first index of the row
				}
				else
				{
					temp = board[i][j]; // the rest of the char in the row will be set to this temp variable at each iteration
				}

				if (firstTemp == temp) // if firstTemp char is equal to temp char
				{
					if (temp != ' ') // if temp does not equal nothing
					{
						count++; // counter for measuring how many variables in the same row are the same as the first one
					}
				}
				else {  // else...
					continue; // continue to go through the loops
				}
		}
		if (count == (size - 1)) // count will equal variable (size  - 1), if all char in the current row are the same
		{
			cout << "Horizontal match found!\n";
			return false;
		}
	}
	return true;
}

bool verticalWin(char** board, int size) {
	// initialize variables
	char temp = ' ';
	char firstTemp = ' ';
	int count = 0;
	for (int i = 0; i < size; i++)
	{

		// Clear variables before starting another [j] loop
		count = 0;
		firstTemp = ' ';
		temp = ' ';

		for (int j = 0; j < size; j++)
		{

			if (j == 0) { // if starting a new column to check
				firstTemp = board[j][i]; // first temp will be equal to the current [i] iteration at the top of the current [i] column
			}
			else
			{
				temp = board[j][i]; // set temp equal to current [j][i] iteration in loop
			}

			if (firstTemp == temp) // if firstTemp equals temp variable
			{
				if (temp != ' ')
				{
					count++; // counter for measuring how many variables in the same row are the same as the first one
				}
			}
			else {  // else...
				continue; // continue to go through the loop
			}
		}
		if (count == (size - 1)) // if all variables in the vertical are the same char then vertical match is found
		{
			cout << "Vertical match found!\n";
			return false;
		}
	}
	return true;
}

bool topLeftToBottomRightWin(char** board, int size) {
	// initialize the variables
	char temp = ' ';
	char firstTemp = ' ';
	int count = 0;
	for (int i = 0; i < size; i++)
	{
			if (i == 0) { // if top left variable on the board...
				firstTemp = board[i][i]; // set firstTemp equal to top left variable on board
			}
			else // else...
			{
				temp = board[i][i]; // set temp equal to current iteration of loop using [i][i] counter
			}

			if (firstTemp == temp) // if firstTemp equals temp
			{
				if (temp != ' ') // if temp is not equal to nothing
				{
					count++; // counter for measuring how many variables in the same row are the same as the first one
				}
			}
			else { // else...
				continue; // continue to go through the loop
			}
		if (count == (size - 1)) // if all variables in the diagonal are the same, then diagonal match is found!
		{
			cout << "top left Diagonal match found!\n";
			return false;
		}
	}
	return true;
}

 bool topRightToBottomLeftWin(char** board, int size) {
	 // initialize the variables
	char temp = ' ';
	char firstTemp = ' ';
	int count = 0;
	int j = 0;
	for (int i = size - 1; i >= 0; i--, j++) // i decrements (moves checker left one), j increments (moves check down one)
	{
			if (i == size - 1) { // if i = top right character
				firstTemp = board[j][i]; //set firstTemp equal to the variable in the top right character on the board
			}
			else
			{
				temp = board[j][i]; // else if it isnt the top right variable, set it equal to temp		 
			}

			if (firstTemp == temp) // if first temp == temp
			{ 
				if (temp != ' ') // if temp is not equal to a blank space...
				{
					count++; // counter for measuring how many variables in the same diagonal are the same as the first one
				}
			}
			else { // else...
				continue; // go back to the top of the loop
			}
	}
		if (count == (size - 1)) // if all variables in the diagonal are the same then turn player wins
		{
			cout << "top right Diagonal match found!\n";
			return false;
		}
	return true;
}

 bool validNumber(string sizeString) { // checks for valid dimensions
	 if (sizeString != "3" && sizeString != "4" && sizeString != "5" && sizeString != "6" && sizeString != "7" && sizeString != "8" && sizeString != "9")
		 return false; // if not valid return false
	 else
		 return true; // else return true
 }