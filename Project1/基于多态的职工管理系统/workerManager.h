#pragma once//防止头文件重复包含
#include<iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
#include<fstream>
#define FILENAME "E:\\Users\\ASUS\\Desktop\\empFile.txt"

class workerManager {
public:
	int m_EmpNum;//记录职工人数
	worker** m_EmpArray;//职工数组指针
	bool m_FileIsEmpty;//判断文件是否为空

	workerManager();//构造函数

	void show_menu();//展示菜单
	void exitsystem(); //退出系统
	void Add_Emp();//添加职工
	int get_EmpNum();//统计文件中的人数
	void init_Emp();//初始化员工
	void show_Emp();//显示职工
	void Del_Emp();//删除职工
	void Mod_Emp();//修改职工
	void Find_Emp();//查找职工
	void sort_Emp();//给职工排序
	void clean_Emp();//清空文件
	int isExist(int id);//判断职工是否存在
	void save();//保存文件

	~workerManager();//析构函数
};
