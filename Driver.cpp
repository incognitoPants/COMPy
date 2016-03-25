#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "COMPy.h"
using namespace std;

int main () {
	COMPy obj;
	string input = "";
	while (input != "exit") {
		//Capture User Input
		cout << ">>>";
		getline(cin, input);
		obj.capture(input);
	}

	return 0;
}
