/*
Dijkstra���Ͽ�˹��������Դ���·���㷨(Ҫ��ߵ�Ȩֵ�Ǹ���:

1.����һ������ļ��ϡ�

2.Ϊÿ���������һ����ʱ����ֵ:
       1.�������ǵĳ�ʼ���㣬������Ϊ�㡣
       2.���������������㣬��������Ϊ�����

3.ÿ��ѡ����С��ʱ����Ķ��㣬��Ϊ�µĵ�ǰ����

4.���ڵ�ǰ���㣬���������е��ھӣ����������ǵ���ʱ����Ϊ��С:
      ����1--��6�ľ�����14����1--��3-->6�ľ�����11����ʱ���������Ϊ11��
      ���򣬽������ϴξ���ֵ
      ͬʱ�����ھӽڵ��ǰһ���ڵ����Ϊ��ǰ�ڵ�

5.��¼·���������

6.��ǰ������ھӴ�����ɺ󣬰ѵ�ǰ�ڵ�Ӽ�����ɾ��

*/
#include<iostream>
#include<vector>
#include<stack>
#include<climits>//int inf=INT_MAX��ʾ�������͵����ֵ
using namespace std;

class Edge;
class Vertex {
public:
    int id;
    string name;//��������
    int dist = INT_MAX;//����
    Vertex* per;
    vector<Edge*> edges;//��ǰ�������ӵı�
    Vertex(int _id, string _name) :id(_id), name(_name) {}
};

class Edge {
public:
    Vertex* last;//�ߵ��յ�
    int weight;//Ȩ��
    Edge(Vertex* p, int _weight) :last(p), weight(_weight) {}
};

class Graph {
public:
    vector<Vertex*> vertexs;//���㼯��
    stack<Vertex*>mystack;

   

    //���ؾ�����С�Ľڵ�
    Vertex* minvretex(Graph* s) {
        Vertex* min = s->vertexs[0];
        for (int i = 1; i < s->vertexs.size(); i++) {
            if (s->vertexs[i]->dist < min->dist) {
                min = s->vertexs[i];
            }
        }
        return min;
    }

    //ɾ����ǰ�ڵ�
    void erasee(Vertex* p, Graph* s) {
        auto it = find(s->vertexs.begin(), s->vertexs.end(), p);
        if (it != s->vertexs.end()) {
            s->vertexs.erase(it);
        }
    }

   
    //��¼·���������·��
    void lujin(Vertex* mindisk) {
        Vertex* tep = mindisk;
        while (tep->per!=NULL) {
            mystack.push(tep->per);
            tep = tep->per;
        }

        while (!mystack.empty()) {
            Vertex* p = mystack.top();
            mystack.pop();
            cout << p->name << "-->";
        }
    }


    //Dijkstra�㷨
    void dijkstra(Graph* s) {
        
        s->vertexs[0]->dist = 0;//1.���ó�ʼ����ľ���Ϊ0
        while (!s->vertexs.empty()) {
            //3.ѡȡ��ǰ�ڵ�
            Vertex* mindisk = minvretex(s);
            //4.���µ�ǰ�ڵ��ھӵľ���
            for (Edge* m : mindisk->edges) {
                int tepdisk = mindisk->dist + m->weight;
                if (tepdisk < m->last->dist) {
                    m->last->dist = tepdisk;
                    m->last->per = mindisk;
                }
            }
            //��¼·���������·��
            lujin(mindisk);
            //�����ǰ�ڵ�ľ���
            cout << mindisk->name << ": " << mindisk->dist << endl;
            //5.�Ƴ���ǰ�ڵ�
            erasee(mindisk, s);
        }
    }

};


int main() {
    //��������
    Vertex* a = new Vertex(0, "v1");
    Vertex* b = new Vertex(1, "v2");
    Vertex* c = new Vertex(2, "v3");
    Vertex* d = new Vertex(3, "v4");
    Vertex* e = new Vertex(4, "v5");
    Vertex* f = new Vertex(5, "v6");

    //������
    Edge* n6 = new Edge(e, 9);
    Edge* n7 = new Edge(e, 6);

    d->edges.push_back(n7);
    f->edges.push_back(n6);

    Edge* n4 = new Edge(d, 11);
    Edge* n8 = new Edge(d, 15);

    b->edges.push_back(n8);
    c->edges.push_back(n4);

    Edge* n5 = new Edge(f, 2);
    c->edges.push_back(n5);

    Edge* n1 = new Edge(b, 7);
    Edge* n3 = new Edge(f, 14);
    Edge* n2 = new Edge(c, 9);

    a->edges.push_back(n1);
    a->edges.push_back(n2);
    a->edges.push_back(n3);

    //����ͼ
    Graph* grap = new Graph;

    //��ͼ��Ӷ���
    grap->vertexs.push_back(a);
    grap->vertexs.push_back(b);
    grap->vertexs.push_back(c);
    grap->vertexs.push_back(d);
    grap->vertexs.push_back(e);
    grap->vertexs.push_back(f);

    grap->dijkstra(grap);

    system("pause");
    return 0;
}