#include"person.h"

template<typename T1, typename T2>
person<T1, T2>::person(T1 id, T2 name) {
	this->m_id = id;
	this->m_name = name;
}


template<typename T1, typename T2>
void person<T1, T2>::show() {
	cout << this->m_id << endl;
	cout << this->m_name << endl;
}