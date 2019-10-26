#include "pch.h"
#include <iostream>
#include "MyStack.h"
#include "Coordinate.h"

#define BIN 2
#define OCT 8
#define HEX 16


using namespace std;
int main()
{
	//char num[] = "0123456789ABCDEF";
	MyStack <int> *p = new MyStack<int>(30);
	int N = 1348;
	int mod = 0;
	while (N != 0)
	{
		mod = N % HEX;
		p->push(mod);
		N = N / HEX;
	}

	p->stackTraverse(false);

	delete p;
	p = NULL;









	//MyStack <Coordinate> *p = new MyStack<Coordinate>(5);
	/*MyStack <char> *p = new MyStack<char>(5);
	p->push('h');
	p->push('l');
	p->stackTraverse(true);
	p->stackTraverse(false);
	cout << p->stackLength() << endl;*/



	/*MyStack *p = new MyStack(5);

	p->push((Coordinate(1, 2)));
	p->push((Coordinate(3, 4)));

	p->stackTraverse(true);
	p->stackTraverse(false);




	cout << p->stackLength() << endl;




	if (p->stackEmpty())
	{
		cout << "空" << endl;
	}

	if (p->stackFull())
	{
		cout << "满" << endl;
	}



	delete p;
	p = NULL;
*/
    return 0; 
}




