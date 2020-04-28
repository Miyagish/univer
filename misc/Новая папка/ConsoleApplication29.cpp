#pragma once
#include "pch.h"


using namespace std;


int main() {
	
	system("pause");

	vector <string> input;
	string buffer = "";

	cout << "Please insert strings" << endl;
	getline(cin, buffer);

	parseInput(input, buffer);
	printVector(input, input.size());

	while (callMenu(input));

	system("pause");
}


