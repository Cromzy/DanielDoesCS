// Daniel Harrison
// c++
// data file maker

#include <iostream> // for the usual console input and output features
#include <fstream> // to write to a file
#include <string> // as the data type to store the file name
#include <ctime> // to seed the pseudorandom number generator
using namespace std;

int main(int argc, char * argv[])
{
	string fileName;
	srand(time(0)); // needed for srand
	int numValues = 200; // number of values
	int range = 1000; // top of range


	if (argc >= 2) { // at least one command-line parameter was provided
		numValues = atoi(argv[1]);
	}
	if (argc >= 3) { // at least two command-line parameters were provided
		range = atoi(argv[2]);
	}
	if (argc >= 4) { // all three were provided
		fileName = (argv[3]);
	}
	
	if( argc < 4){ // no file name provided so prompt for it
		cout << "Please enter file name: ";
		getline(cin, fileName);
	}

	cout << "Writing " << numValues <<
		    " values in [0-" << range << ") to "  
		     << fileName << endl;

	ofstream fout; // create the output stream
	fout.open(fileName); // connect to the file
	fout << numValues << endl;
	for (int i = 0; i < numValues; i++) 
	{
		fout << rand() % range << " ";
	}







}


