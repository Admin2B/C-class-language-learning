#include "pch.h"
#include <iostream>
#include "MyStack.h"
//#include "Coordinate.h"

using namespace std;
int main()
{
	MyStack<char> *p = new MyStack <char>(30);

	MyStack<char> *q = new MyStack <char>(30);

	char str[] = "[[()()]";

	char currentNeed = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i]!=currentNeed)
		{
			p->push(str[i]);
			switch (str[i])
			{
			case '[':
				if (currentNeed != 0)
				{
					q->push(currentNeed);
				}
				currentNeed = ']';
				break;
			case '(':
				if (currentNeed != 0)
				{
					q->push(currentNeed);
				}
				currentNeed = ')';
				break;
			default:
				cout << "不匹配" << endl;
				return 0;
			}
		}
		else
		{
			char elem;
			p->pop(elem);
			if (!q->pop(currentNeed))
			{
				currentNeed = 0;
			}
		}
	}
	if (p->stackEmpty())
	{
		cout << "匹配" << endl;
	}
	else
	{
		cout << "不匹配" << endl;
	}
	delete p;
	p = NULL;
	delete q;
	q = NULL;

    return 0; 
}




