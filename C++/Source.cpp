#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <vector>

// Daniel Harrison
// Binary Merge Sort & Natural Merge Sort
// OCCC C++

using namespace std;



bool binaryMerge(ifstream& if1, ifstream& if2, int mergeDepth, ofstream& of) { // Professors code, no need to change it (Implement into the binaryMergeSort function)
	int count1 = 0, count2 = 0;
	bool file1 = true, file2 = true;
	int buffer1, buffer2;

	if (if1 >> buffer1) {}
	else file1 = false;

	if (if2 >> buffer2) {}
	else file2 = false;

	if (!file1 && !file2) {
		return false; // No more data to merge
	}

	while (file1 && file2) {
		if (buffer1 < buffer2) {
			of << buffer1 << " ";
			count1++;
			if (count1 < mergeDepth && (if1 >> buffer1)) {}
			else {
				file1 = false; // reached merge depth or end of file
				break;
			}
		}
		else {
			of << buffer2 << " ";
			count2++;
			if (count2 < mergeDepth && (if2 >> buffer2)) {}
			else {
				file2 = false; // reached merge depth or end of file
				break;
			}
		}
	}

	while (file1 && count1 < mergeDepth) {
		of << buffer1 << " ";
		count1++;
		if (!(if1 >> buffer1)) {
			file1 = false; // End of file
		}
	}

	while (file2 && count2 < mergeDepth) {
		of << buffer2 << " ";
		count2++;
		if (!(if2 >> buffer2)) {
			file2 = false; // End of file
		}
	}

	return true; // Merge complete
}
void binaryMergeSort(string& unsorted) {
	
	
	bool flag = true;
	int temp;
	int pair = 1;
	
	while (flag) {

		ifstream fin; // input file stream
		fin.open(unsorted); // open file
		if (!fin) { // if file does not open...
			cout << "ERROR opening file " << unsorted << "!!!" << endl; // Error message
			exit(EXIT_FAILURE); // Exit program
		}

		ofstream tempOut("temp1.txt"), tempOut2("temp2.txt");
		int count = 0;
		int size = 0;
		flag = false;
		int counter = 0;
		while (fin >> temp) {
			if (count < pair) {
				tempOut << temp << " ";
				count++;
			}
			else if(count > 0){
				tempOut2 << temp << " ";
				count--;
			}
			
		}
		fin.close();
		tempOut.close();
		tempOut2.close();
		ofstream fout(unsorted);
		ifstream tempIf("temp1.txt"), tempIf2("temp2.txt");
		
		
			if (binaryMerge(tempIf, tempIf2, pair, fout)) {
				cout << "Merged\n";
		}
			else {
				cout << "Merge Failed\n";
			}


		for(int i = 0; i < pair; i++){}
		
		


		pair *= 2;
	}

}


