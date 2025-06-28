#include <iostream>
#include <ctime>
#include <iomanip>
// Daniel Harrison                    
// OCCC C++
// Factorial Loop vs Rescurive program 
using namespace std;

// Prototypes Here:
unsigned __int64 factorial_loop(int input);
unsigned __int64 factorial_recursive(int input);

int main() {

	clock_t start, finish;
	double elapsedTime;
	unsigned __int64 result = 0;

	int n;	// Highest factorial able to be computed and stored within the __int64 data type
	cout << "Enter a number for the factorial: ";
	cin >> n;

	
	start = clock();
	result = factorial_loop(n); // accumulates after each loop
	finish = clock();
	elapsedTime = (finish - start) / CLOCKS_PER_SEC;
	cout << fixed << setprecision(10);
	cout << "Time required = " << elapsedTime << " seconds " << endl;
	cout << "Sum of factorial from 0! to n! is: " << result << endl; // Display the sum of 0! to n!

	start = clock();
	result = factorial_recursive(n); // accumulates after each loop
	finish = clock();
	elapsedTime = (finish - start) / CLOCKS_PER_SEC;
	cout << fixed << setprecision(10);
	cout << "Time required = " << elapsedTime << " seconds " << endl;
	cout << "Sum of factorial from 0! to n! is: " << result << endl; // Display the sum of 0! to n!

}

unsigned __int64 factorial_loop(int input) { // Method to get the value of the current factorial
	unsigned __int64 result = 1; // result starts at 1 because 0! and 1! both equal 1...

	if (input > 1) { // formula for calculating factorials
		for (int i = 1; i <= input; i++)
		{
			result *= i; // factorial formula multiplies current value by previous value and set result equal to the product
		}
	}
	return result; // return result
}

unsigned __int64 factorial_recursive(int n) {
	unsigned __int64 result = 1;

	if (n > 1) {
		result = n * factorial_recursive(n - 1);
	}
	return result;
}
