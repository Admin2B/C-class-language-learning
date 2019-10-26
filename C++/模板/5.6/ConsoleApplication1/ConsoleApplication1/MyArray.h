#ifndef MYARRAY_H
#define MYARRAY_H


#include<iostream>
using namespace std;

template <typename T,int Ksize,int KVal>
class MyArray
{
public:
	MyArray();
	~MyArray()
	{
		delete[]m_pArr;
		m_pArr = NULL;
	}
	void display();

private:
	T *m_pArr;
};

template <typename T, int Ksize, int KVal>
MyArray<T, Ksize, KVal>::MyArray()
{
	m_pArr = new T[Ksize];
	for (int i = 0; i < Ksize; i++)
	{
		m_pArr[i] = KVal;
	}
}


template <typename T, int Ksize, int KVal>
void MyArray <T,Ksize,KVal>::display()
{
	for (int i = 0; i < Ksize; i++)
	{
		cout << m_pArr[i] << endl;
	}
}




#endif
