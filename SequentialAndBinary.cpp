#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
// Daniel Harrison
// OCCC C++
// Sequential and Binary Search

using namespace std;

// Prototypes Here:

bool sequentialSearch(int* arr, int theSize, int theSearchItem); // sequential search
void printArray(int* arr, int theSize); // display array

//The prototypes for the simple sort insertionSort algorithm are:
int* insertionSort(int* arr, int theSize);
void insertionSort(int* arr, int start, int stop);

// return true if a[i] <= a[j], false otherwise
// and increment a global “compareCount” variable
bool compareElement(int& i, int& j);

// exchange elements i and j 
// and increment a global “swapCount” variable
void swapElement(int& i, int& j);

bool binarySearch(int* arr, int start, int stop, int searchItem, int count);

int main() {

	string fileName;
	cout << "Please enter input file name: "; // prompt user input
	getline(cin, fileName);

	int size = 0, searchItem;
	ifstream fin; // input file stream
	fin.open(fileName); // open first file
	if (!fin) { // if file does not open...
		cout << "ERROR opening file " << fileName << "!!!" << endl; // Error message
		exit(EXIT_FAILURE); // Exit program
	}
	fin >> size;
	int* unsortedArray = new int[size];
	int i = 0;
	for(int i = 0; i < size; i++){ // while reading in each int into temp variable
		fin >> unsortedArray[i];
	}
	fin.close(); // close file

	cout << endl;
	cout << "Enter number to search for: ";
	cin >> searchItem;

	printArray(unsortedArray, size);
	cout << endl;
	cout << "Searching for " << searchItem << " using sequential search..." << endl;
	sequentialSearch(unsortedArray, size, searchItem);

	int* sortedArray = new int[size];  // Initialize array
	cout << "Sorting..." << endl;

	sortedArray = insertionSort(unsortedArray, size);
	printArray(sortedArray, size);
	cout << endl;

	cout << "Searching for " << searchItem << " using binary search..." << endl;

	int count = 0;
	binarySearch(sortedArray, 0, size, searchItem, count);										 

}
bool sequentialSearch(int* arr, int theSize, int theSearchItem) {

	int count = 0; // counter variable

	for (int i = 0; i < theSize; i++) { // for - loop

		count++;
		if (arr[i] == theSearchItem) // if current element equals the search item...
		{
			cout << "Found! Number of comparisons was " << count << endl;
			return true;
		} // else continue to top of loop ^^^
	}
	// if number is not found in the file....
	cout << theSearchItem << " was not found!" << endl; // display that number was not found
	return false; // return false
}
void printArray(int* arr, int theSize) {

	if (theSize <= 200) { // if size of array is 200 or less, PRINT ALL
		for (int i = 0; i < theSize; i++) { // for - loop
			cout << setw(5) << arr[i] << " "; // fill unsortedArray
			if ((i + 1) % 10 == 0) {
				cout << endl;
			}
		}
	}
	else { // else, print FIRST 100 and LAST 100 elements

		for (int i = 0; i < 100; i++){
			cout << setw(5) << arr[i] << " "; // fill unsortedArray
			if ((i + 1) % 10 == 0) {
				cout << endl;
			}
		}

		for (int i = theSize - 100; i < theSize; i++){
			cout << setw(5) << arr[i] << " "; // fill unsortedArray
			if ((i + 1) % 10 == 0) {
				cout << endl;
			}
		}
	}
}
int*  insertionSort(int* arr, int theSize) {

	for (int i = 1; i < theSize; i++) {
		insertionSort(arr, i, 0); // start would equal i value and stop would equal 0
	}
	return arr;
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

bool binarySearch(int* arr, int start, int stop, int searchItem, int count) {
	count++;

	int n = (stop - start) + 1;  // Size of the current search space
	int mid = (start + stop) / 2; // Midpoint of the current range

	if (n == 0) {
		return false;  // If the range is empty, the item is not found
	}
	
	if (n == 1) {
		if (arr[start] == searchItem) {  // Compare the only element in the range
			cout << "Found! Number of comparisons was " << count << endl;
			return true;
		}
		else {
			return false;
		}
	}
	
	if (arr[mid] == searchItem) {
		cout << "Found! Number of comparisons was " << count << endl;
		return true;
	}
	
	if (arr[mid] > searchItem) {
		// Search the left half: stop at mid - 1 (exclude mid)
		return binarySearch(arr, start, mid - 1, searchItem, count);
	}

	if (arr[mid] < searchItem) {
		// Search the right half: start at mid + 1 (exclude mid)
		return binarySearch(arr, mid + 1, stop, searchItem, count);
	}
	return false;  // If no match, return false
}

// exchange elements i and j 
// and increment a global “swapCount” variable
void swapElement(int& i, int& j) {
	int temp;

	temp = i;
	i = j;
	j = temp;
}

// return true if a[i] <= a[j], false otherwise
// and increment a global “compareCount” variable
bool compareElement(int& i, int& j) {
	return i <= j; // returns true if statement is true, else false
}