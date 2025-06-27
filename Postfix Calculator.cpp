// Daniel Harrison
// occc - C++ Programming
// Homework - Postfix Calculator.cpp
#include <iostream>
#include <vector>//allows for use of vectors
#include <string>//allows for conversion of strings to ints

using namespace std;

int calculation(int a, int b, char opera) {

    if (opera == '+') return a + b; //if operator received is a additional symbol  a + b
    if (opera == '-') return b - a; //if operator received is a subtraction symbol  b - a
    if (opera == '*') return a * b; //if operator received is a multiplication symbol  a * b
    if (opera == '/') return b / a; //if operator received is a division symbol  b / a
    if (opera == '%') return b % a; //if operator received is a modulus symbol  b % a

    return a;
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
        char tempC = input[i + 1];
        if (c == ' ') {
            // if c equals a blank/white space

            if (temp != "") {
                //If temp does not equal empty
                v.push_back(stoi(temp));//Convert temp from string to int and push temp into vector, creating a new element.
                temp = "";
            }
            if (!isdigit(c) && tempCombine != "" && tempCombine != "-" && tempCombine != "+") {
                //If not a digit, tempCombine is not nothing, temp combine is not a unary operator.
                v.push_back(stoi(tempCombine)); //Convert tempCombine to an integer from a string, push tempCombine into the vector, creating a new element.
                tempCombine = "";//Reset temp combine to equal nothing
            }
        }


        //used for unary numbers
        else if (tempCombine[0] == '-' || tempCombine[0] == '+' && isdigit(c))
        {
            
            tempCombine = tempCombine + c;
            if (tempC == ' ')
            {          
                v.push_back(stoi(tempCombine));
                tempCombine = "";
            }
        }
        else if (c == '-'  && (isdigit(tempC)))
        {
            tempCombine = tempCombine + c;
        }
        else if (c == '+' && (isdigit(tempC)))
        {
            tempCombine = tempCombine + c;
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
                    return "INVALID INPUT DETECTED!"; //if vector doesnt have 2 elements when an operator is being detected, return invalid
                }

                int a = v.back(); //initialize a to the most recently added element vector v
                v.pop_back(); //pop the most recently added element from vector v
                int b = v.back();//initialize b to the most recently added element from vector v
                v.pop_back();//pop the most recently added element from vector v      

                result = calculation(a, b, c); //Result is equivalent to
                v.push_back(result); //push result to vector
            }
        }
    }

    
    if (v.size() >= 2) {
        return "INVALID INPUT DETECTED!"; //If vector still has 2 or more elements after being evaluated return invalid
    }

    return to_string(result); // Convert result from an int to a string, return result.
}


int main()
{
    string userInput; //initialize the string
    string output;
    int runningTotal = 0, invalidCounter = 0; //Counters
    do {

        cout << "Enter a postfix expression (or 0 to exit): "; // Prompt user for input
        getline(cin, userInput);//Store user input
        userInput = userInput + " "; // Adds an extra space at the end of each line for error checking

        if (userInput == "0 ") break; //Break program when 0 is entered

        output = evaluatePostfix(userInput); //Call the function evaluatePostfix

        if (output == "INVALID INPUT DETECTED!")
        {
            invalidCounter++; //increment invalid counter by 1
        }
        else
        {
            cout << "Result: " << output << endl; // Display the output
            runningTotal += stoi(output);
        }

    } while (userInput != "0"); // while user input is not equivalent to 0, continue the loop

    cout << "Total: " << runningTotal << endl; //Display total
    cout << "INVALID: " << invalidCounter << endl; //Display invalid counter
    return 0;
}