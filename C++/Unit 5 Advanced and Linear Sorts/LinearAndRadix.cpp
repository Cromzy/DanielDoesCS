#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Daniel Harrison
// OCCC C++
// Linear and Radix Sorts

using namespace std;

int getDigitCount(int num) {
    int count = 0;
    if (num == 0) return 1; // Special case for 0, which has one digit
    while (num > 0) { // while num greater than 0, continue
        num /= 10; // num = num / 10
        count++; // increment count
    }
    return count; // after while loop is completes, return count
}

void radixSort(vector<int> v, string outputFileName) {
    if (v.size() < 2) return; // If vector has less than two numbers(return because it is already sorted)

    int largest = v[0]; // initialize largest with first value of first element
    int passes = 0; // initialize passes counter to zero

    // Find the largest value
    for (int i = 1; i < v.size(); i++) { // compare the largest value with the following value
        if (largest < v[i]) { // if largest is less than following value...
            largest = v[i]; // set largest to the following value
        } // go back through the loop
    }

    // Calculate number of passes needed
    passes = getDigitCount(largest); // uses getDigitCount() function which calculates how many digits are in a number

    vector<int> buckets[10]; // declare Array of vectors to act as buckets

    // Iterate through the number of digits
    for (int i = 0; i < passes; i++) {
        // Clear buckets for the current pass
        for (int k = 0; k < 10; k++) {
            buckets[k].clear();
        }

        // Distribute numbers into buckets based on the current digit
        for (int j = 0; j < v.size(); j++) {
            // Calculate divisor for the current place (1 for units, 10 for tens, etc.)
            int divisor = 1;
            for (int k = 0; k < i; k++) {
                divisor *= 10;  // Get the right place value
            }

            // Gets the digit at the current place value
            int digit = (v[j] / divisor) % 10; // This works fine even for numbers with fewer digits

            // Pushes value into correct bucket by using digit as 'index'
            buckets[digit].push_back(v[j]);
        }

        // After going through the entire original vector 'v'
        v.clear(); // Clear original vector so that it can be refilled

        for (int k = 0; k < 10; k++) { // Loop through buckets 0-9
            for (int a = 0; a < buckets[k].size(); a++) {
                v.push_back(buckets[k][a]); // push back the entire bucket onto the original vector 'v'
            }
        }
    }
    // Now that we finished the radixSort

    // Open the output file
    ofstream fout; // output file stream
    fout.open(outputFileName); // open output file
    if (!fout) { // if file does not open...
        cout << "ERROR opening file " << outputFileName << "!!!" << endl; // Error message
        exit(EXIT_FAILURE); // Exit program
    }

    // Write the sorted output to the file
    fout << "Sorted output from radix sort:\n";
    for (int num : v) {
        fout << num << " "; // Write sorted numbers to output file
    }
    fout << endl; // New line after sorted output
    fout.close(); // Close the output file
    cout << "Sorted disk written to " << outputFileName << endl;
}

void countingSort(vector<int> v, string outputFileName) {
    if (v.size() < 2) return; // If vector has less than two numbers(return because it is already sorted)

    // Initialize largest and smallest
    int largest = v[0];
    int smallest = v[0];

    // Find the largest and smallest values
    for (int i = 1; i < v.size(); i++) {
        if (largest < v[i]) {
            largest = v[i];
        }
        if (smallest > v[i]) {
            smallest = v[i];
        }
    }

    int range = largest - smallest + 1;

    // Create a count array to store the count of each number
    int* Array = new int[range](); // Using () to zero-initialize the array

    // Count occurrences of each number
    for (int i = 0; i < v.size(); i++) {
        int num = v[i];
        Array[num - smallest]++;
    }

    // Open the output file
    ofstream fout; // output file stream
    fout.open(outputFileName); // open output file
    if (!fout) { // if file does not open...
        cout << "ERROR opening file " << outputFileName << "!!!" << endl; // Error message
        exit(EXIT_FAILURE); // Exit program
    }

    // Print sorted output
    fout << "Sorted output from counting sort:\n";
    for (int i = 0; i < range; i++) {
        for (int a = 0; a < Array[i]; a++) {
            fout << (i + smallest) << " "; // Print the number based on count
        }
    }
    fout << endl; // New line after sorted output

    cout << "Sorted disk written to " << outputFileName << endl;

    delete[] Array; // Delete Array to save memory
    fout.close(); // Close the output file
}

int main() {
    cout << "Welcome to the linear and radix sorting program\n";
    string fileName;
    cout << "Enter input filename: ";
    getline(cin, fileName);

    string fileName2;
    cout << "Enter output filename: ";
    cin >> fileName2;

    vector<int> v; // Ensure the vector is declared here

    // Read data from the input file into vector 'v'
    ifstream fin(fileName); // open input file
    if (!fin) { // if file does not open...
        cout << "ERROR opening file " << fileName << "!!!" << endl; // Error message
        exit(EXIT_FAILURE); // Exit program
    }

    int data;
    while (fin >> data) { // Read data into the vector
        v.push_back(data);
    }
    fin.close(); // Close the input file after reading

    int selection;
    do {
        cout << "Enter 1 for radixSort or Enter 2 for countingSort: ";
        cin >> selection;
    } while (selection != 1 && selection != 2);

    if (selection == 1) {
        radixSort(v, fileName2); // Call countingSort with the vector 'v' and output filename
    }
    else if (selection == 2) {
        countingSort(v, fileName2); // Call countingSort with the vector 'v' and output filename
    }

    return 0;
}
