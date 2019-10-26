#include "pch.h"
#include <iostream>
#include<vector>
#include<list>
#include<map>


using namespace std;


int main()
{
	vector <int> vec;
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(6);
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

	cout << vec.front() << endl;
	cout << vec.back() << endl;


	return 0;
}

