
#pragma once
#include<iostream>//�������������ͷ�ļ�
#include"worker.h"
using namespace std;//ʹ�ñ�׼�����ռ�

//������
class manager :public worker {
public:
    //���캯��
    manager(int id,string name,int deptid);

    //��ʾ������Ϣ
    void showInfo();

    //��ȡ��λ����
    string getDeptName();
};