#include <vector>
#include <iostream>
#include "tree_of_sum.h"

node* build(std::vector<int>& a, int L, int R) //���������� ������
{
	/*���� ����� �������
	  ��������� ������ -
	  ������ ������ �� ����� �������*/
	if (L == R)
	{
		node* obj = new node; //��������� ������������ ������ ��� obj

		obj->summa = a[L]; //����������� summa �������� ����� �������
		obj->add_value = 0;
		obj->Left = obj->Right = NULL; //����������� ����� � ������ ����� 0
		obj->LeftPos = obj->RightPos = L; //����������� ����� � ������ ������� ����� ������
		return obj; //���������� obj
	}

	int middle = (L + R) / 2; //������� �������� ������

	node* Left = build(a, L, middle); //���������� ����� �����
	node* Right = build(a, middle + 1, R); //���������� ������ �����

	node* tree = new node; //�������� ��������������� ������ Tree
	tree->Left = Left;     //� �����
	tree->Right = Right;   //� ������ ����������

	tree->summa = Left->summa + Right->summa;
	tree->add_value = 0;
	tree->LeftPos = Left->LeftPos;
	tree->RightPos = Right->RightPos;

	return tree; //���������� tree
}

int sum(node* tree, int L, int R) //����� ������
{
	if (L < tree->LeftPos) //� ���� if'�� ��������
		L = tree->LeftPos; //������� [L;R] ����� �������,

	if (R > tree->RightPos) //����� �� ������ � �������
		R = tree->RightPos; //[tree->LeftPos; tree->RightPos],
							//�������� ������������� ������� ������ tree
	if (L > R) //���� ���������� ������� �������� ������, �� �������
		return 0; //���������� ����� 0

	if ((tree->LeftPos == L) && (tree->RightPos == R)) // ���� ������ ������ tree ������������� ������� [L..R],
		return tree->summa; // �� ���������� �������� �����, ���������� � ���� �����

	int LeftSum = sum(tree->Left, L, R); //������� ����� ������ ���������
	int RightSum = sum(tree->Right, L, R); //������� ����� ������� ���������

	return LeftSum + RightSum; //���������� ����� ��������� + ������
}

void update(node* tree, int L, int R)
{
	if (L < tree->LeftPos) //� ���� if'�� ��������
		L = tree->LeftPos; //������� [L;R] ����� �������,

	if (R > tree->RightPos) //����� �� ������ � �������
		R = tree->RightPos; //[tree->LeftPos; tree->RightPos],
							//�������� ������������� ������� ������ tree
	if (L > R) //���� ���������� ������� �������� ������, �� �������
		return;//�� ���������
	if ((tree->LeftPos == L) && (tree->RightPos == R) && (L == R)) //���� ������ ������ tree ������������� ������� [L,R], �� �������� ������ � ���
		return;
	update(tree->Left, L, R); //���������� ������������
	update(tree->Right, L, R);//����� � ������ ���������
	tree->add_value = tree->Left->add_value + tree->Right->add_value;
}

void add(node* tree, int L, int R, int value) //����������� �������� value � ������������ ��������� ��������
{
	if (L < tree->LeftPos) //� ���� if'�� ��������
		L = tree->LeftPos; //������� [L;R] ����� �������,

	if (R > tree->RightPos) //����� �� ������ � �������
		R = tree->RightPos; //[tree->LeftPos; tree->RightPos],
							//�������� ������������� ������� ������ tree
	if (L > R) //���� ���������� ������� �������� ������, �� �������
		return;//�� ���������
	if ((tree->LeftPos == L) && (tree->RightPos == R) && (L == R)) //���� ������ ������ tree ������������� ������� [L,R], �� �������� ������ � ���
	{
		tree->add_value += value;
		return;
	}
	add(tree->Left, L, R, value); //���������� ������������
	add(tree->Right, L, R, value);//����� � ������ ���������
}

void print(node* curNode, int depth) { //�� ���� ������� ������� ������� � �������, �� ������� ��� �������

	if (curNode)
	{
		print(curNode->Left, depth + 1);

		for (int i = 0; i < depth * 4; i++)
		{
			std::cout << ' ';
		}

		std::cout << curNode->summa + curNode->add_value << std::endl;
		print(curNode->Right, depth + 1);
	}
}
