#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

// Daniel Harrison
// OCCC C++
// Quick Sort

using namespace std;


// global variables
long long comparisonCount = 0, exchangeCount = 0;
const int SMALL_LIST_SIZE = 10;


// Prototypes Here:

// exchange elements i and j 
// and increment a global “swapCount” variable
void swapElement(int& i, int& j);

// return true if a[i] <= a[j], false otherwise
// and increment a global “compareCount” variable
bool compareElement(int& i, int& j);
void displayArray(int* arr, int theSize); // display array
void insertionSort(int* arr, int theSize);
void insertionSort(int* arr, int start, int stop);

void quickSort(int* arr, int theSize);
void quickSort(int* arr, int startIndex, int stopIndex);


void setMedianOfThree(int* arr, int startIndex, int stopIndex);
int partition(int* arr, int startIndex, int stopIndex);


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
	int* Array = new int[size];
	int i = 0;
	for (int i = 0; i < size; i++) { // while reading in each int into temp variable
		fin >> Array[i];
	}
	fin.close(); // close file

	displayArray(Array, size);

	quickSort(Array, size);

	displayArray(Array, size);


	/*
	* As with the simple sorts, the files to be sorted will begin with a count, followed by at least that meny data items. 
	Your program should prompt the user for the input file, read the file, display the (unsorted) data, sort the data, display the sorted data, 
	and write the sorted data to a file, and give the sorting metrics.
	For the file name, use the original file name with "_sorted" appended to the name. 
	So if the input file was MyNumbers.txt the sorted file will be MyNumbers_sorted.txt.
	*/

	string fileName2;
	for (int i = 0; i < fileName.length() - 4; i++)
	{
		fileName2 += fileName[i];
	}

	fileName2 += "_sorted.txt";

	ofstream fout; // output file stream
	fout.open(fileName2); // open first file
	if (!fout) { // if file does not open...
		cout << "ERROR opening file " << fileName2 << "!!!" << endl; // Error message
		exit(EXIT_FAILURE); // Exit program
	}

	for (int i = 0; i < size; i++)
	{
		fout << Array[i] << " "; // write the array to the file
	}
	fout.close(); // close file

	cout << "Metrics are: \n";
	cout << "Comparisions: " << comparisonCount << endl;
	cout << "Exchanges : " << exchangeCount << endl;
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

void swapElement(int& i, int& j) {

	exchangeCount++;

	int temp;

	temp = i;
	i = j;
	j = temp;
}

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

void quickSort(int* arr, int theSize) {
	//cout << "Check 1\n";[TESTING]
	quickSort(arr, 0, theSize - 1);
}

void quickSort(int* arr, int startIndex, int stopIndex) {
	
	//base case
	//cout << "Check 2\n";[TESTING]
	if ((stopIndex - startIndex) <= SMALL_LIST_SIZE) {
		//cout << "Check 3\n";[TESTING]
		insertionSort(arr + startIndex, stopIndex - startIndex + 1);;
	}
	else { // general case (recursive)
	//cout << "Check 4\n";[TESTING]
		setMedianOfThree(arr, startIndex, stopIndex);
		int partitionElement = partition(arr, startIndex, stopIndex);
		quickSort(arr, startIndex, partitionElement - 1);
		quickSort(arr, partitionElement + 1, stopIndex);
	}
}

/*

*Fix insertion sort; according to powerpoint explanation...
* So you have to write

	#1 *The Set Median of Three algorithm. setMedianOfThree() function!
	It's just a few lines of code. 

	#2 *The partitioning algorithm. partition(arr, startIndex, stopIndex) function
	We went over this in detail.
	This returns the index where the pivot element ended up.

	*Might not need the exchange + comparison counters (double check directions in hw on moodle + powerpoint) or even the swap/compareElement functions

*/

// #1
void setMedianOfThree(int* arr, int startIndex, int stopIndex) {

	int firstElement, lastElement, centerElement;

	firstElement = arr[startIndex]; 
	lastElement = arr[stopIndex]; 
	centerElement = arr[(startIndex + stopIndex) / 2];

	//cout << "First element: " << firstElement << endl;[TESTING]
	//cout << "Last element: " << lastElement << endl;[TESTING]
	//cout << "Center element: " << centerElement << endl;[TESTING]
	//Now find median value of the three

	if ((lastElement >= centerElement && lastElement <= firstElement) || (lastElement >= firstElement && lastElement <= centerElement)) // if lastElement is median
	{
		swapElement(arr[startIndex], arr[stopIndex]);
		//cout << "check 5\n";[TESTING]
		//cout << "Median element: " << arr[startIndex] << endl;[TESTING]
		return;
	}

	if ((centerElement >= lastElement && centerElement <= firstElement) || (centerElement >= firstElement && centerElement <= lastElement)) // if centerElement is median
	{
		swapElement(arr[(startIndex + stopIndex) / 2], arr[stopIndex]);
		//cout << "check 6\n";[TESTING]
		//	cout << "Median element: " << arr[startIndex] << endl;[TESTING]
		return;
	}

	//cout << "Median element: " << arr[startIndex] << endl; [TESTING]
}

// #2
int partition(int* arr, int startIndex, int stopIndex) {

	int size = (stopIndex - startIndex + 1);
	int pivotPointer = startIndex;
	int freePointer = stopIndex;

	//displayArray(arr, size);[TESTING]
	while (pivotPointer != freePointer) {
		if (pivotPointer < freePointer && !compareElement(arr[pivotPointer], arr[freePointer])) { // if left element is less than right element  arr[pivotPointer] > arr[freePointer]
			//cout << arr[pivotPointer] << " > " << arr[freePointer] << endl;[TESTING]
			swapElement(arr[pivotPointer], arr[freePointer]); // swap the two
			swapElement(pivotPointer, freePointer); // and swap the index of the pointers
		}
		else if (freePointer < pivotPointer && !compareElement(arr[freePointer], arr[pivotPointer])) { // arr[pivotPointer] < arr[freePointer]

			//cout << arr[pivotPointer] << " < " << arr[freePointer] << endl;[TESTING]
			swapElement(arr[pivotPointer], arr[freePointer]); // swap the two
			swapElement(pivotPointer, freePointer); // and swap the index of the pointers
		}
		else { // else if right side is less than left
			//cout << arr[pivotPointer] << " ()()()()() " << arr[freePointer] << endl;[TESTING]
			//cout << "third type\n";[TESTING]
			if (freePointer < pivotPointer) { // and if freePointer is on the left
				freePointer++; // increment freePointer
			}
			else { //  else if free pointer is on the right
				freePointer--; //decrement free pointer
			}
		}
	}

	//cout << "Partition index: " << pivotPointer << endl;[TESTING]
	//displayArray(arr, size);[TESTING]
	return pivotPointer;
}
