#pragma once
#include<iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间

//职工抽象类
class worker {
public:

    //显示个人信息
    virtual void showInfo()=0;

    //获取岗位名称
    virtual string getDeptName()=0;

    //职工编号
    int m_Id;
    //职工姓名
    string m_Name;
    //部门编号
    int m_DeptId;
};