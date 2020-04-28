#pragma once
#include "pch.h"


using namespace std;

int insertObj(vector <string> & input) {
	string word = "";
	int index = 0;

	cout << "Input word:" << endl;
	cin >> word;
	cout << "Input index:" << endl;
	cin >> index;
	index--;

	input.insert(input.begin() + index, word);
	return 1;
}


int deleteObj(vector <string> & input) {
	int index = 0;

	cout << "Input index:" << endl;
	cin >> index;
	index--;
	if (index >= 0 and index <= input.size()) {
		input.erase(input.begin() + index);
		return 1;
	}
	else {
		cout << "Invalid index!" << endl;
		return 0;
	}
}


int editObj(vector <string> & input) {
	int index = 0;
	string buffer = "";

	cout << "Input index:" << endl;
	cin >> index;
	index--;

	cout << input[index] << endl << "Type new word";
	cin >> buffer;

	input[index] = buffer;
	return 1;
}


int parseInput(vector <string>& input, string& buffer) {
	std::stringstream stream(buffer);

	while (stream.good())
	{
		string substr = "";
		getline(stream, substr, '\t');
		if (substr != "") {
			input.push_back(substr);
		}
	}
	return 1;
}


int printVector(vector <string>& a, int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << '\t' << endl;
	}
	return 1;
}


int callMenu(vector <string>& input) {
	string param;

	cout << "Menu:" << endl << "1.Insert" << endl << "2.Delete" << endl << "3.Edit" << endl << "4.Print" << endl << "5.Exit" << endl;
	cin >> param;

	try {
		if (not cin.fail()) {
			{

				switch (stoi(param)) {
				case 1: insertObj(input);
					break;
				case 2: deleteObj(input);
					break;
				case 3: editObj(input);
					break;
				case 4: printVector(input, input.size());
					break;
				case 5: return 0;
				default: return 2;
				}
			}
			return 1;
		}
	}
	catch(...) {
		cout << "Invalid input!" << endl;
		return 1;
	}
}
