#pragma once

//RT-L_R«∞–Ú
//L-RT-R÷––Ú
//L-R-RT∫Û–Ú
#include "node.h"
class PreOrderTree
{
public:
	PreOrderTree();
	PreOrderTree(int pre[],int size);
	node *constructTree(int pre[],int size);
	node *constructTree(int pre[],int *preIndex,int low,int high,int size);
	node *newNode(int data);
	node *preOrder(node *root);
	node *outputCurr(node *curr);
	node *getRoot() { return root; }

	
	~PreOrderTree();
private:
	node *root;
};

