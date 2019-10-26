#include "pch.h"
#include <iostream>

struct weapon
{
	int price;
	int atk;
	struct weapon *next;
};
int main()
{
	struct weapon a, b, c, *head;
	a.price = 100;
	a.atk = 1;
	b.price = 200;
	b.atk = 2;
	c.price = 300;
	c.atk = 3;

	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	struct weapon *p;
	p = head;
	while (p != NULL)
	{
		printf("%d,%d\n",p->price,p->atk);
		p=p->next;
	}

	return 0;
}
