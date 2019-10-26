#include "pch.h"
#include <iostream>
#include<vector>
#include<list>
#include<map>
#include<string>


using namespace std;


int main()
{

	map <string, string> m;
	pair<string, string> p1("H", "hello");
	pair<string, string> p2("W", "world");
	pair<string, string> p3("B", "beijing");
	//m.push_back(p1);
	//m.push_back(p2);
	m.insert(p1);
	m.insert(p2);
	m.insert(p3);
	//cout << m[3] << endl;
	//cout << m[6] << endl;
	cout << m["H"] << endl;
	map<string, string>::iterator a = m.begin();
	for (; a != m.end(); a++)
	{
		cout << a->first << " " << a->second << endl;
	}

	//map内部按照key的大小进行输出，B大于G大于S



	//map <int, string> m;
	//pair<int, string> p1(3, "hello");
	//pair<int, string> p2(6, "world");
	//pair<int, string> p3(8, "beijing");
	//m.push_back(p1);
	//m.push_back(p2);
	//m.insert(p1);
	//m.insert(p2);
	//m.insert(p3);
	//cout << m[3] << endl;
	//cout << m[6] << endl;

	//map<int,string>::iterator a = m.begin();
	//for (; a != m.end(); a++)
	//{
	//	cout << a->first << " " << a->second << endl;
	//}


	//list<int> list1;
	//list1.push_back(4);
	//list1.push_back(7);
	//list1.push_back(10);
	
	
	//for (int i = 0; i < list1.size(); i++)
	//{
	//	cout << list1[i] << endl;
	//
	//}

	//list<int>::iterator a = list1.begin();
	//for (; a != list1.end(); a++)
	//{
	//	cout << *a << endl;
	//}



	//vector <int> vec;
	//vec.push_back(3);
	//vec.push_back(4);
	//vec.push_back(6);
	//vec.pop_back();
	//cout << vec.size() << endl;


	//for (int i = 0; i < vec.size(); i++)
	//{
	//	cout << vec[i] << endl;
	//}

	//vector<int>::iterator a = vec.begin();
	////cout << *a << endl;
	//for (; a != vec.end(); a++)
	//{
	//	cout << *a << endl;
	//}

	//cout << vec.front() << endl;
	//cout << vec.back() << endl;


	return 0;
}

