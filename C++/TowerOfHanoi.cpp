#include <iostream>
#include <string>
// Daniel Harrison
// OCCC C+++
// Tower of Hanoi

using namespace std;

// Prototypes Here:
void TOH(int number_of_disks, int start, int end);
bool isValidInput(string input);

int main() {
	bool flag1 = false, flag2 = false, flag3 = false; // flag variables 
	int number_of_disks, start, end; // int variables
	string input; // string variables

	cout << "Hello User! Welcome to the Tower of Hanoi\n";

	while (!flag1) {
		cout << "Enter the number of disk(any digit): "; // prompt for number of disk
		cin >> input; // store user input
		cout << endl; // blank space
		
		if (isValidInput(input)) { // validate user input
			flag1 = true; // set flag to true if user input is valid
			number_of_disks = stoi(input); // set int variable number_of_disk equal to the (string to int) value of input
		}
		if (input == "0") // if input equal to string "0"
			flag1 = false; // set flag variable to false

		if (!flag1) // if flag is false after all checks, prompt for valid input
			cout << "Invalid input! Enter any positive integer\n";
	}
		while (!flag2) {
			cout << "Enter the starting spindle(1 to 3): "; // prompt for starting spindle
			cin >> input; // store input
			cout << endl; // blank space
			if (isValidInput(input) && (input == "1" || input == "2" || input == "3")) { // validate input isDigit + a number 1 to 3
				start = stoi(input); // set start equal to the converted value from string input to integer
				flag2 = true; // set flag variable equal to true
			}
		else // else display an error message and go back to top of loop
			cout << "Invalid spindle. Please enter 1, 2, or 3.\n";
		}
	while (!flag3) {
		cout << "Enter the ending spindle(1 to 3, not same as start): "; // prompt for ending spindle
		cin >> input; // store user input
		cout << endl; // blank space
		if (isValidInput(input) && (input == "1" || input == "2" || input == "3")) { // validate user input isDigit + a number 1 to 3
			end = stoi(input); // set end equal to the value of the string input converted to int
			if (start != end) { // if int start is not equal to int end...
				flag3 = true; // set flag to true
			}
			else // else if they are equal, display error message and restart loop
				cout << "Invalid spindle. Please enter 1, 2, or 3, different from starting spindle.\n";
		}
	}
	TOH(number_of_disks, start, end); // Call the Tower of Hanoi function to print instructions to solve the puzzle
}
bool isValidInput(string input) { // validates user input isDigit

	for (char c : input) {
		if (!isdigit(c))
			return false;
	}
	return true;
}
void TOH(int number_of_disks, int start, int end) {

	// Calculate the undesignated spindle
	int undesignated = 6 - start - end;

	if (number_of_disks == 1) { 
		// Base case: n = 1 -> Move one disk directly
		cout << "Move disk 1 from spindle " << start << " to spindle " << end << endl;
	}
	else { // General case: n > 1
		// Move n-1 disks from start to undesignated
		TOH(number_of_disks - 1, start, undesignated);

		// Move the largest disk from start to end
		cout << "Move disk " << number_of_disks << " from spindle " << start << " to spindle " << end << endl;

		// Move n-1 disks from undesignated to end
		TOH(number_of_disks - 1, undesignated, end);
	}
}