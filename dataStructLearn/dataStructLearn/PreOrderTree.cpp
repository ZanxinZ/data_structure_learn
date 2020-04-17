#include "stdafx.h"
#include "PreOrderTree.h"
#include <iostream>
using namespace std;
PreOrderTree::PreOrderTree()
{
	
}
PreOrderTree::PreOrderTree(int pre[])
{
	int size = sizeof(pre) / sizeof(pre[0]);
	constructTree(pre, size);
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
	if (*preIndex > size||low>high)
	{
		return NULL;
	}
	node *root = newNode(pre[*preIndex]);
	(*preIndex)++;
	if (left == right) {
		cout << "form a node" << endl;
		return root;
	}
	int i=0;
	for (; i < high; i++)
	{
		if (pre[i] > root->data) {
			break;
		}
	}
	root->left = constructTree(pre, preIndex, *preIndex, i - 1, size);
	root->right = constructTree(pre, preIndex,i ,high , size);

}
/*Create a new node*/
node *PreOrderTree::newNode(int data) {
	node *create = new node();
	create->data = data;
	create->left = create->right = NULL;
	return create;
}
node *PreOrderTree::preOrder(node *root) {
	if (root != NULL) {
		outputCurr(root);
		preOrder(root->left);
		preOrder(root->right);
		return root;
	}
	return root;
}
node *PreOrderTree::outputCurr(node *curr) {
	cout << "data:"<<curr->data << endl;
	return curr;
}
