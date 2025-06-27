// Daniel Harrison
// matrix addition
// c++
#include <iostream> // console Input/Output
#include <fstream>  // file Input/Output
#include <string>   // for fileName
#include <iomanip>  // for columns
using namespace std;

int main() {
	string fileName, fileName2;
	cout << "Please enter input file name: "; // prompt user input
	getline(cin, fileName);

	ifstream fin; // input file stream
	fin.open(fileName); // open first file
	if (!fin) { // if file does not open...
		cout << "ERROR opening file " << fileName << "!!!" << endl; // Error message
		exit(EXIT_FAILURE); // Exit program
	}

	// If we make it past the if statement above, the file is open and ready for use
	int numRows, numCols;
	fin >> numRows; // retrieve number of rows in the first matrix
	fin >> numCols; // retrieve number of columns in the first matrix

	double* * firstArray = new double* [numRows]; // create first array to store the first matrix

	for (int i = 0; i < numRows; i++) {
		firstArray[i] = new double[numCols]; // now we read the rest of the file and fill the first array
		for (int j = 0; j < numCols; j++) {
			fin >> firstArray[i][j];
		}
	}

	fin.close(); // close first file
	cout << endl;

	cout << "Please enter input file name: "; // prompt user input
	getline(cin, fileName2);
	fin.open(fileName2); // open second file
	if (!fin) { // if file does not open...
		cout << "ERROR opening file " << fileName2 << "!!!" << endl; // Error message
		exit(EXIT_FAILURE); // Exit program
	}

	// If we make it past the if statement above, the file is open and ready for use
	int numRows2, numCols2;
	fin >> numRows2; // retrieve number of rows in the second matrix
	fin >> numCols2; // retrieve number of columns in the second matrix

	// Checks to make sure the two matrices dimensions are equal
	if (numRows != numRows2 || numCols != numCols2)
	{
		cout << "Dimensions of the matrixes do NOT match!\n";
		return 0;
	}
	else
	{
		cout << "Dimensions of the matrixes DO MATCH, proceed.\n";
	}

	double** secondArray = new double* [numRows]; // create second array to store the second matrix

	for (int i = 0; i < numRows; i++) {
		secondArray[i] = new double[numCols]; // now we read the rest of the file and fill the second array
		for (int j = 0; j < numCols; j++) {
			fin >> secondArray[i][j];
		}
	}

	fin.close(); // close second file
	double** sumArray = new double* [numRows]; // then we create an array of that size

	for (int i = 0; i < numRows; i++) {
		sumArray[i] = new double[numCols]; // now we read the rest of the file and fill the array with the sum of the two Matrices
		for (int j = 0; j < numCols; j++) {
			sumArray[i][j] = firstArray[i][j] + secondArray[i][j];
		}
	}
	cout << "\n\n\n";

	cout << fixed << setprecision(2); // Sets the formatting to -> 2 digits after decimal place
	// display the contents of the array and exit
	cout << "Sum of the two Arrays\n";
	for (int r = 0; r < numRows; r++) {
		for (int c = 0; c < numCols; c++) { // format + displays first array
			cout << setw(9) << firstArray[r][c];
		}

		// used to space out the input for the '+' symbol
		if (r == numRows / 2)
		{
			cout << "   +";
		}
		else
			cout << "    ";

		for (int c2 = 0; c2 < numCols; c2++) { 
			cout << setw(9) << secondArray[r][c2]; // format + displays second array
		}
		
		// used to space out the input for the '=' symbol
		if (r == numRows / 2)
		{
			cout << "   =";
		}
		else
			cout << "    ";
		
		for (int c3 = 0; c3 < numCols; c3++) { // format + displays sum array
			cout << setw(9) << sumArray[r][c3];
		}

		cout << endl;
	}

	//Clean up the dynamic memory (from powerpoint notes)
	for (int i = 0; i < numRows; i++) { // Delete each row using for loop
		delete[] firstArray[i];
		delete[] secondArray[i];
		delete[] sumArray[i];
	}
	//Delete the array of pointers
	delete[] firstArray;
	delete[] secondArray;
	delete[] sumArray;

	return 0;
}
