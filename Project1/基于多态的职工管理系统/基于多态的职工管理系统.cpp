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
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice) {
		case 0:wm.exitsystem();//�˳�ϵͳ
			break;
		case 1:wm.Add_Emp();//���ְ��
			break;
		case 2: wm.show_Emp();//��ʾְ��
			break;
		case 3:wm.Del_Emp();//ɾ��ְ��
			break;
		case 4:wm.Mod_Emp();//�޸�ְ��
			break;
		case 5:wm.Find_Emp();//����ְ��
			break;
		case 6:wm.sort_Emp();//����ְ��
			break;
		case 7:wm.clean_Emp();//����ļ�
			break;
		default:
			system("cls");//����
			break;
		}
	}
	
	system("pause");
	return 0;
}