#pragma once
#include "functions.h"


int main() {
	std::vector <std::string> in_vector;
	std::string buffer = "";

	std::cout << "Please insert your string" << std::endl;
	getline(std::cin, buffer);

	string_parse(in_vector, buffer);

	while (menu(in_vector));

	system("pause");
}


