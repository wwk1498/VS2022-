#include <iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
using gg = long long;
constexpr gg INF = 2e18;  //��ʾ�����
struct File {
    gg size;  //���ļ�����ʾ�ļ���С������Ϊ0
    gg ld, lr;  //��Ŀ¼����ʾ��Ŀ¼�����ļ��ܴ�С������ļ��ܴ�С�������Ϊ0
    gg ldsize, lrsize;  //��Ŀ¼����ʾĿ¼���ͺ���������Ϊ0
    bool isFile;  //�Ƿ����ļ�
    unordered_map<string, File*> child;  //���ļ�����Ŀ¼
    File(gg sz, bool file) : size(sz), isFile(file), ld(INF), lr(INF), ldsize(0), lrsize(0) {}
};
//�ָ��ַ���
vector<string> split(const string& s, string c = " ") {
    vector<string> ans;
    for (gg i = 0, j = 0; i < s.size(); i = j + 1) {
        j = s.find(c, i);
        if (j == -1) {
            j = s.size();
        }
        ans.push_back(s.substr(i, j - i));
    }
    return ans;
}
//���path��ʾ�ļ��������ļ���С�����򷵻�0
gg fileSize(File* root, const vector<string>& path) {
    for (gg i = 1; i < path.size() and root; i++) {
        root = root->child.count(path[i]) ? root->child[path[i]] : nullptr;
    }
    return root and root->isFile ? root->size : 0;
}
//���path·���Ƿ��ܴ���һ���µ��ļ�
bool canCreateFile(File* root, const vector<string>& path, gg sz) {
    for (gg i = 1; i < path.size() and root; i++) {
        if (root->isFile or root->lrsize + sz > root->lr or (i == path.size() - 1 and root->ldsize + sz > root->ld)) {
            return false;
        }
        root = root->child.count(path[i]) ? root->child[path[i]] : nullptr;
    }
    return not root or root->isFile;
}
//������ܳɹ������ļ�������false��sz��ʾ�˴δ����ļ��Ĵ�С
bool createFile(File* root, const vector<string>& path, gg sz) {
    gg curSize = fileSize(root, path);
    sz -= curSize;
    if (not canCreateFile(root, path, sz)) {  // path·���²��ܴ����ļ�������false
        return false;
    }
    for (gg i = 1; i < path.size() - 1; i++) {
        root->lrsize += sz;
        if (not root->child.count(path[i])) {
            root->child[path[i]] = new File(0, false);
        }
        root = root->child[path[i]];
    }
    root->lrsize += sz, root->ldsize += sz;
    if (not root->child.count(path.back())) {
        root->child[path.back()] = new File(0, true);
    }
    root->child[path.back()]->size += sz;
    return true;
}
//ɾ���ļ�
void removeFile(File* root, const vector<string>& path) {
    auto r = root;
    for (gg i = 1; i < path.size() and r; i++) {
        r = r->child.count(path[i]) ? r->child[path[i]] : nullptr;
    }
    if (not r) {  //Ҫɾ����·��������
        return;
    }
    gg sz = r->isFile ? r->size : r->lrsize;
    for (gg i = 1; i < path.size() - 1 and root; i++) {
        root->lrsize -= sz;
        root = root->child[path[i]];
    }
    root->lrsize -= sz;
    if (r->isFile) {
        root->ldsize -= sz;
    }
    root->child.erase(path[path.size() - 1]);
}
//�޸����
bool QFile(File* root, const vector<string>& path, gg ld, gg lr) {
    for (gg i = 1; i < path.size() and root; i++) {
        root = root->child.count(path[i]) ? root->child[path[i]] : nullptr;
    }
    if (not root or root->isFile or root->lrsize > lr or root->ldsize > ld) {
        return false;
    }
    root->lr = lr;
    root->ld = ld;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ld, lr, sz;
    cin >> ni;
    string c, path;
    File* root = new File(0, false);  //��ʾ��Ŀ¼�Ľ��
    while (ni--) {
        cin >> c >> path;
        auto pathSplit = split(path, "/");
        if (c == "C") {
            cin >> sz;
            cout << (createFile(root, pathSplit, sz) ? "Y" : "N") << "\n";
        }
        else if (c == "R") {
            removeFile(root, pathSplit);
            cout << "Y\n";
        }
        else {
            cin >> ld >> lr;
            ld = ld == 0 ? INF : ld;
            lr = lr == 0 ? INF : lr;
            cout << (QFile(root, pathSplit, ld, lr) ? "Y" : "N") << "\n";
        }
    }
    return 0;
}