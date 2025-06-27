// Daniel Harrison
// occc - C++ Programming
// Homework - Roman Numbers.cpp

#include <iostream>
#include <string>
using namespace std;

// Prototypes go here:
bool isValidDecimalNumber(string s);
bool isValidRomanNumber(string s);
string convertRomanToDecimal(string s);
string convertDecimalToRoman(string s);

int main()
{
	bool flag = true;
	int valuesConverted = 0, decimalToRoman = 0, romanToDecimal = 0, invalidEntries = 0;
	int totalConvertedDECIMAL = 0, totalConvertedROMAN = 0;
	string userInput;

	cout << "Welcome to Roman Number Conversion!\n";
	while (flag == true) // flag to control the while loop
	{
		cout << "Please enter a value to convert: ";
		cin >> userInput; // Take user input

		//converts string to uppercase
		for (char& c : userInput)
		{
			c = toupper(c);
		}

		/* checks for the value 0 or O;
		if detected as a single value, program will display values converted and exit program */
		if (userInput == "0" || userInput == "O")
		{
			cout << valuesConverted << " numbers were converted ( " << decimalToRoman << " Decimal to Roman, " << romanToDecimal << " Roman to Decimal )\n";
			cout << "Thank you for playing Roman Number Conversion!\n";
			flag = false;
			break;
		}

		if (isValidDecimalNumber(userInput))
		{
			string converted;

			converted = convertDecimalToRoman(userInput);
			int tempDEC = stoi(userInput);
			totalConvertedDECIMAL += tempDEC;

			cout << userInput << " (Decimal) is " << converted << " (Roman)" << endl;
			valuesConverted += 1;// Incrememnt values converted by 1
			decimalToRoman += 1;// Incrememnt decimal to roman values converted by 1
		}
		else if (isValidRomanNumber(userInput))
		{
			string converted2;
			//cout << "Valid Roman!\n";
			converted2 = convertRomanToDecimal(userInput);

			if (converted2 == "invalid")
			{
				cout << "ERROR! -> Invalid input: " << userInput << endl;
				invalidEntries++;
			}
			else
			{
				int tempROM = stoi(converted2);
				totalConvertedROMAN += tempROM;
				cout << userInput << " (Roman) is " << converted2 << " (Decimal)" << endl;
				valuesConverted += 1;// Incrememnt values converted by 1
				romanToDecimal += 1; // Incrememnt roman to decimal values converted by 1
			}
		}
	}
}

bool isValidDecimalNumber(string s)
{

	for (int i = 0; i < s.length(); i++) // loop for making sure every character in the string is a digit
	{
		if (isdigit(s[i]) == false) // If one of the characters in the string is not a number, return false
		{
			return false;
		}
	}
	return true; // If all of the characters in the string are digits, return true
}

bool isValidRomanNumber(string s)
{
	char symbol[] = { 'M','D','C','L','X','V','I' }; // Valid roman symbols
	for (int i = 0; i < s.length(); i++) // array for checking each character in the string
	{
		// Compares current index of user string with each Symbol to make sure it is a valid symbol
		if ((s[i]) != symbol[0] && (s[i]) != symbol[1] && (s[i]) != symbol[2] && (s[i]) != symbol[3] && (s[i]) != symbol[4] && (s[i]) != symbol[5] && (s[i]) != symbol[6])
		{
			cout << "I did not understand input " << s << endl;
			return false; // If the character is not one of the roman symbols, return false
		}
	}
	return true; // If all characters in the string are roman symbols, return true
}
string convertDecimalToRoman(string s)
{
	string convertedString; // holds the converted string

	int num = stoi(s); // converts string s to integer value


	while (num > 0) // continues until the decimal number has been consumed
	{
		if (num >= 1000 && convertedString[0] != 'M')
		{
			num -= 1000;
			convertedString += "M";
		}
		else if (num >= 999)
		{
			num -= 999;
			convertedString += "IM";
		}
		else if (num >= 900)
		{
			num -= 900;
			convertedString += "CM";
		}
		else if (num >= 500)
		{
			num -= 500;
			convertedString += "D";
		}
		else if (num >= 450)
		{
			num -= 450;
			convertedString += "LD";
		}
		else if (num >= 400)
		{
			num -= 400;
			convertedString += "CD";
		}
		else if (num >= 100)
		{
			num -= 100;
			convertedString += "C";
		}
		else if (num >= 90)
		{
			num -= 90;
			convertedString += "XC";
		}
		else if (num >= 50)
		{
			num -= 50;
			convertedString += "L";
		}
		else if (num >= 49)
		{
			num -= 49;
			convertedString += "IL";
		}
		else if (num >= 40)
		{
			num -= 40;
			convertedString += "XL";
		}
		else if (num >= 10)
		{
			num -= 10;
			convertedString += "X";
		}
		else if (num >= 9)
		{
			num -= 9;
			convertedString += "IX";
		}
		else if (num >= 5)
		{
			num -= 5;
			convertedString += "V";
		}
		else
		{
			num -= 1;
			convertedString += "I";
		}
	}

	return convertedString; // returns converted string
}

string convertRomanToDecimal(string s)
{
	string convertedString2;
	int accumulator = 0, previousValue = 0; // holds the decimal value being created from the conversion
	int tempA = 0, tempB = 0; // holds temp values from the symbols

	for (int i = 0; i < s.length(); i++)
	{
		tempA = 0, tempB = 0;
		//find value of current symbol and set tempA equal to the integer value
		if ((s[i]) == 'M')
		{
			tempA = 1000;
		}
		else if ((s[i]) == 'D')
		{
			tempA = 500;
		}
		else if ((s[i]) == 'C')
		{
			tempA = 100;
		}
		else if ((s[i]) == 'L')
		{
			tempA = 50;
		}
		else if ((s[i]) == 'X')
		{
			tempA = 10;
		}
		else if ((s[i]) == 'V')
		{
			tempA = 5;
		}
		else if ((s[i]) == 'I')
		{
			tempA = 1;
		}
		// -------------------------------------
				//find value of next symbol and set tempB equal to the integer value
		if ((s[i + 1]) == 'M')
		{
			tempB = 1000;
		}
		else if ((s[i + 1]) == 'D')
		{
			tempB = 500;
		}
		else if ((s[i + 1]) == 'C')
		{
			tempB = 100;
		}
		else if ((s[i + 1]) == 'L')
		{
			tempB = 50;
		}
		else if ((s[i + 1]) == 'X')
		{
			tempB = 10;
		}
		else if ((s[i + 1]) == 'V')
		{
			tempB = 5;
		}
		else if ((s[i + 1]) == 'I')
		{
			tempB = 1;
		}

		if ((tempB - tempA) > previousValue && previousValue > 0)
		{
			cout << tempB - tempA << " > " << previousValue << endl;
			return "invalid";
		}
		/*
			If the symbol you see is followed by a symbol of equal or lesser value
			Consume that symbol and add that value to the accumulator
		*/
		else if (tempA >= tempB)
		{
			previousValue = tempA;
		}
		/*
			If the symbol you see is followed by a symbol of greater value
			Consume both symbols and add their difference to the accumulator
		*/
		else if (tempA < tempB)
		{
			previousValue = (tempB - tempA);
			//cout << "accumulator: " << accumulator << " += temp B: "
			i++; // Increment counter by 1 to consume both symbols
		}
		accumulator += previousValue;
	}
	convertedString2 = to_string(accumulator); // converts the integer value to a string value
	return convertedString2; //returns converted string (decimal number)
}
