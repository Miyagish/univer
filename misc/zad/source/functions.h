#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int field_insert(std::vector <std::string> &);
int field_delete(std::vector <std::string> &);
int field_edit(std::vector <std::string> &);
int string_parse(std::vector <std::string>&, std::string&);
int vector_print(std::vector <std::string>&, int);
int menu(std::vector <std::string>&);

#endif 