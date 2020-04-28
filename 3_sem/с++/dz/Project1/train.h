#pragma once
#include <iostream>

using namespace std;


class train
{
public:
	int* a;
	int size;

	train()
	{
		a = NULL;
		size = 0;
	}
	//train(int x)
	//{
	//	a = { x };
	//	size = 1;
	//}
	~train()
	{
		delete [] a;
	}

	void pushback(int x)
	{
		int i;
		int* b = this->a;
		this->size++;
		this->a = new int [this->size];
		for ( i = 0; i < this->size - 1; i++)
		{
			this->a[i] = b[i];
		}
		this->a[this->size] = x;
		delete [] b;
	}

	void readtrain()
	{
		int x=-1;
		while (x != 0)
		{
			cin >> x;
			if (x != 0)
			{
				this->pushback(x);
			}
		}

		/*for (int i = 0; i < size; i++)
		{
			for (int j = i+1 ; j < size ; j++)
			{
				if (this->a[i] == this->a[j])
				{
					cout << "Vagons can't match!" << endl;
					system("pause");
					exit(1);
				}
			}
		}*/

	}


	friend ostream& operator << (ostream& cout, train& t)
	{
		for (int i = 0; i < t.size; i++)
		{
			cout << t.a[i]<<'	';
		}
		cout << endl;
		return cout;
	}

};