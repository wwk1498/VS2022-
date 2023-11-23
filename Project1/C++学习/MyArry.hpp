#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray {
private:
	T* pArray;
	int m_Capacity;//��������
	int m_Size;//�����С
public:
	MyArray(int Capacity) {//�вι��� ���� ����
		//cout << "�вι��캯��" << endl;
		this->m_Capacity = Capacity;
		this->m_Size = 0;
		this->pArray = new T[this->m_Capacity];
	}

	MyArray(const MyArray&arry) {//��������
		//cout << "��������" << endl;
		this->m_Capacity = arry.m_Capacity;
		this->m_Size = arry.m_Size;
		//this->pArray = arry.pArray;   ǳ����

		//���
		this->pArray = new T[arry.m_Capacity];
		for (int i = 0; i < arry.m_Size; i++) {
			this->pArray[i] = arry.pArray[i];
		}
	}

	//operator= ��ֹǳ����
	MyArray& operator=(const MyArray& arry) {//arr2=arr1;
		//cout << "operator=��������" << endl;
		//���ͷ�ԭ���Ķ�������
		if (this->pArray != NULL) {
			delete[] this->pArray;
			this->pArray = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//���
		this->m_Capacity = arry.m_Capacity;
		this->m_Size = arry.m_Size;
		this->pArray = new T[arry.m_Capacity];
		for (int i = 0; i < arry.m_Size; i++) {
			this->pArray[i] = arry.pArray[i];
		}
		return *this;
	}

	//β�巨��������
	void push_back(const T&val) {
		if (this->m_Size == this->m_Capacity) {
			return;
		}
		this->pArray[this->m_Size] = val;
		this->m_Size++;
	}
	//βɾ��
	void pop_back() {
		if (this->m_Size == 0) {
			return;
		}
		this->m_Size--;
	}

	//ͨ���±���������е�Ԫ��
	T& operator[](int index) {
		return this->pArray[index];
	}
	//������������
	int get_Capacity() {
		return this->m_Capacity;
	}
	//���������С
	int get_Size() {
		return this->m_Size;
	}

	~MyArray() {//��������
		//cout << "��������" << endl;
		if (this->pArray != NULL) {
			delete[] this->pArray;
			this->pArray = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}
};