// Complex Numbers Demo
// John Goulden
// F1998 - 2020
// Yes it has improved with age
// OCU and OCCC

#include<iostream>
#include"ComplexNumbers.h"
using namespace std;

int main() {

	double v1, v2;
	cout << "Give me a real number: ";
	cin >> v1;
	cout << endl;
	cout << "Constructor tests..." << endl;
	cout << endl;
	ComplexNumber d1;       // default constructor
	ComplexNumber d2(v1);     // one parameter constructor
	ComplexNumber d3(v1, v1); // two parameter constructor
	cout << "D1 is " << d1 << endl;
	cout << "D2 is " << d2 << endl;
	cout << "D3 is " << d3 << endl;
	cout << endl;
	cout << "Give me a complex number: ";
	ComplexNumber d4;
	cin >> d4;
	cout << "D4 is " << d4 << endl;
	cout << "The magnitude of d4 is " << d4.magnitude() << endl;
	cout << "The conjugate of d4 is " << d4.conjugate() << endl;
	cout << endl;

	cout << "Assignment and equality test..." << endl;
	cout << endl;
	ComplexNumber x1;
	ComplexNumber x2 = x1;
	cout << "X1 is " << x1 << endl;
	cout << "X2 is " << x2 << endl;
	cout << "Are they equal? " << (x1 == x2 ? "true" : "false") << endl;
	cout << "Not equal? " << (x1 != x2 ? "true" : "false") << endl;
	cout << endl;
	x2 = ComplexNumber(10, 10);
	cout << "X1 is " << x1 << endl;
	cout << "X2 is " << x2 << endl;
	cout << "Are they equal? " << (x1 == x2 ? "true" : "false") << endl;
	cout << "Not equal? " << (x1 != x2 ? "true" : "false") << endl;
	cout << endl;
	cout << "Assignment and equality test complete!" << endl;
	cout << endl;

	ComplexNumber a3(5, 5);
	ComplexNumber a1, a2;
	a1 = a2 = a3;
	cout << "Chained assignment demo..." << endl;
	cout << endl;
	cout << "A1 is " << a1 << endl;
	cout << "A2 is " << a2 << endl;
	cout << "A3 is " << a3 << endl;
	cout << endl;
	cout << "Chained assignment demo complete!" << endl;
	cout << endl;

	cout << "Type casting demo..." << endl;
	cout << endl;
	ComplexNumber dd = (ComplexNumber)3.3;
	cout << "DD is " << dd << endl;
	double k = (double)dd;
	cout << "k is " << k << endl;
	cout << endl;

	ComplexNumber a(10.2, 12.3);
	ComplexNumber b(11.1, -3.1);

	// this works because we wrote a constructor that accepts one double
	cout << "The ComplexNumber of " << k << " is " << (ComplexNumber)k << endl;

	// these work because we wrote code for them in the header file
	cout << "The int of ComplexNumber " << a << " is " << (int)a << endl;
	cout << "The double of ComplexNumber " << a << " is " << (double)a << endl;

	cout << endl;
	cout << "Type casting demo complete!" << endl;
	cout << endl;

	cout << "Math demos..." << endl;
	cout << endl;

	ComplexNumber c1 = d4;
	ComplexNumber c2(-42.5, 3.333);
	cout << "The unary plus of " << c1 << " is " << +c1 << endl;
	cout << "The negation of " << c1 << " is " << -c1 << endl;
	cout << endl;
	cout << "We will add " << c1 << " and " << c2 << "..." << endl;
	ComplexNumber c3 = c1 + c2;
	cout << "The sum is " << c3 << endl;
	cout << endl;
	cout << "We will now do a plus-equals with " << c3 << " and " << c2 << "..." << endl;
	c3 += c2;
	cout << "The result is " << c3 << endl;
	cout << endl;
	cout << "Now we do a chained addition of " << c1 << " and " << c2 << " and " << c3 << "..." << endl;
	ComplexNumber x = c1 + c2 + c3;
	cout << "The result is " << x << endl;
	cout << endl;
	cout << "Add the integer " << 10 << " to ComplexNumber " << c2 << "..." << endl;
	// this works because there is a ComplexNumber constructor that accepts an int and the int gets promoted to ComplexNumber.
	c2 += 10;
	cout << "The result is " << c2 << endl;
	cout << "Add the double " << 11.11 << " to ComplexNumber " << c2 << "..." << endl;
	// this works because there is a ComplexNumber constructor that accepts a double and the double gets promoted to ComplexNumber.
	c2 += 11.11;
	cout << "The result is " << c2 << endl;
	cout << "Math demo complete!" << endl;
	cout << endl;
	cout << "Thank you for playing Complex Numbers Demo!" << endl;

	return EXIT_SUCCESS;
}