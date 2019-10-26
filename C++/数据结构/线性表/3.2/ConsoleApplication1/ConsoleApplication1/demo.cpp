#include "pch.h"
#include <iostream>
#include "List.h"

using namespace std;
int main()
{
	Node node1,node2,node3,node4,node5;
	node1.data = 3;
	node2.data = 4;
	node3.data = 5;
	node4.data = 6;
	node5.data = 7;
	Node temp;
	List *p = new List();

	//p->ListInsertHead(&node1);
	//p->ListInsertHead(&node2);
	//p->ListInsertHead(&node3);
	//p->ListInsertHead(&node4);

	p->ListInsertTail(&node1);
	p->ListInsertTail(&node2);
	p->ListInsertTail(&node3);
	p->ListInsertTail(&node4);

	p->ListInsert(1,&node5);

	//p->ListDelete(1,&temp);
	//p->GetElem(1,&temp);
	//p->PriorElem(&node5, &temp);

	p->NextElem(&node5, &temp);

	p->ListTraverse();
	cout << "temp:" << temp.data << endl;
	delete p;
	p = NULL;

    return 0; 
}


