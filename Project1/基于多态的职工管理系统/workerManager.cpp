#include"workerManager.h"

workerManager::workerManager() {//构造函数

    ifstream ifs(FILENAME, ios::in);//读文件

    //1.当文件不存在
    if (!ifs.is_open()) {
        //cout << "文件不存在！" << endl;
        this->m_EmpNum = 0;//初始化记录人数
        this->m_EmpArray = NULL;//初始化数组指针
        this->m_FileIsEmpty = true;//初始化文件是否为空
        ifs.close();//关闭文件
        return;
    }

    //2.当文件存在，数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
       // cout << "文件为空！" << endl;
        this->m_EmpNum = 0;//初始化记录人数
        this->m_EmpArray = NULL;//初始化数组指针
        this->m_FileIsEmpty = true;//初始化文件是否为空
        ifs.close();//关闭文件
        return;
    }

    //当文件存在，且记录数据
    int num = this->get_EmpNum();
   // cout << "职工人数为：" << num << endl;
    this->m_EmpNum = num;

    //开辟空间
    this->m_EmpArray = new worker * [this->m_EmpNum];

    //将文件中的数据存储在数组
    this->init_Emp();
}

void workerManager::show_menu() { //展示菜单
    cout << "******************************************************" << endl;
    cout << "***********欢迎来到职工管理系统！************" << endl;
    cout << "***********0.退出程序************" << endl;
    cout << "***********1.增加职工************" << endl;
    cout << "***********2.显示所有职工信息************" << endl;
    cout << "***********3.删除职工************" << endl;
    cout << "***********4.修改职工信息************" << endl;
    cout << "***********5.查找职工信息************" << endl;
    cout << "***********6.按职工编号排序************" << endl;
    cout << "***********7.清空文档************" << endl;
    cout << "******************************************************" << endl;
}

void workerManager::exitsystem()//退出系统
{
    cout << "欢迎下次使用！" << endl;
    system("pause");
    exit(0);
}

void workerManager::Add_Emp()//添加职工
{
    cout << "请输入添加职工的数量：" << endl;
    int addNum;//新增人数
    cin >> addNum;
    if (addNum > 0) {
        int newSize=this->m_EmpNum+ addNum;//计算新空间的大小
        worker **newSpace=new worker* [newSize];//开辟新空间

        //将原来空间下的数据拷贝到新空间
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //添加新数据
        for (int j = 0; j < addNum; j++) {

            int id;//职工编号
            string name;//姓名
            int dselect;//部门选择

            cout << "请输入第" << j + 1 << "个员工的编号" << endl;
            cin >> id;
            cout << "请输入第" << j + 1 << "个员工的姓名" << endl;
            cin >> name;
            cout << "请选择该职工的岗位：" << endl;
            cout << "1.普通员工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin>> dselect;

            worker* work = NULL;//创建职工指针
            switch (dselect) {
            case 1:
                work = new employee(id, name, 1);
                break;
            case 2:
                work = new manager(id, name, 2);
                break;
            case 3:
                work = new boss(id, name, 3);
                break;
            default:
                break;
            }
            //将创建的职工指针保存到数组
            newSpace[this->m_EmpNum + j] = work;
        }
        //释放原有空间
        delete[] this->m_EmpArray;
        //更改新空间的指向
        this->m_EmpArray = newSpace;
        //更新新的职工人数
        this->m_EmpNum = newSize;
        //更新职工不为空标志
        this->m_FileIsEmpty = false;
        //保存数据到文件
        this->save();
        //提示
        cout << "成功添加" << addNum << "新职工" << endl;
    }
    else {
        cout << "输入的数据有误！" << endl;
    }
    system("pause");
    system("cls");
}

int workerManager::get_EmpNum()//统计文件中的人数
{
    ifstream ifs(FILENAME, ios::in);//读文件
    int id;
    string name;
    int dId;

    int num=0;//记录人数
    while (ifs >> id && ifs >> name && ifs >> dId) {
        num++;
    }
    ifs.close();
    return num;
}

void workerManager::init_Emp()//初始化员工
{
    ifstream ifs(FILENAME, ios::in);//读文件

    int id;
    string name;
    int dId;

    int index=0;
    while (ifs >> id && ifs >> name && ifs >> dId) {
        worker* work = NULL;
        if (dId == 1) {
            work = new employee(id, name, dId);
        }
        else if (dId == 2) {
            work = new manager(id, name, dId);
        }
        else {
            work = new boss(id, name, dId);
        }

        this->m_EmpArray[index] = work;
        index++;
    }
    ifs.close();
}

