#pragma once
#include<iostream>//�������������ͷ�ļ�
#include"worker.h"
using namespace std;//ʹ�ñ�׼�����ռ�

//�ϰ���
class boss :public worker {
public:
    //���캯��
    boss(int id, string name, int deptid);

    //��ʾ������Ϣ
    void showInfo();

    //��ȡ��λ����
    string getDeptName();
};