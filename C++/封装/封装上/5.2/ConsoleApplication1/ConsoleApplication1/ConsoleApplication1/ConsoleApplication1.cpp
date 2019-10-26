#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class Teacher
{
public:
	void setName(string _name);
	string getName();
	void setGender(string _gender);
	string getGender();
	void setAge(int _age);
	int getAge();
	void teach();
private:
	string m_strName;
	string m_strGender;
	int m_iAge;
};

void Teacher::setName(string _name)
{
	m_strName = _name;
}

string Teacher::getName()
{
	return m_strName ;
}

void Teacher::setGender(string _gender)
{
	m_strGender = _gender;
}

string Teacher::getGender()
{
	return m_strGender;
}

void Teacher::setAge(int _age)
{
	m_iAge = _age;
}

int Teacher::getAge()
{
	return m_iAge;
}

void Teacher::teach()
{
	cout << "上课啦" << endl;
}
int main(void)
{
	Teacher t;
	t.setName("kongzi");
	t.setGender("male");
	t.setAge(30);
	cout << t.getName() << " " << t.getAge() << " " << t.getGender() << endl;
	t.teach();
	return 0;
}
