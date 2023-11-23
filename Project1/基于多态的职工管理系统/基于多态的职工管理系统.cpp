#include<iostream>
using namespace std;
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"

int main() {
	workerManager wm;
	int choice;

	while(true){
		wm.show_menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice) {
		case 0:wm.exitsystem();//退出系统
			break;
		case 1:wm.Add_Emp();//添加职工
			break;
		case 2: wm.show_Emp();//显示职工
			break;
		case 3:wm.Del_Emp();//删除职工
			break;
		case 4:wm.Mod_Emp();//修改职工
			break;
		case 5:wm.Find_Emp();//查找职工
			break;
		case 6:wm.sort_Emp();//排序职工
			break;
		case 7:wm.clean_Emp();//清空文件
			break;
		default:
			system("cls");//清屏
			break;
		}
	}
	
	system("pause");
	return 0;
}