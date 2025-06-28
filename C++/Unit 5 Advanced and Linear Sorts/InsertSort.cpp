#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include<ctime>
// Daniel Harrison
// OCCC C++
// Simple Sorts

using namespace std;

// global variables
long long comparisonCount = 0, exchangeCount = 0;


// Prototypes Here:
void displayArray(int* arr, int theSize); // display array

// exchange elements i and j 
// and increment a global “swapCount” variable
void swapElement(int& i, int& j);

// return true if a[i] <= a[j], false otherwise
// and increment a global “compareCount” variable
bool compareElement(int& i, int& j);


void insertionSort(int* arr, int theSize);
void insertionSort(int* arr, int start, int stop);



int main() {
	cout << "Welcome to the simple sorts program\n";
	string fileName;
	cout << "Please enter input file name: "; // prompt user input
	getline(cin, fileName);

	int size;
	ifstream fin; // input file stream
	fin.open(fileName); // open first file
	if (!fin) { // if file does not open...
		cout << "ERROR opening file " << fileName << "!!!" << endl; // Error message
		exit(EXIT_FAILURE); // Exit program
	}
	fin >> size;
	int* unsortedArray = new int[size];
	int i = 0;
	for (int i = 0; i < size; i++) { // while reading in each int into temp variable
		fin >> unsortedArray[i];
	}
	fin.close(); // close file

	displayArray(unsortedArray, size);

	int* copyArray = new int[size];

	for (int i = 0; i < size; i++) { // while reading in each int into temp variable
		copyArray[i] = unsortedArray[i];
	}
	
	clock_t start, finish;
	double elapsedTime;
	start = clock();

	// FIRST SORT -> SORTING THE UNSORTED ARRAY
	cout << "Insertion Sorting..." << endl;
	insertionSort(copyArray, size);
	displayArray(copyArray, size);

	finish = clock();
	elapsedTime = (finish - start) / CLOCKS_PER_SEC;
	cout << fixed << setprecision(8);
	cout << "Time required for loop version = " << elapsedTime << " seconds " << endl;

	cout << "Comparisions: " << comparisonCount << " Exchanges: " << exchangeCount << endl;
	comparisonCount = 0, exchangeCount = 0;

	// reset the array with the unsorted array
	for (int i = 0; i < size; i++) { // while reading in each int into temp variable
		copyArray[i] = unsortedArray[i];
	}

}
void displayArray(int* arr, int theSize) {

	if (theSize <= 200) { // if size of array is 200 or less, PRINT ALL
		for (int i = 0; i < theSize; i++) { // for - loop
			cout << setw(5) << arr[i] << " "; // fill unsortedArray
			if ((i + 1) % 10 == 0) {
				cout << endl;
			}
		}
	}
	else { // else, print FIRST 100 and LAST 100 elements

		for (int i = 0; i < 100; i++) {
			cout << setw(5) << arr[i] << " "; // fill unsortedArray
			if ((i + 1) % 10 == 0) {
				cout << endl;
			}
		}

		for (int i = theSize - 100; i < theSize; i++) {
			cout << setw(5) << arr[i] << " "; // fill unsortedArray
			if ((i + 1) % 10 == 0) {
				cout << endl;
			}
		}
	}
	cout << endl;
}

// exchange elements i and j 
// and increment a global “swapCount” variable
void swapElement(int& i, int& j) {

	exchangeCount++;

	int temp;

	temp = i;
	i = j;
	j = temp;
}

// return true if a[i] <= a[j], false otherwise
// and increment a global “compareCount” variable
bool compareElement(int& i, int& j) {

	comparisonCount++;

	return i <= j; // returns true if statement is true, else false
}

void insertionSort(int* arr, int theSize) {

	for (int i = 1; i < theSize; i++) {
		insertionSort(arr, i, 0); // start would equal i value and stop would equal 0
	}
}

void insertionSort(int* arr, int start, int stop) {

	for (int i = start; i > stop; i--) {
		// Use compareElement to check if theArray[i] is smaller than theArray[i - 1]
		if (!compareElement(arr[i - 1], arr[i])) {  // If theArray[i - 1] > theArray[i]
			swapElement(arr[i - 1], arr[i]);  // Swap them
		}
		// If compareElement returns true (meaning theArray[i - 1] <= theArray[i]), break the loop.
		else {
			break;
		}
	}
}
