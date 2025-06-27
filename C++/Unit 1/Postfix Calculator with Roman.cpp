#include <iostream>
#include <vector>//allows for use of vectors
#include <string>//allows for conversion of strings to ints

using namespace std;

int calculation(int a, int b, char opera) {

    cout << "operator: " << opera << " "; // CHECKPOINT
    if (opera == '+') return a + b; //if operator received is a additional symbol  a + b
    if (opera == '-') return b - a; //if operator received is a subtraction symbol  b - a
    if (opera == '*') return a * b; //if operator received is a multiplication symbol  a * b
    if (opera == '/') return b / a; //if operator received is a division symbol  b / a
    if (opera == '%') return b % a; //if operator received is a modulus symbol  b % a

    return a;
}

bool isValidRomanNumber(char c)

{
   
    char symbol[] = { 'M','D','C','L','X','V','I' }; // Valid roman symbols
        // Compares current index of user string with each Symbol to make sure it is a valid symbol
        if (c != symbol[0] && c != symbol[1] && c != symbol[2] && c != symbol[3] && c != symbol[4] && c != symbol[5] && c != symbol[6])
        {
            //cout << "I did not understand input " << c << endl;
            return false; // If the character is not one of the roman symbols, return false
        }
    return true; // If all characters in the string are roman symbols, return true
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



string evaluatePostfix(string input)
{
    vector<int> v;//initialize the vector
    string temp = "";
    string tempCombine = "";
    string extraFlag = "";
    int result = 0;



    for (int i = 0; i < input.size(); i++) {
        //for loop, size of the string

        char c = input[i]; //set char c equal to the current index of the string
        if(!isdigit(c) && c != '-' && c != '+' && c != ' ')
        c = toupper(c);

        
        char tempC = input[i + 1];
        if (!isdigit(tempC) && tempC != '-' && tempC != '+' && tempC != ' ')
        tempC = toupper(c);

        if (c == ' ') {
            // if c equals a blank/white space

            if (temp != "") {
                //If temp does not equal empty
                v.push_back(stoi(temp));//Convert temp from string to int and push temp into vector, creating a new element.
               // cout << " [CHECK 1] Token = " << temp << " Push " << temp << endl;
                temp = "";
            }
            if (!isdigit(c) && tempCombine != "" && tempCombine != "-" && tempCombine != "+") {
                //If not a digit, tempCombine is not nothing, temp combine is not a unary operator.
                v.push_back(stoi(tempCombine)); //Convert tempCombine to an integer from a string, push tempCombine into the vector, creating a new element.
               // cout << " [CHECK 2] Token = " << tempCombine << " Push " << tempCombine << endl;
                tempCombine = "";//Reset temp combine to equal nothing
            }
        }
        //else if(!isValidRomanNumber(c) && !isdigit(c) && c != '-' && c != '*' && c != )
        else if (isValidRomanNumber(tempCombine[0]) && isValidRomanNumber(tempC))
        {
            //cout << "We are in check 35\n";
            tempCombine = tempCombine + c;
/*
            if (tempC == ' ')
            {
                cout << "We are in check 37\n";
                int temporary = stoi(convertRomanToDecimal(tempCombine));
                v.push_back(temporary);
                tempCombine = "";
            }
            */
        }
        else if (isValidRomanNumber(tempCombine[0]))
        {
            tempCombine = tempCombine + c;
            //cout << "TempCombine: " << tempCombine << endl;
            v.push_back(stoi(convertRomanToDecimal(tempCombine)));
            tempCombine = "";


        }
        else if (tempCombine[0] == '-' || tempCombine[0] == '+' && isdigit(c))
        {
           // cout << "We are in check 7\n";
            //cout << "current val: " << c << endl;

            tempCombine = tempCombine + c;
           // cout << "tempCombine: " << tempCombine << "after check 7\n";
            if (tempC == ' ')
            {
               // cout << "We are in check 8\n";
               // cout << " [CHECK 8] Token = " << tempCombine << " Push " << tempCombine << endl;
                v.push_back(stoi(tempCombine));
                tempCombine = "";
            }
        }
        else if (c == '-' && (isdigit(tempC)))
        {
            tempCombine = tempCombine + c;
           // cout << "We are in check 9\n";
        }
        else if (isValidRomanNumber(c))
        {
            tempCombine += tempCombine + c;

           // cout << "We are in check 27\n";
        }
        else if (isdigit(c)) {
            //Else if c is a digit.
            if (tempCombine != "") {
                //If tempCombine is not equal to empty
                tempCombine = tempCombine + c;//Combine tempCombine with char c     
            }
            if (tempCombine == "") {
                //If tempCombine is empty
                temp = temp + c; //temp is equal to temp + char c          
            }
        }
        else {

            if (tempCombine == "") {
                //If tempCombine is equal to nothing

                //add if statement to check next value if its space or numeric

                if (v.size() < 2) {
                    return "INVALID INPUT DETECTED!";
                }

                int a = v.back(); //initialize a to the most recently added element vector v
               // cout << "Pop " << a << " ";
                v.pop_back(); //pop the most recently added element from vector v
                int b = v.back();//initialize b to the most recently added element from vector v
                //cout << "Pop " << b << " ";
                v.pop_back();//pop the most recently added element from vector v      

                result = calculation(a, b, c); //Result is equivalent to
                //cout << " Push " << result << endl;
                v.push_back(result);
            }
        }
    }
    
    cout << endl;
    if (v.size() >= 2) {
        return "INVALID INPUT DETECTED!";
    }
    cout << endl;
    return to_string(result); // Convert result from an int to a string, return result.
}


int main()
{
    string userInput; //initialize the string
    string output;
    int runningTotal = 0, invalidCounter = 0, validCounter = 0;
    do {

        cout << "Enter a postfix expression (or 0 to exit): "; // Prompt user for input
        getline(cin, userInput);//Store user input
        userInput = userInput + " ";

        if (userInput == "0 ") break;

        output = evaluatePostfix(userInput); //Call the function evaluatePostfix

        if (output == "INVALID INPUT DETECTED!")
        {
            invalidCounter++;
        }
        else
        {
            cout << "Result: " << output << endl; // Display the output
            validCounter++;
            runningTotal += stoi(output);
        }

    } while (userInput != "0"); // while user input is not equivalent to 0, continue the loop

    cout << "Total: " << runningTotal << endl;
    cout << "Valid: " << validCounter << endl;
    cout << "INVALID: " << invalidCounter << endl;
    return 0;
}
