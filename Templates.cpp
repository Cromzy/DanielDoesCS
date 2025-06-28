#include<iostream>
#include<string>
#include<fstream>
#include"ComplexNumbers.h"
#include"RomanNumbers.h"
#include"BigInteger.h"

// Daniel Harrison
// OCCC C++
// BONUS HOMEWORK - Sorting with C++ Templates


using namespace std;

template<typename T>
void exchangeSort(T* theArray, int theSize) {
    T theBuffer;
    for (int k = 1; k < theSize; k++) {
        for (int i = 0; i < theSize - k; i++) {
            if (theArray[i] > theArray[i + 1]) {
                theBuffer = theArray[i];
                theArray[i] = theArray[i + 1];
                theArray[i + 1] = theBuffer;
            }
        }
    }
}

template<typename T>
void displayArray(T* arr, int theSize) {

    for (int i = 0; i < theSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


template<typename T>
void writeToFile(T* arr, int theSize, ofstream& fout) {
    
    for (int i = 0; i < theSize; i++) {
        fout << arr[i] << " ";
    }
    fout << endl;
}

int main()
{
    int size = 10;
    // variables:     
    int intInput;
    double dbInput;
    string strInput;
    ComplexNumber complexNumInput;
    RomanNumber romanNumInput;
    BigInteger bigIntInput;

    // arrays:
    int* intArr = new int[size];
    double* dbArr = new double[size];
    string* strArr = new string[size];
    ComplexNumber* complexNumArr = new ComplexNumber[size];
    RomanNumber* romanNumArr = new RomanNumber[size];
    BigInteger* bigIntArray = new BigInteger[size];

    ifstream fin;
    ofstream fout;
    string fileName, fileName2;

    cout << "Enter input filename: ";
    cin >> fileName;
   
    fin.open(fileName);
    if (!fin) { // if file does not open...
        cout << "ERROR opening input file " << fileName << "!!!" << endl; // Error message
        exit(EXIT_FAILURE); // Exit program
    }
    cout << "Enter output filename: ";
    cin >> fileName2;
    fout.open(fileName2);
    
    // store int array
    for (int i = 0; i < size; i++) { // read next 10 entries from file
        fin >> intInput;
        intArr[i] = intInput; // store in intArr
    }
    // display int array
    fout << "Type: Integer\n";
    fout << "Unsorted: ";
    cout << "Unsorted: ";
    writeToFile(intArr, size, fout);
    displayArray(intArr, size);
    // sort int array
    exchangeSort(intArr, size);
    // display sorted int array
    cout << "Sorted: ";
    fout << "Sorted: ";
    writeToFile(intArr, size, fout);
    displayArray(intArr, size);
    cout << endl;
    fout << endl;
    // store double array
    for (int i = 0; i < size; i++) { // read next 10 entries
        fin >> dbInput;
        dbArr[i] = dbInput; // store in dbArr
    }
    // display double array
    fout << "Type: Double\n";
    fout << "Unsorted: ";
    cout << "Unsorted: ";
    writeToFile(dbArr, size, fout);
    displayArray(dbArr, size);
    // sort double array
    exchangeSort(dbArr, size);
    // display double array
    cout << "Sorted: ";
    fout << "Sorted: ";
    writeToFile(dbArr, size, fout);
    displayArray(dbArr, size);
    cout << endl;
    fout << endl;

    // store string array
    for (int i = 0; i < size; i++) { // read next 10 entries
        fin >> strInput;
        strArr[i] = strInput; // store in dbArr
    }
    // display string array
    fout << "Type: String\n";
    fout << "Unsorted: ";
    cout << "Unsorted: ";
    writeToFile(strArr, size, fout);
    displayArray(strArr, size);
    // sort string array
    exchangeSort(strArr, size);
    // display sorted string array
    cout << "Sorted: ";
    fout << "Sorted: ";
    writeToFile(strArr, size, fout);
    displayArray(strArr, size);
    cout << endl;
    fout << endl;

    // store complexNumber array
    for (int i = 0; i < size; i++) { // read next 10 entries
        fin >> complexNumInput;
        complexNumArr[i] = complexNumInput; // store in dbArr
    }
    // display complexNumber array
    fout << "Type: ComplexNumber\n";
    fout << "Sorted: ";
    cout << "Unsorted: ";
    writeToFile(complexNumArr, size, fout);
    displayArray(complexNumArr, size);
    // sort the complexNumber array
    exchangeSort(complexNumArr, size);
    // display sorted complexNumber array
    cout << "Sorted: ";
    fout << "Sorted: ";
    writeToFile(complexNumArr, size, fout);
    displayArray(complexNumArr, size);
    cout << endl;
    fout << endl;

    // store romanNumber array
    for (int i = 0; i < size; i++) { // read next 10 entries
        fin >> romanNumInput;
        romanNumArr[i] = romanNumInput; // store in dbArr
    }
    // display romanNumber array
    fout << "Type: RomanNumber\n";
    fout << "Unsorted: ";
    cout << "Unsorted: ";
    writeToFile(romanNumArr, size, fout);
    displayArray(romanNumArr, size);
    // sort the romanNumber array
    exchangeSort(romanNumArr, size);
    // display sorted romanNumber array
    cout << "Sorted: ";
    fout << "Sorted: ";
    writeToFile(romanNumArr, size, fout);
    displayArray(romanNumArr, size);
    cout << endl;
    fout << endl;

    // store bigInteger array
    for (int i = 0; i < size; i++) { // read next 10 entries
        fin >> bigIntInput;
        bigIntArray[i] = bigIntInput; // store in dbArr
    }
    // display bigInteger array
    fout << "Type: BigInteger\n";
    fout << "Unsorted: ";
    cout << "Unsorted: ";
    writeToFile(bigIntArray, size, fout);
    displayArray(bigIntArray, size);
    // sort the bigInteger array
    exchangeSort(bigIntArray, size);
    // display sorted bigInteger array
    cout << "Sorted: ";
    fout << "Sorted: ";
    writeToFile(bigIntArray, size, fout);
    displayArray(bigIntArray, size);
    cout << endl;
    fout << endl;

    // Close the files
    fin.close();
    fout.close();

    return 0;
}