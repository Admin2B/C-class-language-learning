#include <string>
//#include<iostream>
using namespace std;
class Person
{
public:
	Person();
	~Person();
	void eat();
private:
	string m_strName;
	int m_iAge;
};