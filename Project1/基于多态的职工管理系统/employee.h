#pragma once
#include<iostream>//�������������ͷ�ļ�
#include"worker.h"
using namespace std;//ʹ�ñ�׼�����ռ�

//��ͨԱ����
class employee:public worker {
public:
    //���캯��
    employee(int id,string name,int deptid);

    //��ʾ������Ϣ
     void showInfo();

    //��ȡ��λ����
     string getDeptName();
};