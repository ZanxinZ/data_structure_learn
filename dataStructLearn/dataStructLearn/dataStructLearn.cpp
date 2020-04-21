// dataStructLearn.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyList.h"
#include "PreOrderTree.h"

int main()
{
	int pre[] = { 1, 2, 3 ,4,5,6,7,8,9,10,11,12,13,14};
	PreOrderTree myTree(pre, sizeof(pre) / sizeof(pre[0]));
	cout << myTree.getRoot() << endl;
	myTree.preOrder(myTree.getRoot());

	//cout << myTree.getRoot()->right->right->right ->data;
	cout << "----------" << endl;
	node *temp = myTree.getRoot();
	while (temp != NULL) {
		myTree.outputCurr(temp);
		myTree.outputCurr(temp->left);
		myTree.outputCurr(temp->right);
		cout << "*****" << endl;
		temp = temp->right;
		
	}
}