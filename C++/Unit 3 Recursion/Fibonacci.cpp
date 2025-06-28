#include <iostream>
#include <string>
#include <vector>

// Daniel Harrison
// OCCC C++
// BigInteger Fibonacci Program with Recursion and memoization

using namespace std;

//Prototypes:
vector<int> toDigits(string s);
int valueOf(char c); // convert the character representation of a digit into its integer value
void displayDecimalDigits(vector<int> v);  // display the entire vector
vector<int> trimLeadingZeros(vector<int> v); // trims leading zeros from result
vector<int> addLeadingZeros(vector<int> v, int zeros); // add leading zeros to vector with a lesser size
vector<int> normalize(vector<int> v, int b); // normalizes the result
vector<int> add(vector<int> v1, vector<int> v2); // add the vectors

vector<int> fib_loop(int n);
vector<int> fib_recursive(int n, vector<vector<int>>& theMemo);
int main() {

	clock_t start, finish;
	double elapsedTime;

	int n;
	cout << "How many Fibonacci numbers do you want: ";
	cin >> n;
	vector<int> result;

	// loop version (faster)
	cout << "Using Loops\n";
	start = clock();
	result = fib_loop(n);
	cout << endl;
	cout << "fib(" << n << ") = ";
	displayDecimalDigits(result); // display the value of the Fibonacci number prompted for at the beginning of program "cin >> n"
	cout << endl;
	finish = clock();
	elapsedTime = (finish - start) / CLOCKS_PER_SEC;
	cout << "Time required = " << elapsedTime << " seconds " << endl;
	cout << endl;

	// recursive version (slower)
	cout << "Using Recursion\n";
	start = clock();
	vector<vector<int>> theMemo(n + 1); // memoization vector that will make the recursive function operate more effectively
	result = fib_recursive(n, theMemo);
	cout << endl;
	cout << "fib(" << n << ") = ";
	displayDecimalDigits(result); // display the value of the Fibonacci number prompted for at the beginning of program "cin >> n"
	cout << endl;
	finish = clock();
	elapsedTime = (finish - start) / CLOCKS_PER_SEC;
	cout << "Time required = " << elapsedTime << " seconds " << endl;
	
}

vector<int> toDigits(string a)
{
	vector<int> result(a.length());
	for (unsigned int i = 0; i < result.size(); i++)
	{
		result[i] = valueOf(a[i]); // calls on valueOf function that returns int value of char at current index
	}
	return result; // reuturns the vector<int> result created from the string parameter
}

