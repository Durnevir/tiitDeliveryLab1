#pragma once
struct node //������� ������ ��������
{
	int summa, LeftPos, RightPos, add_value; //summa - �������� �� �����, LeftPos - ����� �������, RightPos - ������ �������
	node* Left, * Right; //Left - ����� ���������, Right - ������
};

node* build(std::vector<int>&, int, int);

int sum(node*, int, int);

void update(node*, int, int);

void add(node*, int, int, int);

void print(node*, int);