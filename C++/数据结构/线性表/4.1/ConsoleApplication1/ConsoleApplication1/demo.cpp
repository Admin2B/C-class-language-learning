#include "pch.h"
#include <iostream>
#include "List.h"

using namespace std;

int menu()
{
	cout << "功能菜单" << endl;
	cout << "1.新建联系人" << endl;
	cout << "2.删除联系人" << endl;
	cout << "3.浏览通讯录" << endl;
	cout << "4.退出通讯录" << endl;
	cout << "请输入：" ;
	int order = 0;
	cin >> order;
	return order;
}

void creatPerson(List *p)
{
	Node node;
	Person person;
	cout << "请输入姓名：";
	cin >> node.data.name;
	cout << "请输入电话：";
	cin >> node.data.phone;
	p->ListInsertTail(&node);
}

void deletePerson(List *p)

{

	Node node;

	Person person;

	cout << "请输入要删除的人的姓名：";

	cin >> person.name;

	cout << "请输入要删除的人的电话：";

	cin >> person.phone;

	node.data = person;

	Node temp;

	int index = p->LocateElem(&node);

	p->ListDelete(index, &temp);

}
int main()
{
	int userOrder = 0;
	List *p = new List();
	while (userOrder != 4)
	{

		userOrder = menu();
		switch (userOrder)
		{
		case 1:
			cout << "用户指令-->>新建联系人：" << endl;
			creatPerson(p);
			break;
		case 2:
			cout << "用户指令-->>删除联系人：" << endl;
			deletePerson(p);
			break;
		case 3:
			cout << "用户指令-->>浏览通讯录：" << endl;
			p->ListTraverse();
			break;
		case 4:
			cout << "用户指令-->>退出通讯录：" << endl;
			break;
		default:
			break;
		
		}
	}

	delete p;
	p = NULL;



    return 0; 
}


