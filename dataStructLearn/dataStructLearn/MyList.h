#pragma once
#include <iostream>
using namespace std;
typedef struct Node
{
	double num;
	Node *pre;
	Node *next;
};
class MyList
{
public:
	MyList();
	~MyList();
	bool add(double num);
	bool remove(double num);
	bool insert(double num, int index);
	bool swap(int a, int b);
	Node *findNodeByNum(int num);
	void showList();
private:
	int size = 0;
	Node *currentNode;
	Node *head;
	Node *tail;
};

