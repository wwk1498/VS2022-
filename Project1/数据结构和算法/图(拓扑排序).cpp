/*
��������
  1.ͳ��ÿ����������
  2.�����Ϊ0�Ķ���������
  3.�����в����Ƴ����㣬ÿ�Ƴ�һ�����㣬�������ڵıߵĶ������ȼ�һ��������0�����

*/
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;



//���嶥��
class Vertex {
public:
	int id;//����id
	string name;//������
	bool visited = false;//���� DFS �� BFS
	int inDegree = 0;//��ȣ�������������
	Vertex(int _id,string _name) :id(_id),name(_name) {}

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
	queue< Vertex*> myqueue;


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



	//��������
	void topsort(Graph*s) {
		//1.ͳ��ÿ����������(�����)
		
		//2.�����Ϊ0�Ķ���������
		for (Vertex* p : s->vertexs) {
			if (p->inDegree==0) {
				myqueue.push(p);
			}
		}
		//3.�����в����Ƴ����㣬ÿ�Ƴ�һ�����㣬�������ڵıߵĶ������ȼ�һ��������0�����
		while (!myqueue.empty()) {
			Vertex* tep = myqueue.front();
			myqueue.pop();
			cout << tep->name << endl;
			for (Edge* m : s->ljlist[tep->id]) {
				m->last->inDegree--;
				if (m->last->inDegree==0) {
					myqueue.push(m->last);
				}
			}


		}
		
	}






};



int main() {
	Graph* graph = new Graph;

	Vertex* a = new Vertex(0,"��ҳ����");
	Vertex* b = new Vertex(1,"Java����");
	Vertex* c = new Vertex(2,"JavaWeb");
	Vertex* d = new Vertex(3,"Spring���");
	Vertex* e = new Vertex(4, "΢������");
	Vertex* f= new Vertex(5, "���ݿ�");
	Vertex* g= new Vertex(6, "ʵս��Ŀ");

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

	
	graph->topsort(graph);


	system("pause");
	return 0;
}