void workerManager::show_Emp()//显示职工
{
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或者记录为空！" << endl;
    }
    else {
        for (int i = 0; i < this->m_EmpNum; i++) {
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

void workerManager::Del_Emp()//删除职工
{
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或者记录为空" << endl;
    }
    else {
        cout << "请输入想要删除的职工编号：" << endl;
        int id;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1) {
            for (int i = index; i < this->m_EmpNum; i++) {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;
            this->save();
            cout << "删除成功！" << endl;
        }
        else {
            cout << "未找到该职工！" << endl;
        }
    }
    system("pause");
    system("cls");
}

void workerManager::Mod_Emp()//修改职工
{
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或者记录为空" << endl;
    }
    else {
        cout << "请输入想要修改的职工编号：" << endl;
        int id;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1) {
            delete this->m_EmpArray[index];
            int newid;
            string name;
            int dselect;
            cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
            cin >> newid;
            cout << "请输入新的姓名：" << endl;
            cin >> name;
            cout << "请选择该职工的岗位：" << endl;
            cout << "1.普通员工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dselect;
            worker* work = NULL;
            switch (dselect) {
            case 1:
                work = new employee(newid, name, dselect);
                break;
            case 2:
                work = new manager(newid, name, dselect);
                break;
            case 3:
                work = new boss(newid, name, dselect);
                break;
            default:
                break;
            }
            this->m_EmpArray[index] = work;
            this->save();
            cout << "修改成功！" << endl;
        }
        else {
            cout << "未找到该职工！" << endl;
        }
    }
    system("pause");
    system("cls");
}

void workerManager::Find_Emp()//查找职工
{
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或者记录为空" << endl;
    }
    else {
        cout << "请输入查找方式:" << endl;
        cout << "1.按职工编号查找" << endl;
        cout << "2.按姓名查找" << endl;
        int select;
        cin >> select;
        if (select == 1) {
            cout << "请输入要查到的职工编号：" << endl;
            int id;
            cin >> id;
            int ref = this->isExist(id);
            if (ref != -1) {
                cout << "查找成功，该职工信息如下：" << endl;
                this->m_EmpArray[ref]->showInfo();
            }
            else {
                cout << "查无此人！" << endl;
            }
        }
        else if (select == 2) {
            cout << "请输入查找的姓名：" << endl;
            string name;
            bool flag=false;
            cin >> name;
            for (int i = 0; i < this->m_EmpNum; i++) {
                if (this->m_EmpArray[i]->m_Name == name) {
                    cout << "查到成功，职工编号为：" << this->m_EmpArray[i]->m_Id
                        << "职工信息如下：" << endl;
                    this->m_EmpArray[i]->showInfo();
                    flag = true;
                }
            }
            if (flag == false) {
                cout << "查无此人！" << endl;
            }
        }
        else {
            cout << "输入错误！" << endl;
        }
    }
    system("pause");
    system("cls");
}

void workerManager::sort_Emp()//给职工排序
{

    if (this->m_FileIsEmpty) {
        cout << "文件不存在或者记录为空" << endl;
        system("pause");
        system("cls");
    }
    else {
        cout << "请选择排序方式：" << endl;
        cout << "1.按职工号升序排序" << endl;
        cout << "2.按职工号降序排序" << endl;
        int select;
        cin >> select;
        for (int i = 0; i < this->m_EmpNum; i++) {
            int minormax=i;
            for (int j = i + 1; j < this->m_EmpNum; j++) {
                if (select == 1) {//升序
                    if (this->m_EmpArray[minormax]->m_Id > this->m_EmpArray[j]->m_Id) {
                        minormax = j;
                    }
                }
                else if(select == 2){//降序
                    if (this->m_EmpArray[minormax]->m_Id < this->m_EmpArray[j]->m_Id) {
                        minormax = j;
                    }
                }
            }
            if (i != minormax) {
                worker* temp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[minormax];
                this->m_EmpArray[minormax] = temp;
            }
        }
        this->save();
        cout << "排序成功！排序后的结果为：" << endl;
        this->show_Emp();
    }
    
}

void workerManager::clean_Emp()//清空文件
{
    cout << "确认要清空吗？" << endl;
    cout << "1.确认" << endl;
    cout << "2.取消" << endl;
    int select;
    cin >> select;
    if (select == 1) {
        ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
        ofs.close();
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                delete this->m_EmpArray[i];
                this->m_EmpArray[i] = NULL;
            }
            delete this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_EmpNum = 0;
            this->m_FileIsEmpty = true;

        }
        cout << "清空成功！" << endl;
    }
    else if (select == 2) {
        system("pause");
        system("cls");
        return;
    }
    else {
        cout << "输入错误！" << endl;
    }
    system("pause");
    system("cls");
}

int workerManager::isExist(int id)//判断职工是否存在
{
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_Id == id) {
            index = i;
            break;
        }
    }
    return index;
}

void workerManager::save()//保存文件
{
    ofstream ofs(FILENAME, ios::out);//输出的方式打开文件--写文件
    for (int i = 0; i < this->m_EmpNum; i++) {
        ofs << this->m_EmpArray[i]->m_Id << "  "
            << this->m_EmpArray[i]->m_Name << "  "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    //关闭文件
    ofs.close();
}

workerManager::~workerManager() {//析构函数
    if (this->m_EmpArray != NULL) {
        for (int i = 0; i < this->m_EmpNum; i++) {
            delete this->m_EmpArray[i];
            this->m_EmpArray[i] = NULL;
        }
        delete this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}
