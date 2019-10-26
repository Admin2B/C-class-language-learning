#include "pch.h"
#include <stdio.h>


struct weapon
{
	char name[20];
	int atk;
	int price;
};

int main()
{
	struct weapon weapon_1 = {"w1",100,200};
	printf("%s\n%d\n",weapon_1.name,++weapon_1.price);

	struct weapon *w;
	w = &weapon_1;
	printf("name=%s\n",(*w).name);
	printf("name=%s\n", w->name);


	struct weapon weapon_2[2] = { {"w2",300,400,},{"w3",500,600 } };
	printf("%s\n%d\n", weapon_2[0].name, weapon_2[1].atk);

	struct weapon *p;
	p = weapon_2; // p->name  weapon_2[0].name 
	//数组名前加&表示指向其地址，
	//不加&表示指向该数组的第一个元素的起始地址即指向该数组第一个元素的地址
	printf("%s\n",p->name);

	p++;//weapon_2 +1  weapon_2[1]
	printf("%s\n", p->name);
	return 0;
}

