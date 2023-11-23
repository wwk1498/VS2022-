
#pragma once
#include<iostream>//包含输入输出流头文件
#include"worker.h"
using namespace std;//使用标准命名空间

//经理类
class manager :public worker {
public:
    //构造函数
    manager(int id,string name,int deptid);

    //显示个人信息
    void showInfo();

    //获取岗位名称
    string getDeptName();
};