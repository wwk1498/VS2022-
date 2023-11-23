#pragma once
#include<iostream>//包含输入输出流头文件
#include"worker.h"
using namespace std;//使用标准命名空间

//普通员工类
class employee:public worker {
public:
    //构造函数
    employee(int id,string name,int deptid);

    //显示个人信息
     void showInfo();

    //获取岗位名称
     string getDeptName();
};