#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
#include<fstream>
#define FILENAME "E:\\Users\\ASUS\\Desktop\\empFile.txt"

class workerManager {
public:
	int m_EmpNum;//��¼ְ������
	worker** m_EmpArray;//ְ������ָ��
	bool m_FileIsEmpty;//�ж��ļ��Ƿ�Ϊ��

	workerManager();//���캯��

	void show_menu();//չʾ�˵�
	void exitsystem(); //�˳�ϵͳ
	void Add_Emp();//���ְ��
	int get_EmpNum();//ͳ���ļ��е�����
	void init_Emp();//��ʼ��Ա��
	void show_Emp();//��ʾְ��
	void Del_Emp();//ɾ��ְ��
	void Mod_Emp();//�޸�ְ��
	void Find_Emp();//����ְ��
	void sort_Emp();//��ְ������
	void clean_Emp();//����ļ�
	int isExist(int id);//�ж�ְ���Ƿ����
	void save();//�����ļ�

	~workerManager();//��������
};
