
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;



//���嶥��
class Vertex {
public:
	int id;//����
	bool visited = false;
	Vertex(int _id):id(_id){}
	
};
//�����
class Edge {
public:
	Vertex* last;//�ߵ��յ�
	int weight;//�ߵ�Ȩ��
	Edge(Vertex* _linked,int _weight):last(_linked),weight(_weight){}
};



//����ͼ
class Graph {
public:
	
	vector<Vertex*> vertexs;//���㼯��
	vector<vector<Edge*>> ljlist; //�ڽӱ�
	stack< Vertex*> mystack;
	queue< Vertex*> myqueue;


	//��Ӷ���
	void addvertexs(Vertex*p) {
		vertexs.push_back(p);
		ljlist.push_back(vector<Edge*>());//��ӿյ�vector<Edge*>���ͣ�Ϊ����ʹ��[]�̵�
	}

	//��ӱ�
	void addEdges(Vertex*p,Vertex*z,int w) {
		Edge* newedge = new Edge(z, w);
		ljlist[p->id].push_back(newedge);
	}

	//�ݹ�ʵ��DFS
	void dfs(Vertex* x,Graph*s) {
		x->visited = true;
		cout << x->id << endl;
		for (Edge* m : s->ljlist[x->id]) {
			if (!m->last->visited) {
				dfs(m->last,s);
			}
		}
	}

	//�ǵݹ�ʵ��DFS
	void dfsa(Vertex* x, Graph* s) {
		mystack.push(x);
		while (!mystack.empty()) {
			Vertex* tep = mystack.top();//��ȡջ��Ԫ��
			mystack.pop();//�Ƴ�ջ��Ԫ��
			tep->visited = true;
			cout << tep->id << endl;
			for (Edge* m : s->ljlist[tep->id]) {
				if (!m->last->visited) {
					mystack.push(m->last);
				}
			}
		}
	}

	//�ǵݹ�ʵ��BFS
	void bfs(Vertex* x, Graph* s) {
		myqueue.push(x);
		x->visited = true;
		while (!myqueue.empty()) {
			Vertex* tep = myqueue.front();
			myqueue.pop();
			cout << tep->id <<endl;
			for (Edge* m : s->ljlist[tep->id]) {
				if (!m->last->visited) {
					m->last->visited = true;
					myqueue.push(m->last);
				}
			}
		}

	}


};



int main() {
	Graph* graph = new Graph;

	Vertex* a = new Vertex(0);
	Vertex* b = new Vertex(1);
	Vertex* c = new Vertex(2);
	Vertex* d = new Vertex(3);

	graph->addvertexs(a);
	graph->addvertexs(b);
	graph->addvertexs(c);
	graph->addvertexs(d);
	

	graph->addEdges(a,b, 10);
	graph->addEdges(a,c, 30);
	graph->addEdges(b,d, 20);
	graph->addEdges(c,d, 40);
	
	for (int i = 0; i < graph->vertexs.size(); i++) {
		cout << "����" << graph->vertexs[i]->id<<": ";
		
		for (int j = 0; j < graph->ljlist[i].size(); j++) {
			cout <<"  ->" << graph->ljlist[i][j]->last->id<<" " << graph->ljlist[i][j]->weight;
		} 
		cout << endl;
	}

	//������һ
	cout << "------------------------" << endl;
	//graph->dfsa(graph->vertexs[0], graph);


	cout << "--------------------------" << endl;
	graph->bfs(graph->vertexs[0], graph);
	system("pause");
	return 0;
}