#include "pch.h"
#include <iostream>
#include"Teacher.h"

Teacher::Teacher()
{
	m_strName = "Jim";
	m_iAge = 5;
	cout << "Teacher()" << endl;
}

Teacher::Teacher(string name,int age)
{
	m_strName =name;
	m_iAge = age;
	cout << "Teacher(string name,int age)" << endl;
}

void Teacher::setName(string name)
{
	m_strName = name;
}

string Teacher::getName()
{
	return m_strName;
}

void Teacher::setAge(int age)
{
	m_iAge = age;
}

int Teacher::getAge()
{
	return m_iAge;
}


