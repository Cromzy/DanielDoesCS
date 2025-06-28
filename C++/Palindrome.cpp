#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Daniel Harrison
// OCCC C++
// Palindrome Program

// Prototypes Here:
string strictPalindrome(string s); // remove punctuation and all text is upper case
string ordinaryPalindrome(string s); // punctuation and text is upper case has already happened... In addition, remove spaces.
bool palindrome_recursive(vector<char> v);

int main() {

	// Initialize variables and vector
	vector<char> v;
	string s, s_copy;
	bool strictTest = false, ordinaryTest = false, notPalindrome = false, hasSpace = false;

	cout << "Hello User!\n";

	do  {
		// reset variables and clear vector
		strictTest = false, ordinaryTest = false, notPalindrome = false, hasSpace = false;
		v.clear(); // Clear vector for next test

		// Prompt user for a string input or '1' to exit
		cout << "Enter a string (or enter '1' to exit): ";
		getline(cin, s); // retrieve the line and store it in string s
		
		if (s == "1") // check if '1' is detected to exit program, else continue...
			break; // break from loop

		s_copy = strictPalindrome(s); // remove punctuation and make all text uppercase

		// Check if there is at least one space in the input
		for (char c : s_copy)
		{
			if (c == ' ')
				hasSpace = true;
		}
		// If there's no space, strictTest must be set to false
		if (!hasSpace) {
			strictTest = false;
		}
		else {
			// Populate the vector and perform strict palindrome check
			for (int i = 0; i < s_copy.length(); i++) {
				v.push_back(s_copy[i]);
			}
			strictTest = palindrome_recursive(v); // Test strict palindrome
		}

		if (strictTest) // if strictTest is true then userInput is a strict palindrome
		{
			cout << s_copy << " is a strict palindrome" << endl;
		}

		v.clear(); // Clear vector for next test


		if (!strictTest) { // if strictTest is false
			s_copy = ordinaryPalindrome(s_copy); // take away the spaces from the string that was just used

			// copy the string value into the vector at each char
			for (int i = 0; i < s_copy.length(); i++) {
				v.push_back(s_copy[i]);
			}
			ordinaryTest = palindrome_recursive(v); // Test ordinary palindrome
			if (ordinaryTest) // if ordinary test comes is true, then userInput string is an ordinary palindrome
			{
				cout << s_copy << " is a ordinary palindrome" << endl;
			}
		}

		// Neither strict nor ordinary palindrome
		if (!strictTest && !ordinaryTest)
		{
			notPalindrome = true;
			cout << s << " is not a palindrome" << endl;
		}
	} while (s != "1");
}

// Strict palindrome: remove punctuation and convert to uppercase
string strictPalindrome(string s) {

	string result;
	for (char c : s)
	{
		if (isdigit(c) || c == ' ' || isalpha(c)){ // if current char is a digit, letter, or a space: add it to result string

			if (isalpha(c)) { // if char is a letter convert toUpper case
				c = toupper(c);
			}
			result += c; // add the current char to string result 
		}
	}
	return result; // return string result after the loop has finished
}
// Ordinary palindrome: remove spaces, keep digits and letters
string ordinaryPalindrome(string s) {

	string result;
	for (char c : s)
	{
		if (isdigit(c) || isalpha(c)) { // if current char is a letter or digit: add it to result string
			result += c; // add the current char to string result
		}
	}
	return result; // return string result after the loop has finished
}
// Recursive palindrome check
bool palindrome_recursive(vector<char> v) {

	// Base Case
	if (v.size() <= 1){ // if only 1 char is left in the vector, return true
		return true;
	}
	else{ // General Case
		if (v.front() != v.back()){ // if first char of vector is not equal to last char in the vector
			return false; // return false
		}
		else { // else...
			v.erase(v.begin()); // Remove the first character
			v.pop_back(); // Remove the last character
			return palindrome_recursive(v); // Recursive call (call the function again, repeating the recursive)...
		}
	}
}