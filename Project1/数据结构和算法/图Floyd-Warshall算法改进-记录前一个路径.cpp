/*

ֻ�ܼ�¼��ǰ�����ǰ��һ��������Ϊ·��


*/
#include<iostream>
#include<vector>
#include<limits.h>//�������ֵ
using namespace std;

class Edge;
class Vertex {
public:
	int id;
	string name;//��������
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


	//Floyd-Warshall�㷨
	void FloydWarshall(Graph* s) {
		//������ά���飬���Զ������Ϊ�������ռ�,����ʼ��ȫ��Ԫ��Ϊ0
		int size = s->vertexs.size();
		vector<vector<int>> myvec(size, vector<int>(size, 0));//�洢Ȩֵ
		vector<vector<Vertex*>> prev(size, vector<Vertex*>(size, NULL));//�洢��ʱ�Ķ���

		//1.k=0  ֱ����ͨ(INT_MAX���������

		//��㶥��
		for (int i = 0; i < size; i++) {
			Vertex* tw = s->vertexs[i];
			//�ڲ㶥��
			for (int j = 0; j < size; j++) {
				Vertex* tn = s->vertexs[j];
				if (tw->id == tn->id) {
					myvec[i][j] = 0;
				}
				else {
					for (Edge* m : tw->edges) {
						if (m->last->id == tn->id) {
							myvec[i][j] = m->weight;
							prev[i][j] = tw;
							break;
						}
						else {
							myvec[i][j] = INT_MAX;
						}
					}
				}
			}
		}
		for (vector<Vertex*>e : prev) {
			for (Vertex* w : e) {
				if (w != NULL) {
					cout << w->name << "  ";
				}
				else {
					cout <<"NULL  ";
				}
			}
			cout << endl;
		}
		cout << "-------------------------------" << endl;

		//2.k=i,i=1,2,3...V,����vi������������(INT_MAX���������
		//����size��ѭ��
		for (int k = 0; k < size; k++) {//k���Կ������������������

			for (int i = 0; i < size; i++) {//����������
				if (s->vertexs[i]->id != s->vertexs[k]->id && myvec[i][k] != INT_MAX) {//�����㲻���ڱ��������㡢Ȩֵ�����������
					for (int j = 0; j < size; j++) {//�ᶥ������
						if (myvec[k][j] != INT_MAX && myvec[i][k] + myvec[k][j] < myvec[i][j]) {
							myvec[i][j] = myvec[i][k] + myvec[k][j];
							prev[i][j] = prev[k][j];//��¼��ʱ��·��
						}
					}
				}
			}

			for (vector<Vertex*>e : prev) {
				for (Vertex* w : e) {
					if (w!=NULL) {
						cout << w->name << "  ";
					}else {
						cout << "NULL  ";
				    }
				}
				cout << endl;
			}
			cout << "-------------------------------" << endl;
		}
	}
};


int main() {

	//��������
	Vertex* a = new Vertex(0, "v1");
	Vertex* b = new Vertex(1, "v2");
	Vertex* c = new Vertex(2, "v3");
	Vertex* d = new Vertex(3, "v4");

	//������
	Edge* n1 = new Edge(c, -2);
	Edge* n2 = new Edge(c, 3);

	a->edges.push_back(n1);
	b->edges.push_back(n2);

	Edge* n3 = new Edge(a, 4);
	b->edges.push_back(n3);

	Edge* n4 = new Edge(b, -1);
	d->edges.push_back(n4);

	Edge* n5 = new Edge(d, 2);
	c->edges.push_back(n5);

	//����ͼ
	Graph* graph = new Graph;

	graph->vertexs.push_back(a);
	graph->vertexs.push_back(b);
	graph->vertexs.push_back(c);
	graph->vertexs.push_back(d);

	graph->FloydWarshall(graph);

	system("pause");
	return 0;
}