int valueOf(char a) 
{
	if (isdigit(a)) //if char is a digit convert to a string by adding it to tempStr and using stoi to convert to int
	{
		string tempStr;
		tempStr += a;

		return stoi(tempStr);
	}
	else {
		//else
		a = toupper(a); // converts char to uppercase

		switch (a) { // returns hexadecimal value based on the char value
		case 'A': return 10;
		case 'B': return 11;
		case 'C': return 12;
		case 'D': return 13;
		case 'E': return 14;
		case 'F': return 15;
		case 'G': return 16;
		case 'H': return 17;
		case 'I': return 18;
		case 'J': return 19;
		case 'K': return 20;
		case 'L': return 21;
		case 'M': return 22;
		case 'N': return 23;
		case 'O': return 24;
		case 'P': return 25;
		case 'Q': return 26;
		case 'R': return 27;
		case 'S': return 28;
		case 'T': return 29;
		case 'U': return 30;
		case 'V': return 31;
		case 'W': return 32;
		case 'X': return 33;
		case 'Y': return 34;
		case 'Z': return 35;
		}
	}
}
	void displayDecimalDigits(vector<int> a) // Display the vector at each index
	{
		for (unsigned int i = 0; i < a.size(); i++) {
			cout << a[i];
		}
		cout << " ";
	}
	vector<int> trimLeadingZeros(vector<int> v)
	{
		int count = 0;
		for (unsigned int i = 0; i <= v.size(); i++)
		{
			if (v[i] == 0)
			{
				++count; // count number of leading zeros
			}
			else
			{
				break;
			}
		}
		// Then...
		vector<int> result(v.size() - count); // subtract the number of leading zeros from the vector size
		for (unsigned int i = count, r = 0; i < v.size(); r++, i++)
		{
			result[r] = v[i]; // set the value of the result vector at each index equal to the original vector
		}
		return result;
	}
	vector<int> addLeadingZeros(vector<int> v, int zeros) 
	{
		vector<int> result;
		for (unsigned int i = 0; i < zeros; i++)
		{
			result.push_back(0); // Pushback the required number of leading zeros
		}
		for (unsigned int i = 0; i < v.size(); i++)
		{
			result.push_back(v[i]); // Pushback the rest of the vector
		}

		return result;
	}
	vector<int> normalize(vector<int> v, int b) // Normalizes the result
	{
		vector<int> result = v;
		result = addLeadingZeros(result, 1);
		for (int i = result.size() - 1; i >= 0; --i)
		{
			while (result[i] >= b)
			{
				result[i] -= b;
				result[i - 1] += 1;
			}
		}
		trimLeadingZeros(v);
		return result;
	}
	vector<int> add(vector<int> v1, vector<int> v2) 
	{
		if (v1.size() < v2.size()) // if v1.size is less than v2.size
		{
			v1 = addLeadingZeros(v1, v2.size() - v1.size()); // add zeros to v1 to make the sizes equivalent
		}
		else if (v2.size() < v1.size()) // if v2.size is less than v1.size
		{
			v2 = addLeadingZeros(v2, v1.size() - v2.size()); // add zeros to v2 to make the sizes equivalent
		}

		// now v1.size() = v2.size(), so we then...
		vector<int> result(v1.size()); // declare result equal to the size of vector v1

		// Add the values place by place
		for (int i = v1.size() - 1; i >= 0; --i) { // v1.size - 1 because index starts at 0, continune until i = 0, decremeant by 1
			result[i] = v1[i] + v2[i]; // add values place by place (at each index) to the result vector.
		}

		// Normalize the result
		result = normalize(result, 10);
		result = trimLeadingZeros(result);

		return result; // return result
	}

	vector<int> fib_loop(int n) {

		string s1 = "1", s2 = "1", s3 = "2"; // Intitialize variables

		vector<int> result;
			vector<int> total;
		if (n == 1) {

			 result = toDigits(s1);
			total = toDigits(s1);
		}

		if (n == 2) {

			result = toDigits(s1);
			total = toDigits(s3);
		}

		if (n > 2) {

			vector<int> v1 = toDigits(s1); // set values from string s1 to vector v1
			vector<int> v2 = toDigits(s2); // set values from string s2 to vector v2
			result; // Current Fibonacci Number contained here
			total = toDigits(s3); // Running total starts equal to 2 because first two Fibonacci numbers are 1 and 1
			for (int count = 3; count <= n; count++)
			{
				result = add(v1, v2); // add current and previous number together
				total = add(total, result);
				v1 = v2; // set previous equal to current
				v2 = result; // set current equal to result

			} // repeat loop...
		}

		cout << "Running total: "; // display running total of "n" amount of Fibonacci numbers
		displayDecimalDigits(total);
		cout << endl;

		return result;
	}

	vector<int> fib_recursive(int n, vector<vector<int>>& theMemo) {
		string s1 = "1", s2 = "1";

		// Base cases
		if (n == 1 || n == 2) {
			return toDigits(s1);  // Return the first Fibonacci number as [1]
		}

		// Check if result is already memoized
		if (!theMemo[n].empty()) {
			return theMemo[n];
		}
		else {
			// Recursive call to compute Fibonacci numbers
			vector<int> result = add(fib_recursive(n - 1, theMemo), fib_recursive(n - 2, theMemo));
			theMemo[n] = result; // Store result in memo array
			return result;
		}
	}

