#include "pch.h"
#include <iostream>

struct weapon
{
	int price;
	int atk;
	struct weapon *next;
};

struct weapon *creat()
{
	struct weapon *head;

	struct weapon *p1,*p2;//p1当前节点，p2上一节点节点
	int n = 0;
	p1 = p2 = (struct weapon*)malloc(sizeof(struct weapon));
	//p1->next = NULL;
	scanf_s("%d,%d",&p1->price,&p1->atk);
	head = NULL;
	while (p1->price != 0)
	{
		n++;
		if (n == 1)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;//当前节点的上一节点的next指针 指向当前节点
			//p2->next = (struct weapon*)malloc(sizeof(struct weapon));
		}
		p2 = p1;
		p1= (struct weapon*)malloc(sizeof(struct weapon));
		p1->next = NULL;
		scanf_s("%d,%d", &p1->price, &p1->atk);
	}
	p1->next= NULL;
	return head;
};
int main()
{
	struct weapon *p ;
	p = creat();
	//printf("%d,%d\n",p->price,p->atk);

	while(p->next != NULL)
	{
		printf("%d,%d\n", p->price, p->atk);
		p = p->next;
	} 
	return 0;
}
