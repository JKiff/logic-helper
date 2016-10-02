// satisfiabilityDeterminer.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;

bool not(bool);
bool con(bool, bool);
bool dis(bool, bool);
bool xor(bool, bool);
bool bic(bool, bool);
bool imp(bool, bool);
void printNotation();
void beginPropDecoding(string, bool[], int);
bool evaluateCompProp(string, string, bool[]);
bool evaluate(string, bool[]);
string replaceAll(string, string, string);

void printNotation() {
	cout << "\n********************\n";
	cout << "0-n: propositional variables, either T or F, where n is the number of propositions - 1" << endl;
	cout << "aa: not." << endl;
	cout << "b: biconditional (if and only if)." << endl;
	cout << "c: conjunction (and)." << endl;
	cout << "d: disjunction (or)." << endl;
	cout << "e: exclusive disjunction (xor)." << endl;
	cout << "f: implication (if-then)." << endl;
	cout << "(: begin group." << endl;
	cout << "): end group." << endl;
	cout << "\n********************\n";
}

void beginPropDecoding(string compProp, bool props[], int index) {
	if (index = 0)
		for (int x = 1; x >= 0; x--) {
			props[index] = x;
			compProp = replaceAll(compProp, "" + index, "" + x);
			evaluateCompProp(compProp, compProp, props);
		}
	else
		for (int x = 1; x >= 0; x--) {
			props[index] = x;
			compProp = replaceAll(compProp, "" + index, "" + x);
			beginPropDecoding(compProp, props, index - 1);
		}
}

string replaceAll(string origin, string from, string to) {
	while (origin.find(from) != -1) {
		origin.replace(origin.find(from), from.size(), to);
	}
	return origin;
}

bool evaluateCompProp(string compProp, string reducedString, bool props[]) {
	if (compProp.find('(') == -1){
		return evaluate(compProp, props);
	}
else
	evaluateCompProp

}

bool evaluate(string compProp, bool props[]) {
	int prop1, prop2;
	prop1 = compProp[0];
	prop2 = compProp[2];
	bool returnVal;
	switch (compProp[1]) {
	case 'a':
		returnVal = not(props[prop2]);
		break;
	case 'b':
		returnVal = bic(props[prop1], props[prop2]);
		break;
	case 'c':
		returnVal = con(props[prop1], props[prop2]);
		break;
	case 'd':
		returnVal = dis(props[prop1], props[prop2]);
		break;
	case 'e':
		returnVal = xor(props[prop1], props[prop2]);
		break;
	case 'f':
		returnVal = imp(props[prop1], props[prop2]);
		break;
	default:
		returnVal = false;
		break;
	}
	return returnVal;

}


bool not(bool val1) {
	return !val1;
}
bool imp(bool val1, bool val2) {
	if (val1 && !val2)
		return false;
	else
		return true;
}
bool con(bool val1, bool val2) {
	return(val1 || val2);
}
bool dis(bool val1, bool val2) {
	return (val1 && val2);
}
bool xor(bool val1, bool val2) {
	return (val1 ^ val2);
}
bool bic(bool val1, bool val2) {
	return (val1 == val2);
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
			bool *props = new bool[numProps];
			beginPropDecoding(compProp, props, numProps - 1);
		}
		else if (menuChoice == 2)
			printNotation();
		
			
	}
	


	cin.clear();
	cin.ignore(32767, '\n');
	//cin.get();
}

