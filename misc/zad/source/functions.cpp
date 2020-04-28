#pragma once
#include "functions.h"

int field_insert(std::vector <std::string> &in_vector) {
	std::string token = "";
	int pos = 0;

	std::cout << std::endl << "Please type a new field: " << std::endl;
	std::cin >> token;
	std::cout << std::endl << "Please type a field number to change: " << std::endl;
	std::cin >> pos;
	pos--;

	if ((pos >= 0) && (pos <= in_vector.size())) {
		in_vector.insert(in_vector.begin() + pos, token);
		system("cls");
		vector_print(in_vector, in_vector.size());
		return 1;
	}
	else {
		std::cout << "ERROR! invalid number" << std::endl;
		return 0;
	}
}


int field_delete(std::vector <std::string> &in_vector) {
	int pos = 0;

	std::cout << "Please type a field number to delete: " << std::endl;
	std::cin >> pos;
	pos--;

	if ((pos >= 0) && (pos <= in_vector.size())) {
		in_vector.erase(in_vector.begin() + pos);
		system("cls");
		vector_print(in_vector, in_vector.size());
		return 1;
	}
	else {
		std::cout << "ERROR! invalid number" << std::endl;
		return 0;
	}
}


int field_edit(std::vector <std::string> &in_vector) {
	int pos = 0;
	std::string buffer = "";

	std::cout << "Please type a field number to edit: " << std::endl;
	std::cin >> pos;
	pos--;

	std::cout << in_vector[pos] << std::endl << "Type new token: ";
	std::cin >> buffer;

	if ((pos >= 0) && (pos <= in_vector.size())) {
		in_vector[pos] = buffer;
		system("cls");
		vector_print(in_vector, in_vector.size());
		return 1;
	}
	else {
		std::cout << "ERROR! invalid number" << std::endl;
		return 0;
	}
}


int string_parse(std::vector <std::string>& in_vector, std::string& buffer) {
	std::stringstream buf_stream(buffer);

	while (buf_stream.good())
	{
		std::string substr = "";
		std::getline(buf_stream, substr, '\t');

		if (substr != "") {
			in_vector.push_back(substr);
		}
	}
	return 1;
}


int vector_print(std::vector <std::string>& a, int size) {
	system("cls");

	for (int i = 0; i < size; i++) {
		std::cout << a[i] << '\t';
	}

	std::cout << std::endl << std::endl;
	return 1;
}


int menu(std::vector <std::string>& in_vector) {
	std::string choise = "";

	std::cout << "Menu:" << std::endl
			  << "1) insert a new field"<< std::endl
			  << "2) delete a field" << std::endl
			  << "3) edit a field" << std::endl
		      << "4) print the string" << std::endl
		      << "5) exit the programm" << std::endl;

	std::cin >> choise;

	try {
		if (!std::cin.fail()) {
			{

				switch (stoi(choise)) {

				case 1: field_insert(in_vector);
					break;

				case 2: field_delete(in_vector);
					break;

				case 3: field_edit(in_vector);
					break;

				case 4: vector_print(in_vector, in_vector.size());
					break;

				case 5:
					return 0;
				}
			}
			return 1;
		}
	}
	catch (...) {
		std::cout << "You have typed invalid number" << std::endl;
		return 1;
	}
}