#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
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

// copy the first s elements from source into dest
void identicalCopy(int* arr, int theSize);
	
// reverse the elements in array a
void reverseArray(int* theArray, int theSize);


//The prototypes for the three simple sort algorithms are:
void exchangeSort(int* arr, int theSize);
void insertionSort(int* arr, int theSize);
void insertionSort(int* arr, int start, int stop);

// sort from index start to index stop inclusive
void selectionSort(int* arr, int theSize);


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
	
	// FIRST SORT -> SORTING THE UNSORTED ARRAY
	cout << "Exchange Sorting..." << endl;
	exchangeSort(copyArray, size);
	displayArray(copyArray, size);
	
	cout << "Comparisions: " << comparisonCount << " Exchanges: " << exchangeCount << endl;
	comparisonCount = 0, exchangeCount = 0;

	// SECOND SORT -> SORTING THE SORTED ARRAY
	cout << "Exchange Sorting..." << endl;
	exchangeSort(copyArray, size);
	displayArray(copyArray, size);
	cout << "Comparisions: " << comparisonCount << " Exchanges: " << exchangeCount << endl;
	comparisonCount = 0, exchangeCount = 0;

	// THIRD SORT -> SORTING THE THIRD ARRAY
	cout << "reversing..." << endl;
	reverseArray(copyArray, size);
	displayArray(copyArray, size);
	cout << "Exchange Sorting..." << endl;
	exchangeSort(copyArray, size);
	displayArray(copyArray, size);
	cout << "Comparisions: " << comparisonCount << " Exchanges: " << exchangeCount << endl;
	comparisonCount = 0, exchangeCount = 0;

	// reset the array with the unsorted array
	for (int i = 0; i < size; i++) { // while reading in each int into temp variable
		copyArray[i] = unsortedArray[i];
	}
	
	
	
	// FIRST SORT -> SORTING THE UNSORTED ARRAY
	cout << "Insertion Sorting..." << endl;
	insertionSort(copyArray, size);
	displayArray(copyArray, size);

	cout << "Comparisions: " << comparisonCount << " Exchanges: " << exchangeCount << endl;
	comparisonCount = 0, exchangeCount = 0;

	// SECOND SORT -> SORTING THE SORTED ARRAY
	cout << "Insertion Sorting..." << endl;
	insertionSort(copyArray, size);
	displayArray(copyArray, size);
	cout << "Comparisions: " << comparisonCount << " Exchanges: " << exchangeCount << endl;
	comparisonCount = 0, exchangeCount = 0;

	// THIRD SORT -> SORTING THE THIRD ARRAY
	cout << "reversing..." << endl;
	reverseArray(copyArray, size);
	displayArray(copyArray, size);
	cout << "Insertion Sorting..." << endl;
	insertionSort(copyArray, size);
	displayArray(copyArray, size);
	cout << "Comparisions: " << comparisonCount << " Exchanges: " << exchangeCount << endl;
	comparisonCount = 0, exchangeCount = 0;

	// reset the array with the unsorted array
	for (int i = 0; i < size; i++) { // while reading in each int into temp variable
		copyArray[i] = unsortedArray[i];
	}
	

	// FIRST SORT -> SORTING THE UNSORTED ARRAY
	cout << "Selection Sorting..." << endl;
	selectionSort(copyArray, size);
	displayArray(copyArray, size);

	cout << "Comparisions: " << comparisonCount << " Exchanges: " << exchangeCount << endl;
	comparisonCount = 0, exchangeCount = 0;

	// SECOND SORT -> SORTING THE SORTED ARRAY
	cout << "Selection Sorting..." << endl;
	selectionSort(copyArray, size);
	displayArray(copyArray, size);
	cout << "Comparisions: " << comparisonCount << " Exchanges: " << exchangeCount << endl;
	comparisonCount = 0, exchangeCount = 0;

	// THIRD SORT -> SORTING THE THIRD ARRAY
	cout << "reversing..." << endl;
	reverseArray(copyArray, size);
	displayArray(copyArray, size);
	cout << "Selection Sorting..." << endl;
	selectionSort(copyArray, size);
	displayArray(copyArray, size);
	cout << "Comparisions: " << comparisonCount << " Exchanges: " << exchangeCount << endl;
	comparisonCount = 0, exchangeCount = 0;

	// reset the array with the unsorted array
	for (int i = 0; i < size; i++) { // while reading in each int into temp variable
		copyArray[i] = unsortedArray[i];
	}
	


	// Identical array metrics
	identicalCopy(copyArray, size);
	displayArray(copyArray, size);

	// EXCHANGE SORT IDENTICAL ARRAY
	cout << "IDENTICAL ARRAY: Exchange Sorting..." << endl;
	exchangeSort(copyArray, size);
	displayArray(copyArray, size);
	cout << "Comparisions: " << comparisonCount << " Exchanges: " << exchangeCount << endl;
	comparisonCount = 0, exchangeCount = 0;


	// INSERTION SORT IDENTICAL ARRAY
	cout << "IDENTICAL ARRAY: Insertion Sorting..." << endl;
	insertionSort(copyArray, size);
	displayArray(copyArray, size);
	cout << "Comparisions: " << comparisonCount << " Exchanges: " << exchangeCount << endl;
	comparisonCount = 0, exchangeCount = 0;
	

	// SELECTION SORT IDENTICAL ARRAY
	cout << "IDENTICAL ARRAY: Selection Sorting..." << endl;
	selectionSort(copyArray, size);
	displayArray(copyArray, size);
	cout << "Comparisions: " << comparisonCount << " Exchanges: " << exchangeCount << endl;
	comparisonCount = 0, exchangeCount = 0;
}
void displayArray(int* arr, int theSize) {

	if (theSize <= 200) { // if size of array is 200 or less, PRINT ALL
		for (int i = 0; i < theSize; i++) { // for - loop
			cout << setw(12) << arr[i] << " "; // fill unsortedArray
			if ((i + 1) % 10 == 0) {
				cout << endl;
			}
		}
	}
	else { // else, print FIRST 100 and LAST 100 elements

		for (int i = 0; i < 100; i++) {
			cout << setw(12) << arr[i] << " "; // fill unsortedArray
			if ((i + 1) % 10 == 0) {
				cout << endl;
			}
		}

		for (int i = theSize - 100; i < theSize; i++) {
			cout << setw(12) << arr[i] << " "; // fill unsortedArray
			if ((i + 1) % 10 == 0) {
				cout << endl;
			}
		}
	}
	cout << endl;
}

