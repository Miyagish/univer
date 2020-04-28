#include <iostream>
#include "system.h"
#include "vagon.h"
#include"train.h"
using namespace std;


vagon* readfile(int& size)
{

//	iptr size;
	ifstream fin("dbase.txt");
	if (!fin)
	{
		cout << "File not found!" << endl;
		system("pause");
		exit(1);
	}
	fin >> size;
	vagon* vagons = new vagon[size];
	for (int i = 0; i < size; i++)
	{
		fin >> vagons[i];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size-1; j++)
		{
			if (vagons[i].id == vagons[j].id)
			{
				cout << "Vagons can't match!" << endl;
				system("pause");
				exit(1);
			}
		}
	}

	fin.close();
	return vagons;
}

void traincompare(train train1, train train2)
{
	
		for (int i = 0; i < train1.size; i++)
			for (int j = 0; j < train2.size; j++)
				if (train1.a[i] == train2.a[j])
				{
					cout << "Vagons can't match!" << endl;
					system("pause");
					exit(1);
				}
	if (train2.size > train1.size)
	{
		for (int i = 0; i < train2.size; i++)
			for (int j = 0; j < train1.size; j++)
				if (train2.a[i] == train1.a[j])
				{
					cout << "Vagons can't match!" << endl;
					system("pause");
					exit(1);
				}
	}

}


void trainfill(train& t,train& A, vagon* vagons,int& size)
{
	for (int i = 0; i < t.size ; i++)
		for (int j = 0; j < size; j++)
			if ((vagons[j].type == 'A') && (t.a[i] == vagons[j].id))
				A.pushback(vagons[j].id);
}




int main()
{
	int size,i;
	vagon* vagons;
	train train1, train2, B, A;

	//iptr x = 10;
	//vagon a;
	//vagon b (x, 'A', "123fsdj");
	//cout << a << endl << b;
	vagons = readfile(size);
	cout << "registered vagons: " << endl;
	for (i = 0; i < size; i++)
	cout<< vagons[i]<<endl;
	cout << endl << endl << endl;
	cout << "Type train 1 vagons IDs, to stop typing press 0 and Enter: ";
	//train1.readtrain();
	train1.pushback(1);
	cout << endl << "Type train 2 vagons IDs, to stop typing press 0 and Enter: ";
	train2.readtrain();
	cout << endl;
	traincompare(train1, train2);
	cout << train1.a[0];
	//trainfill(train1,A, vagons, size);
	//for (int i = 0; i < train1.size; i++)
	//	for (int j = 0; j < size; j++)
	//		if ((vagons[j].type == 'A') && (train1.a[i] == vagons[j].id))
	//			A.pushback(vagons[j].id);
	//cout << A;

	//cout << train1;
	
	//cout << train1<<endl;
	system("pause");
	exit(1);
	return 0;
}











