// Daniel Harrison
// array demo
// c++
#include <iostream> // console Input/Output
#include <fstream>  // file Input/Output
#include <string>   // for fileName
#include <iomanip>  // for columns
using namespace std;

// Function Prototypes
void displayArray(const int* theArray, int theSize);         // Decides how much of the array to actually display
void displayArray(const int* theArray, int start, int stop); // Actually does the display

int main() {
	string fileName;
	cout << "Please enter input file name: "; // prompt user input
	getline(cin, fileName); // We fin from files just like we "cin" from the console

	ifstream fin; // input file stream
	fin.open(fileName);
	if (!fin) {
		cout << "ERROR opening file " << fileName << "!!!" << endl; // Error message
		exit(EXIT_FAILURE); // Exit program
	}

	// If we make it past the if statement above, the file is open and ready for use
	int size;
	fin >> size; // we read the first item in the file -> the size
	int* theArray = new int[size]; // then we create an array of that size
	for (int i = 0; i < size; i++) { 
		fin >> theArray[i]; // now we read the rest of the file and fill the array
	}

	// display the contents of the array and exit
	displayArray(theArray, size);
	return 0;

}

void displayArray(const int* theArray, int theSize) {

	if (theSize <= 200) { // if the size of theArray is 200 or smaller, the entire array will be displayed
		displayArray(theArray, 0, theSize);
	}
	else { // else if that size is greater than 200, we will display the first and last hundred elements
		displayArray(theArray, 0, 100);
		displayArray(theArray, theSize - 100, theSize);
	}

}

void displayArray(const int* theArray, int start, int stop) {
	for (int i = start; i < stop; i++) {
		if (i % 10 == 0) { // line break every ten items
			cout << endl;
		}
		cout << setw(7) << theArray[i];
	}
	cout << endl;
	cout << endl;
}