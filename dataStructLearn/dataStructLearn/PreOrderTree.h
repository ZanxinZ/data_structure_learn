#pragma once

//RT-L_Rǰ��
//L-RT-R����
//L-R-RT����
#include "node.h"
class PreOrderTree
{
public:
	PreOrderTree();
	PreOrderTree(int pre[]);
	node *constructTree(int pre[],int size);
	node *constructTree(int pre[],int *preIndex,int low,int high,int size);
	node *newNode(int data);
	node *preOrder(node *root);
	node *outputCurr(node *curr);
	~PreOrderTree();
private:
	node *root;
};

