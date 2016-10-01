// satisfiabilityDeterminer.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;

void printNotation() {
	cout << "\n********************\n";
	cout << "p-z: propositional variables, either T or F" << endl;
	cout << "i: implication (if-then)." << endl;
	cout << "d: disjunction (or)." << endl;
	cout << "c: conjunction (and)." << endl;
	cout << "e: exclusive disjunction (xor)." << endl;
	cout << "b: biconditional (iff)." << endl;
	cout << "!: not." << endl;
	cout << "(: begin group." << endl;
	cout << "): end group." << endl;
	cout << "\n********************\n";
}

void beginPropDecoding(string compProp) {

}

int main()
{
	string compProp;
	int numProps;
	int menuChoice = 0;
	while (menuChoice != -1) {
		cout << "Enter 1 for a new compound proposition, 2 to view notation help, -1 to exit." << endl;
		cin >> menuChoice;
		if (menuChoice == 1) {
			cout << "Enter the number of propositions that will be in the compound proposition" << endl;
			cin >> numProps;
			cout << "Enter your compound proposition" << endl;
			cin >> compProp;
			beginPropDecoding(compProp);
		}
		else if (menuChoice == 2)
			printNotation();
		
			
	}


	cin.clear();
	cin.ignore(32767, '\n');
	//cin.get();
}

