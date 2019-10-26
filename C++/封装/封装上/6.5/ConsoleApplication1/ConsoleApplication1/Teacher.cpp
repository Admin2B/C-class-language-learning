#include "pch.h"
#include <iostream>
#include"Teacher.h"



Teacher::Teacher(string name, int age,int m) :m_strName(name), m_iAge(age),m_iMax(m)
{
	//m_iMax = m;
	cout<<"Teacher(string name, int age)"<<endl;
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

int Teacher::getMax()
{
	return m_iMax;
}
