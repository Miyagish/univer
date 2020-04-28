#pragma once
using namespace std;

//Шаблонный класс MyStack на основе односвязного списка.
#ifndef MyStack_h			// защита от повторной компиляции
#define MyStack_h           // модуль подключен
#include <iostream>
//Шаблонный класс ListNode (узел односвязного списка)
template <class INF, class FRIEND>
class ListNode				//узел списка
{
private:
	INF d;             			//информационная часть узла
	ListNode* next;   		 //указатель на следующий узел списка
	ListNode() { next = nullptr; } //конструктор 
	friend  FRIEND;
};

//Шаблонный класс MyStack на основе односвязного списка.
template <class INF >
class MyStack
{
	typedef class ListNode < INF, MyStack <INF> > Node;
	Node* top;
public:
	MyStack();			// конструктор
	~MyStack();         // освободить динамическую память
	bool empty();		// стек пустой?
	void push(INF n);	// добавить узел в вершину стека
	void pop();			// удалить узел из вершины стека
	INF* top_inf();		//считать информацию из вершины стека
	int size;
};

template <class INF >
void Multipliers(int n, MyStack<INF> &stack);

template <class INF >
MyStack<INF>::MyStack()
{
	size = 0;
	top = new Node();
}

template <class INF >
MyStack<INF>::~MyStack()
{

	while (size) {
		pop();
	}
}

template <class INF >
bool MyStack<INF>::empty()
{
	if (top->next == nullptr) return 1;
	else return 0;
}

template <class INF >
void MyStack<INF>::push(INF n)
{
	size++;

	Node *current1 = new Node;
	current1->d = n;
	current1->next = top->next;
	top->next = current1;


}

template<class INF>
void MyStack<INF>::pop()
{
	size--;

	Node *current1 = new Node;
	current1 = top->next;
	top->next = top->next->next;
	delete current1;


}

template<class INF>
INF * MyStack<INF>::top_inf()
{
	return &(top->next->d);
}

template<class INF>
void Multipliers(int n, MyStack<INF>& stack)
{
	MyStack<int> temp;

	cout << " = ";
	for (int i = 2; i <= n; i++)
	{
		while (n % i == 0)
		{
			n /= i;
			stack.push(i);
		}
	}
	while (!stack.empty()) {
		cout << *stack.top_inf() << "*";
		temp.push(*stack.top_inf());
		stack.pop();
	}
	cout << "1\n" << " = 1";

	while (!temp.empty()) {
		cout << "*";
		cout << *temp.top_inf();
		temp.pop();
	}

}
#endif
