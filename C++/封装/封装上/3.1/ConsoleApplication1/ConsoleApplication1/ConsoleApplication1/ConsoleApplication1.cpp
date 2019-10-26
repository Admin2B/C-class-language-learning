#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string name;
	cout << "Please input your name:" << endl;
	getline(cin, name);
	if (name.empty())
	{
		cout << "Input is null." << endl;
		return 0;
	}
	if (name == "imooc")
	{
		cout << "You are a administrator." << endl;

	}
	cout << "Hello," + name << endl;
	cout << "Your name length:" << name.size() << endl;
	cout << "Your name first letter is:"  <<name[0] << endl;
	return 0;
}
