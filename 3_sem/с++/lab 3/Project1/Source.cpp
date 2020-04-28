#include "MyStack.h"

int main()
{
	system("chcp 1251 > nul");
	int n;
	MyStack<int> stack;


	do {
		cout << "¬ведите целое положительное „исло: \n";
		cin >> n;
	} while (n <= 0);

	Multipliers(n, stack);


	system("pause");
	return 0;

}