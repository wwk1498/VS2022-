/*
* 
Bellman-Ford�㷨(��Դ���·���㷨)���ɴ����и�Ȩֵ�ı�,ʱ�临�Ӷ�ΪO(VE)��V--��������E--����,����������Ҫ����V-1�ε���

����������һ����ʹ�øû��ϵ����б�Ȩ������Ϊ���������

1.����һ������ļ��ϡ�

2.Ϊÿ���������һ����ʱ����ֵ:
       1.�������ǵĳ�ʼ���㣬������Ϊ�㡣
       2.���������������㣬��������Ϊ�����

3.����V-1�Σ�ÿ�α���һ�����㣬�� ��ǰ�������� < V-1����������ھӶ���ľ��룬����ǰһ�����㣬�����׳��쳣"���ָ���"

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
    Vertex* per = NULL;//��ǰ�����per��
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

    //Bellman-Ford�㷨
    void bellmanFord(Graph* s) {
        s->vertexs[0]->dist = 0;

        //����V-1��
        for (int i = 0; i < s->vertexs.size(); i++) {
            //��ȡ��ǰ����,�����Ӧ�ıߣ����ߵ��յ�
            for (Vertex* tp : s->vertexs) {
                for (Edge* w : tp->edges) {
                    int newdisk = tp->dist + w->weight;
                    if (newdisk < w->last->dist) {
                        if (i< s->vertexs.size()-1) {
                            w->last->dist = newdisk;
                            w->last->per = tp;
                        }
                        else {
                            throw runtime_error("���ָ�����");
                        }
                        
                    }
                }
            }
        }

        for (Vertex* p : s->vertexs) {
            cout << p->name << " :" << p->dist << " " << (p->per != NULL ? p->per->name : "NULL") << endl;
        }

    }

};
int main() {


    //��������
    Vertex* a = new Vertex(0, "V1");
    Vertex* b = new Vertex(1, "v2");
    Vertex* c = new Vertex(2, "v3");
    Vertex* d = new Vertex(3, "v4");

    //������
    Edge* n1 = new Edge(d, 1);
    c->edges.push_back(n1);

    Edge* n2 = new Edge(c, -4);
    b->edges.push_back(n2);

    Edge* n3 = new Edge(b, 2);
    a->edges.push_back(n3);

    Edge* n4 = new Edge(a, 1);
    c->edges.push_back(n4);


    //����ͼ
    Graph* graph = new Graph;
    //��ӱ�
    graph->vertexs.push_back(a);
    graph->vertexs.push_back(b);
    graph->vertexs.push_back(c);
    graph->vertexs.push_back(d);

    try{
        graph->bellmanFord(graph);
    }
    catch(const exception & e){
        cout << "��׽���쳣��" << e.what() << endl;
    }
   

    system("pause");
    return 0;
}