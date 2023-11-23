#pragma once
#include<iostream>
using namespace std;

template<typename T1, typename T2>
class person {
public:
	T1 m_id;
	T2 m_name;
	person(T1 id, T2 name);
	void show();
};

