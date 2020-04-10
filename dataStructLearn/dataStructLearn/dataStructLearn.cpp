// dataStructLearn.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyList.h"

int main()
{
	MyList listA;
	int option = 0;
	while (1) {
		listA.showList();
		cout << "1:add num to list.(num)" << endl;
		cout << "2:insert num to list.(num index)" << endl;
		cout << "3:swap two num in the list.(num1 num2)" << endl;
		cout << "4:remove num from list.(num)" << endl;
		cout << "5:exit" << endl;
		cout << "choose operation:";
		cin >> option;
		double num;
		bool isExit = false;
		switch (option)
		{
		case 1:
			cout << "input the num to add:";
			cin >> num;
			listA.add(num);
			break;
		case 2:
			int index;
			cout << "input the num and the index to insert:";
			cin >> num >> index;
			listA.insert(num, index);
			break;
		case 3:
			double numA, numB;
			cout << "input two num to swap:";
			cin >> numA >> numB;
			listA.swap(numA, numB);
			break;
		case 4:
			cout << "input the num to remove:";
			cin >> num;
			listA.remove(num);
			break;
		case 5:
			isExit = true;
			break;
		default:
			break;
		}
		if (isExit) { break; }
	}

    return 0;
}

