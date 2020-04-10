#include "stdafx.h"
#include "MyList.h"


MyList::MyList() {
	this->size = 0;
	currentNode = new  struct Node;
	tail = new struct Node;
	tail->num = 0;
	tail->next = NULL;
	tail->pre = currentNode;

	currentNode->num = 0;
	currentNode->pre = NULL;
	currentNode->next = tail;
	head = currentNode;
}


bool MyList::swap(int a, int b) {

	Node *p = findNodeByNum(a);
	Node *q = findNodeByNum(b);
	if (p == NULL || q == NULL) {
		cout << "p or q is not exist,swap fail!!" << endl;
		return false;
	}
	Node *tempNode = new struct Node;
	//Two object are adjacent
	if (p->next == q) {
		tempNode->pre = p->pre;
		tempNode->next = q->next;

		tempNode->pre->next = q;
		tempNode->next->pre = p;

		q->pre = tempNode->pre;
		q->next = p;

		p->pre = q;
		p->next = tempNode->next;

	}
	else if (q->next == p) {
		tempNode->pre = q->pre;
		tempNode->next = p->next;

		tempNode->pre->next = p;
		tempNode->next->pre = q;

		p->pre = tempNode->pre;
		p->next = q;

		q->pre = p;
		q->next = tempNode->next;
	}
	//two object isn't adjacent
	else {
		tempNode->next = p->next;
		tempNode->pre = p->pre;

		p->next = q->next;
		p->pre = q->pre;

		q->next = tempNode->next;
		q->pre = tempNode->pre;

		p->pre->next = p;
		p->next->pre = p;

		q->pre->next = q;
		q->next->pre = q;
	}

	delete tempNode;
	return true;
}
bool MyList::add(double num) {
	if (findNodeByNum(num) != NULL) {
		cout << "num is already exist,add fail" << endl;
		return false;
	}
	Node *next = new struct Node;
	next->num = num;
	next->next = tail;
	tail->pre = next;
	next->pre = currentNode;
	currentNode->next = next;
	currentNode = next;
	size++;
	return true;
}
bool MyList::remove(double num) {
	Node *moveNode = findNodeByNum(num);
	if (moveNode == NULL) {
		cout << "num isn't exist,delete fail" << endl;
		return false;
	}
	char confirm;
	cout << "Are you sure to remove num?(Press 'y' to confirm)" << endl;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y') {
		moveNode->pre->next = moveNode->next;
		moveNode->next->pre = moveNode->pre;
		delete moveNode;
		cout << "remove successful." << endl;
		return true;
	}
	return false;



}
bool MyList::insert(double num, int index) {
	if (index > size || index<0) {
		cout << "size of list:" << size << endl;
		cout << "index beyond,insert fail!" << endl;
		return false;
	}
	if (findNodeByNum(num) != NULL) {
		cout << "the same num has exist,insert fail!" << endl;
		return false;
	}
	if (index == 0) {
		Node *newNode = new struct Node;
		newNode->num = 0;
		newNode->next = head;
		newNode->pre = NULL;
		head->num = num;
		head->pre = newNode;
		head = newNode;
	}
	else if (index == size) {
		add(num);
	}
	else {
		Node *newNode = new struct Node;
		newNode->num = num;
		Node *findedNode = head;
		for (int i = 0; i < index; i++)
		{
			findedNode = findedNode->next;
		}
		newNode->next = findedNode->next;
		findedNode->next->pre = newNode;

		newNode->pre = findedNode;
		findedNode->next = newNode;
	}
	return true;
}
Node *MyList::findNodeByNum(int num) {
	Node *scanNode = head->next;
	bool isFind = false;

	while (scanNode->next != NULL) {
		if (scanNode->num == num) {
			isFind = true;
			return scanNode;
		}
		scanNode = scanNode->next;
	}
	cout << "List has no :" << num << endl;
	return NULL;
}
void MyList::showList() {
	Node *scanNode = head->next;
	if (size == 0) {
		cout << "the list is empty!" << endl;
	}
	cout << "Now the list:" << endl;
	while (scanNode->next != NULL) {
		cout << scanNode->num << "\t";
		scanNode = scanNode->next;
	}
	cout << endl;
}
MyList::~MyList() {
	currentNode = head;
	while (currentNode->next != NULL) {

		currentNode = currentNode->next;
		delete currentNode->pre;
	}
	delete currentNode;
}