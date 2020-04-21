#include "stdafx.h"
#include "PreOrderTree.h"
#include <iostream>
/*生成的树的结构仍然不正确*/
using namespace std;
PreOrderTree::PreOrderTree()
{
	
}
PreOrderTree::PreOrderTree(int pre[],int size)
{
	//int size = sizeof(pre) / sizeof(pre[0]);
	cout << "size of pre :" << size << endl;
	root=constructTree(pre, size);
}


PreOrderTree::~PreOrderTree()
{

}
node *PreOrderTree::constructTree(int pre[],int size) {
	int preIndex = 0;
	return constructTree(pre,&preIndex,0,size-1,size);
}
node *PreOrderTree::constructTree(int pre[], int *preIndex, int low, int high, int size) {
	//base case 
	if (*preIndex >= size||low>high)
	{
		return NULL;
	}
	node *root = newNode(pre[*preIndex]);
	(*preIndex)++;
	if (low == high) {
		cout << "form a node" << endl;
		return root;
	}
	int i=size/2;

	root->left = constructTree(pre, preIndex, *preIndex, i - 1, size);
	root->right = constructTree(pre, preIndex,i ,high , size);
	return root;
}
/*Create a new node*/
node *PreOrderTree::newNode(int data) {
	node *create = new node();
	create->data = data;
	create->left = create->right = NULL;
	return create;
}
/*Show the nodes*/
node *PreOrderTree::preOrder(node *root) {
	static int count = 0;
	
	if (root != NULL) {
		outputCurr(root);
		if (root->left != NULL) {
			cout << "-" << endl;
			outputCurr(root->left);

		}
		if (root->right != NULL) {
			cout << "-" << endl;
			outputCurr(root->right);
		}

		preOrder(root->left);
		preOrder(root->right);
	}
	//cout << "ha " << endl;
	return root;
}
node *PreOrderTree::outputCurr(node *curr) {
	if(curr!=NULL)
	cout << "data:"<<curr->data<<endl;
	else {
		cout << "no data" << endl;
	}
	return curr;
}
