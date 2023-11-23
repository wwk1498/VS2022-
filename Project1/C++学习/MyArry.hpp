#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray {
private:
	T* pArray;
	int m_Capacity;//数组容量
	int m_Size;//数组大小
public:
	MyArray(int Capacity) {//有参构造 参数 容量
		//cout << "有参构造函数" << endl;
		this->m_Capacity = Capacity;
		this->m_Size = 0;
		this->pArray = new T[this->m_Capacity];
	}

	MyArray(const MyArray&arry) {//拷贝函数
		//cout << "拷贝函数" << endl;
		this->m_Capacity = arry.m_Capacity;
		this->m_Size = arry.m_Size;
		//this->pArray = arry.pArray;   浅拷贝

		//深拷贝
		this->pArray = new T[arry.m_Capacity];
		for (int i = 0; i < arry.m_Size; i++) {
			this->pArray[i] = arry.pArray[i];
		}
	}

	//operator= 防止浅拷贝
	MyArray& operator=(const MyArray& arry) {//arr2=arr1;
		//cout << "operator=拷贝函数" << endl;
		//先释放原来的堆区数据
		if (this->pArray != NULL) {
			delete[] this->pArray;
			this->pArray = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//深拷贝
		this->m_Capacity = arry.m_Capacity;
		this->m_Size = arry.m_Size;
		this->pArray = new T[arry.m_Capacity];
		for (int i = 0; i < arry.m_Size; i++) {
			this->pArray[i] = arry.pArray[i];
		}
		return *this;
	}

	//尾插法插入数据
	void push_back(const T&val) {
		if (this->m_Size == this->m_Capacity) {
			return;
		}
		this->pArray[this->m_Size] = val;
		this->m_Size++;
	}
	//尾删法
	void pop_back() {
		if (this->m_Size == 0) {
			return;
		}
		this->m_Size--;
	}

	//通过下标访问数组中的元素
	T& operator[](int index) {
		return this->pArray[index];
	}
	//返回数组容量
	int get_Capacity() {
		return this->m_Capacity;
	}
	//返回数组大小
	int get_Size() {
		return this->m_Size;
	}

	~MyArray() {//析构函数
		//cout << "析构函数" << endl;
		if (this->pArray != NULL) {
			delete[] this->pArray;
			this->pArray = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}
};