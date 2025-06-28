#include <iostream>
#include <vector>
#include <string>
using namespace std;


//Prototypes:
vector<int> toDigits(string s);
int valueOf(char c); // convert the character representation of a digit into its integer value
void displayDecimalDigits(vector<int> v);  // display the entire vector
vector<int> trimLeadingZeros(vector<int> v); // trims leading zeros from result
vector<int> addLeadingZeros(vector<int> v, int zeros); // add leading zeros to vector with a lesser size
vector<int> normalize(vector<int> v, int b); // normalizes the result
vector<int> add(vector<int> v1, vector<int> v2); // add the vectors


void BigIntegerMultiplication(vector<int> v1, vector<int> v2) {
	// Trim any leading zeros before beginning
	int counterV1 = 0, counterV2 = 0;
	for (int i = 0; i < v1.size(); i++) { // checks if vector v1 only contains 0, if so return and cout that final Product is 0
		if (v1[i] == 0) {
			counterV1++;
		}
	}
	for (int i = 0; i < v2.size(); i++) { // checks if vector v2 only contains 0, if so return and cout that final Product is 0
		if (v2[i] == 0) {
			counterV2++;
		}
	}
	if (counterV1 == v1.size() || counterV2 == v2.size()) { // if either of the two contained only zeros, display "Final Product = 0 and exit function early!
		cout << "Final Product = 0" << endl;
		cout << endl;
		return;
	}

	v1 = trimLeadingZeros(v1); // now we have the correct v1
	v2 = trimLeadingZeros(v2); //  and the correct v2 vectors(num1 and num2)
	//cout << "check 1\n";
	//displayDecimalDigits(v1);
	//cout << endl;
	//displayDecimalDigits(v2);
	//cout << endl;
	vector<int> temp; // to hold temp version of v1
	vector<char> s;
	int count = 0; // counter for how many zeros to add onto end of num2


	vector<int> accumulator; // accumulator to store running total
	accumulator.push_back(0); // start accumulator with value of 0


	for (int i = v2.size() - 1; i >= 0; i--) { // loops for amount of digits in num2
		temp.clear(); // clear temp vector

		for (int b = 0; b < v1.size(); b++) {
			temp.push_back(v1[b]); //pushback all of vector1 into temp vector
		//	cout << "pushing back: " << v1[b] << endl;
		}
		for (int d = 0; d < count; d++) { // adds zeros to end for the value of count
			temp.push_back(0); // push back extra 0's onto temp vector
		}

		//cout << "temp is: ";
		//displayDecimalDigits(temp); // Display temp(num1 at current shift/with 0's added)


		//cout << "number 2 is:  " << v2[i] << endl; // display current digit of num2 for current index of i


		for (int f = 0; f < v2[i]; f++) { // iterates for current index value : example -> 432 second iteration... then v2[i] = 3, iterates 3 times.
			accumulator = add(accumulator, temp); // this is basically accumulator += temp (temp is number 1, with a "count" number of zeros added to the end for each shift)
			//cout << "accumulator is: ";
			//displayDecimalDigits(accumulator);
			//cout << endl;
		}
		count++; // increment count counter
	}
	cout << "Final Product = "; // display Final Product = 
	displayDecimalDigits(accumulator); // then display the final product
	cout << endl;
}

int main()
{
	string s1, s2; // Intitialize variables
	int count = 0;
	
	while (s1 != "0" || s2 != "0") {

		cout << "Enter first number: "; // prompt for first number
		cin >> s1; // store first number in variable s1	

		cout << "Enter second number: "; // prompt for second number
		cin >> s2; // store second number in variable s2
		
		vector<int> v1 = toDigits(s1); // set values from string s1 to vector v1
		vector<int> v2 = toDigits(s2); // set values from string s2 to vector v2
	
		//displayDecimalDigits(v1);
		//cout << endl;
		//displayDecimalDigits(v2);
		//cout << endl;	

		if (s1 == "0" && s2 == "0") {
		
			break;
		
		}	
		BigIntegerMultiplication(v1, v2);	
		count++;
	}
	cout << count << " Number of multiplications were performed!\n";
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
	cout << endl;
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