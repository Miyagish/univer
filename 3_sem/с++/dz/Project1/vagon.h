#pragma once
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



class vagon
{
public:
	int id;
	char type;
	string name;

	vagon ()
	{
		id = NULL;
		type = NULL;
		name = "NULL";
	}

	vagon (int a, char b, string c)
	{
		id = a;
		type = b;
		name = c;
	}
	
	vagon(vagon& a)
	{
		this->name = a.name;
		this->id = a.id;
		this->type = a.type;
	}

	~vagon()
	{
	}


	friend ostream& operator << (ostream& cout, vagon& v)
	{
		cout << "id : " << v.id << endl;
		cout << "type: " << v.type << endl;
		cout << "name: " << v.name << endl;
		return cout;
	}

	friend ifstream& operator >> (ifstream& fin, vagon& v)
	{
		fin >> v.id;
		fin >> v.type;
		fin >> v.name;
		return fin;
	}
};