void naturalMergeSort(string& unsorted) {
	int passes = 0; // count of passes through while loop
	bool flag = true; // tracks if more passes are needed
	ifstream fin;
	int tracker = 1;
	while (flag) {
		
		flag = false;
		fin.open(unsorted); // open main file
		if (!fin) {
			cout << "ERROR opening file " << unsorted << "!!!" << endl;
			exit(EXIT_FAILURE);
		}

		// Open output files to replace top and bottom vectors
		ofstream topOut("top.txt");
		ofstream bottomOut("bottom.txt");

		int current, previous = 0;
		int change = 0;
		int topCounter = 0;
		int bottomCounter = 0;

		// Reads file from the main file into two separate disks
		while (fin >> current) {
			if (previous != 0) {
				if (change == 0) {
					if (current < previous) { // if current value being read is less than previous
						change++; // change counter keeps track if you should keep writing into the bottom or switch to the top 
						bottomOut << current << " "; // add to bottom sublist
						cout << "Bottom list: " << current << endl;
						bottomCounter++;
						flag = true;
					}
					else {
						topOut << current << " "; // add to top sublist
						cout << "top list: " << current << endl;
						topCounter++;
					}
				}
				else {
					if (current < previous) { // if current value being read is less than previous
						change--; // change counter keeps track if you should keep writing into the top or switch to the bottom 
						topOut << current << " "; // add to top sublist
						cout << "top list: " << current << endl;
						topCounter++;
					}
					else {
						bottomOut << current << " "; // add to bottom sublist
						cout << "Bottom list: " << current << endl;
						bottomCounter++;
						flag = true;
					}
				}
			}
			else {
				topOut << current << " "; // add first value to top
				cout << "top list: " << current << endl;
				topCounter++;

			}
			previous = current; // set previous value equal to current before going back to the top of the loop
		}
		cout << "TOP LIST " << topCounter << endl;
		cout << "BOTTOM LIST " << bottomCounter << endl;

		fin.close(); // close starting file
		topOut.close(); // close top sub-list
		bottomOut.close();

		cout << "START of merge" << tracker << endl;
		// Begin merging phase
		ofstream fout(unsorted); // output main file for sorted data
		ifstream topIn("top.txt"), bottomIn("bottom.txt");

		int topVal, bottomVal;
		bool topHasVal = bool(topIn >> topVal), bottomHasVal = bool(bottomIn >> bottomVal);
		int prev, 
			size = 0; // if just starting the merge...

		while (topHasVal && bottomHasVal) { 
			if (size == 0) {
				if (topVal < bottomVal) { // merge smallest starting value of the top and bottom sublists
					cout << "Merge " << topVal << " " << endl;
					fout << topVal << " "; // if top is smaller, merge top
					prev = topVal;
					topHasVal = bool(topIn >> topVal);
				}
				else {
					cout << "Merge " << bottomVal << " " << endl;
					fout << bottomVal << " "; // else merge bottom
					prev = bottomVal;
					bottomHasVal = bool(bottomIn >> bottomVal);
					flag = true;
				}
				size++;
			}
			else {  // if not the first number in the merge, come here...
				if (topVal <= bottomVal && topVal >= prev) { // if (top value <= bottom value) && (top value >= previous value), merge top value!
					cout << "Merge " << topVal << " " << endl;
					fout << topVal << " ";
					prev = topVal;
					topHasVal = bool(topIn >> topVal);
				}
				else if (bottomVal <= topVal && bottomVal >= prev) { // else if (bottom value <= top value) && (bottom value >= previous value), merge bottom value!
					cout << "Merge " << bottomVal << " " << endl;
					fout << bottomVal << " ";
					prev = bottomVal;
					bottomHasVal = bool(bottomIn >> bottomVal);
					flag = true;
				}
				else {  // else if not the first value and none of the conditions above apply
					if (topVal > prev) { // if top value is greater than previous, merge top!
						cout << "Merge " << topVal << " " << endl;
						fout << topVal << " ";
						prev = topVal;
						topHasVal = bool(topIn >> topVal);
					}
					else if (bottomVal > prev) { // else if bottom value is greater than previous, merge bottom!
						cout << "Merge " << bottomVal << " " << endl;
						fout << bottomVal << " ";
						prev = bottomVal;
						bottomHasVal = bool(bottomIn >> bottomVal);
						flag = true;
					}
					else if (topVal < bottomVal) { // if those conditions don't apply, restart by merging the smallest value
						cout << "Merge " << topVal << " " << endl;
						fout << topVal << " "; // if top is smaller, merge top!
						prev = topVal;
						topHasVal = bool(topIn >> topVal);
					}
					else {
						cout << "Merge " << bottomVal << " " << endl;
						fout << bottomVal << " "; // else if bottom is smaller, merge bottom!
						prev = bottomVal;
						bottomHasVal = bool(bottomIn >> bottomVal);
						flag = true;
					}
				}
			}
		}

		// append rest (if one of the lists is empty, merge the rest of the other list until it is also empty)
		while (topHasVal) {
			cout << "Merge " << topVal << " " << endl;
			fout << topVal << " ";
			topHasVal = bool(topIn >> topVal);
		}
		while (bottomHasVal) {
			cout << "Merge " << bottomVal << " " << endl;
			fout << bottomVal << " ";
			bottomHasVal = bool(bottomIn >> bottomVal);
		}


		fout.close();
		topIn.close();
		bottomIn.close();
		

		if (flag) { // if I had to continue to use a second list, meaning the sort wasn't finished, increment the passes counter!
			passes++;
		}
		cout << "end of merge\ " << tracker << endl;
		tracker++;
	}
	// This section deletes any remaining data from the code after the while loop has ended (file has been sorted)
	ofstream topOut("top.txt"), bottomOut("bottom.txt");
	topOut.close();
	bottomOut.close();

	// The name of the output file should be the same as the input file with _SORTED appended 
	string Output; 
	for (int i = 0; i < unsorted.length() - 4; i++) {
		Output += unsorted[i];
	}
	Output += "_SORTED.txt";

	fin.open(unsorted); // Open the "unsorted" now sorted file for reading
	ofstream fout(Output); // Open the Final file that will have _Sorted.txt Appeneded to the name for writing

	int num;
	while (fin >> num) { // Writes all the sorted data from the original unsorted file that has been sorted into a file filename_SORTED.txt file
		fout << num << " ";
	}
	cout << "Sorted using Natural Merge Sort and written to the file: " << Output << endl;
}


int main() {

	clock_t start, finish;
	double elapsedTime;
	

	string selection, unsortedFile;

	cout << "Welcome to the Merge sorts program\n";
	cout << "Please enter input file name: "; // prompt user input
	getline(cin, unsortedFile);


	do {
		cout << "Enter '1' for binaryMergeSort or Enter '2' for NaturalMerge Sort: ";
		cin >> selection;

	} while (selection != "1" && selection != "2");

	// Based on selection, use corresponding sort
	start = clock();
	if (selection == "1") {
		binaryMergeSort(unsortedFile);
	}
	else {
		naturalMergeSort(unsortedFile);
	}

	finish = clock();
	elapsedTime = (finish - start) / CLOCKS_PER_SEC;
	cout << fixed << setprecision(8);
	cout << "Time required for loop version = " << elapsedTime << " seconds " << endl;

	return 0;

}





