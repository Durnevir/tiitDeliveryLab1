//���������� ���� ��� ������ �����(��������� �������)
#include <iostream>
#include "Library_prot.h"
using namespace std;

node::node(node* Pr, node* Ne) {
	previous = Pr;
	next = Ne;
	dequeue = new int[Max]();
}

void node::print() {
	for (int k = 0; k < Max; k++) {
		if (dequeue[k] != 0)
			cout << dequeue[k] << " | ";
	}                                             
	cout<< endl;
}

Dequeue::Dequeue() {
	node* N = new node(nullptr, nullptr);  //������� ���
	first = N;  
	last = N;
	first_small_deque = Max / 2 - 1;
	last_small_deque = Max / 2;      // ������� ��������� � ��������� ����
	Size = 0;   // ����� ���������� ���������
}


void Dequeue::add_first() {
	node* N = new node(nullptr, first);
	first->previous = N;
	first = N;
	first_small_deque = Max - 1;
}

void Dequeue::add_last() { 
	node* N = new node(last, nullptr);
	last->next = N;
	last = N;
	last_small_deque = 0;
}

void Dequeue::delete_first() { 
	node* N = first->next;
	delete first;
	first = N;
	first->previous = nullptr;
	first_small_deque = 0;
}

void Dequeue::delete_last() { 
	node* N = last->previous;
	delete last;
	last = N;
	last->next = nullptr;
	last_small_deque = Max - 1;
}


void Dequeue::push_front(int n) {
	(first->dequeue)[first_small_deque] = n;
	first_small_deque--;
	Size++;
	if (first_small_deque == -1)   //If - ��� ������������ ����� �������� ��������� �����
		add_first();   
}

void Dequeue::push_back(int n) {
	(last->dequeue)[last_small_deque] = n;
	last_small_deque++;
	Size++;
	if (last_small_deque == Max)
		add_last();
}

void Dequeue::pop_front() {
	Size--;
	if (first_small_deque == Max - 1)
		delete_first();
	else
		first_small_deque++;
	(first->dequeue)[first_small_deque] = 0;
}

void Dequeue::pop_back() {
	Size--;
	if (last_small_deque == 0)
		delete_last();
	else
		last_small_deque--;
	(last->dequeue)[last_small_deque] = 0;
}

bool Dequeue::empty() { return (Size == 0); }

void Dequeue::clear() {
	node* N = first;
	while (N) {
		node* M = N->next;
		delete N->previous;
		delete N;
		N = M;
	}

	N = new node(nullptr, nullptr);
	first = N;
	last = N;
	Size = 0;                                 
	first_small_deque = Max / 2 - 1;
	last_small_deque = Max / 2;
}

void Dequeue::print() {
	cout << "RESULT - | ";
	node* N = first;
	while (N) {
		N->print();   //����� ������� ������ �������
		N = N->next;
	}
}