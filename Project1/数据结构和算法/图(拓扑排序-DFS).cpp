/*
��������
  1.ͳ��ÿ����������
  2.�����Ϊ0�Ķ���������
  3.�����в����Ƴ����㣬ÿ�Ƴ�һ�����㣬�������ڵıߵĶ������ȼ�һ��������0�����

*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;



//���嶥��
class Vertex {
public:
	int id;//����id
	string name;//������
	bool visited = false;//���� DFS �� BFS
	int inDegree = 0;//��ȣ�������������
	int status=0;//״̬ 0-δ���ʣ�1-�����У�2-���ʹ� ��������������
	Vertex(int _id, string _name) :id(_id), name(_name) {}

};
//�����
class Edge {
public:
	Vertex* last;//�ߵ��յ�
	int weight;//�ߵ�Ȩ��
	Edge(Vertex* _linked, int _weight) :last(_linked), weight(_weight) {}
};



//����ͼ
class Graph {
public:

	vector<Vertex*> vertexs;//���㼯��
	vector<vector<Edge*>> ljlist; //�ڽӱ�
	stack< Vertex*> mystack;


	//��Ӷ���
	void addvertexs(Vertex* p) {
		vertexs.push_back(p);
		ljlist.push_back(vector<Edge*>());//��ӿյ�vector<Edge*>���ͣ�Ϊ����ʹ��[]�̵�
	}

	//��ӱߺ����
	void addEdges(Vertex* p, Vertex* z, int w) {
		z->inDegree++;//������
		Edge* newedge = new Edge(z, w);
		ljlist[p->id].push_back(newedge);
	}



	//��������-DFS
	void topsort_dfs(Vertex*p,Graph* s) {
		if (p->status==2) {
			return;
		}
		if (p->status == 1) {
			cout << "���ֻ�" << endl;
			return;
		}
		p->status = 1;
		for (Edge* m : s->ljlist[p->id]) {
			topsort_dfs(m->last,s);
		}
		p->status = 2;
		mystack.push(p);

	}

};



int main() {
	Graph* graph = new Graph;

	Vertex* a = new Vertex(0, "��ҳ����");
	Vertex* b = new Vertex(1, "Java����");
	Vertex* c = new Vertex(2, "JavaWeb");
	Vertex* d = new Vertex(3, "Spring���");
	Vertex* e = new Vertex(4, "΢������");
	Vertex* f = new Vertex(5, "���ݿ�");
	Vertex* g = new Vertex(6, "ʵս��Ŀ");

	//��Ӷ���
	graph->addvertexs(a);
	graph->addvertexs(b);
	graph->addvertexs(c);
	graph->addvertexs(d);
	graph->addvertexs(e);
	graph->addvertexs(f);
	graph->addvertexs(g);

	//��ӱ�
	graph->addEdges(a, c, 10);
	graph->addEdges(b, c, 10);
	graph->addEdges(f, d, 10);
	graph->addEdges(c, d, 10);
	graph->addEdges(d, e, 10);
	graph->addEdges(e, g, 10);
	graph->addEdges(g, e, 10);

	
	for (Vertex*n:graph->vertexs) {
		graph->topsort_dfs(n, graph);
	}
	
	while (!graph->mystack.empty()) {
		Vertex* tep = graph->mystack.top();
		graph->mystack.pop();
		cout << tep->name << endl;
	}

	system("pause");
	return 0;
}