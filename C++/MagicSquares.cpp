#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
// Daniel Harrison
// OCCC C++
// Magic Squares Homework

using namespace std;

// Prototypes Here:
bool isCompletePuzzle(int ** arr, int size); // returns true if every spot in the puzzle has a non-blank(0) value, false otherwise
bool isValidPuzzle(int** arr, int size); // checks if candidate can is valid/no duplicates in puzzle after adding new candidate
bool solvePuzzle(int** arr, int size); // solves the puzzle and contains the recursive call
void printArray(int** arr, int size); // prints out the array
bool isMagicSquare(int** arr, int size); // checks if the sum of row, column, and diagonal M = ((size * ((size * size) + 1)) / 2);

int main() {

	vector<string>v;
	string fileName;
	cout << "Welcome to the Magic Square Solver\n";

	cout << "Enter a filename: ";
	getline(cin, fileName);

	ifstream fin; // input file stream
	fin.open(fileName); // open first file
	if (!fin) { // if file does not open...
		cout << "ERROR opening file " << fileName << "!!!" << endl; // Error message
		exit(EXIT_FAILURE); // Exit program
	}

	string input;
	int size = 0;
	double dbSize;

	while (fin >> input) {
		if (input != " ") {
			size++; // increments after each non-blankspace string is read, to find the total string inputs
			v.push_back(input); // push all the strings fromt the file into a string vector
		}
	}
	// make sure size is a perfect sqrt with no decimal:
	dbSize = size;
	size = sqrt(size);
	dbSize = sqrt(dbSize);

	if (dbSize == size) {
		cout << "dimensions of array will be: " << size << " by " << size << endl;
	}
	else {
		cout << "ERROR, size is not a perfect square, closing program\n";
		return 0;
	}

	int** tableArray = new int * [size]; // declare the array
	int counter = 0;

	// store the strings from the vector into the array
	for (int i = 0; i < size; i++) {
		tableArray[i] = new int[size];
		for (int j = 0; j < size; j++) {
			if (v[counter] == "-"){
				tableArray[i][j] = 0;
			}
			else {
				tableArray[i][j] = stoi(v[counter]);
			}
			counter++;
		}
	}

	// Display the array values in the array
	printArray(tableArray, size);
	cout << endl;

	if (solvePuzzle(tableArray, size)) {
		cout << "Puzzle solved\n";
	}
	else {
		cout << "Error within the solvePuzzle method!\n";
	}
	cout << endl;
	printArray(tableArray, size);
}
void printArray(int** arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			cout << setw(4)<< arr[i][j] << " ";
		}
		cout << endl;
	}
}

bool solvePuzzle(int** arr, int size) {

	//Base Cases :
	if (!isValidPuzzle(arr, size)) //Check if the puzzle is valid using isValidPuzzle().If not, return false.
	{
		return false;
	}
	if (isCompletePuzzle(arr, size)) // Check if the puzzle is complete using isCompletePuzzle().If so, return true.
	{
		if (!isMagicSquare(arr, size)) {
			return false;
		}
		return true;
	}

	//Recursive Case 
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			if (arr[i][j] == 0) { // Locate the first blank space(zero) in the puzzle.
				for (int a = 1; a <= (size * size); a++) { // Loop over all potential candidates(1 to n ^ 2).
		 
						arr[i][j] = a; // Place candidate
						// Check if the candidate can be placed in the current position using isValidPuzzle().
						if (isValidPuzzle(arr, size)) { // If valid, place the candidate in the puzzle and make a recursive call to solvePuzzle().
							if (solvePuzzle(arr, size)) { // If the recursive call returns true, return true.
								return true;
							}
						}
						arr[i][j] = 0; // If none of the candidates work, reset the cell to 0...
					
				}
				return false; // return false
			}
		}
	}
	return false; // If no solutions work, return false
}

bool isValidPuzzle(int** arr, int size) {

	/*
	This function should check if the current state of the puzzle contains duplicates
	and ensures all numbers are within the range from 1 to n^2.
	*/
	vector<int> v; // declare vector v

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			if(arr[i][j] != 0) // if current element value is not equal to 0
			v.push_back(arr[i][j]); // push value onto vector v
		}
	}
	for (int a = 0; a < v.size(); a++) { // checks all non-zero numbers
		int count = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
			{
				if (v[a] < 0 || v[a] > (size * size)) // within the range from 1 to n ^ 2.
				{
					//cout << "check 1\n";
					return false; 
				}
				if (arr[i][j] == v[a]){ // if number in array equals to one of the numbers in the puzzle, increment count counter by 1
					count++;	
				}
			}
		}
		// just to check count is working correctly cout << "count is: " << count << endl;
		if (count > 1)
		{
			//cout << "INVALID\n";
			return false;
		}
	}
	//printArray(arr, size);
	//cout << "VALID\n";
	return true;
}
bool isCompletePuzzle(int** arr, int size) { 

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == 0) // if any value in the puzzle == 0...
				return false; // return false
		}
	}
	return true; // if no zeros are detected, return true
}
bool isMagicSquare(int** arr, int size) {

	int M = ((size * ((size * size) + 1)) / 2);
	int temp = 0; // accumulator for current row, column, or diagonal

	//Horizontal
	for (int i = 0; i < size; i++) {
		temp = 0;
		for (int j = 0; j < size; j++) {
			temp += arr[i][j]; 
		}
		//cout << " tempA is:  " << temp << endl;
		if (temp != M) // if row is not equal to Magic number...
			return false; // return false
		temp = 0;
	}

	//Vertical 
	for (int i = 0; i < size; i++) {
		temp = 0;
		for (int j = 0; j < size; j++) {

			temp += arr[j][i];
		}
		//cout << " temp is:  " << temp << endl;
		if (temp != M) // if column is not equal to Magic number...
			return false; // return false
		temp = 0;
	}
	
	//Top right to bottom left
	for (int i = size - 1, j = 0; i >= 0; i--, j++) {
		temp += arr[j][i];
	}
	//cout << " temp isR:  " << temp << endl;

	if (temp != M) // if diagonal is not equal to Magic number...
		return false; // return false
	temp = 0;

	//Top left to bottom right
	for (int i = 0; i < size; i++) {
		temp += arr[i][i];
	}
	//cout << " temp isL:  " << temp << endl;

	if (temp != M) // if diagonal is not equal to Magic number...
		return false; // return false
	temp = 0; // reset accumulator variable to 0

	return true;
}