// reverse the elements in array a
void reverseArray(int* theArray, int theSize) {

	int temp;
	for (int i = 0; i < theSize / 2; i++)
	{
		temp = theArray[i]; // Store the current element
		theArray[i] = theArray[theSize -1 - i]; // Swap with the corresponding element from the end
		theArray[theSize - 1 - i] = temp; // Complete the swap
	}
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

void identicalCopy(int* arr, int theSize) {
	for (int i = 0; i < theSize; i++) {
		arr[i] = arr[0];
	}
}

void exchangeSort(int* arr, int theSize) {

	for (int k = 1; k < theSize; k++) {
		for (int i = 0; i < theSize - k; i++) {
			if (!compareElement(arr[i], arr[i + 1])){
				swapElement(arr[i], arr[i + 1]);
			}
		}
	}
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

void selectionSort(int* arr, int theSize) {

	int temp, tempA;

	for (int a = 0; a < theSize - 1; a++) { // selects to put minimum equal to first[0] variable, then second[1], then third[2], ect...
		temp = arr[a]; // current element
		tempA = a; // index of the current element
		for (int i = a + 1; i < theSize; i++) { // find min value
			if (compareElement(arr[i], temp)) { // if arr[i] < temp, update temp and tempA
				temp = arr[i]; // update temp to the new minimum
				tempA = i; // update index of the new minimum
			}
		}
		
		if (tempA != a && arr[tempA] != arr[a]) { // only swap if a different element is found
			swapElement(arr[a], arr[tempA]); // swap the found minimum with the current element
		} 
	}
}