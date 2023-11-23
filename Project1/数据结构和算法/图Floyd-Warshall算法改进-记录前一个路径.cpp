/*

只能记录当前顶点的前面一个顶点作为路径


*/
#include<iostream>
#include<vector>
#include<limits.h>//最大整数值
using namespace std;

class Edge;
class Vertex {
public:
	int id;
	string name;//顶点名字
	vector<Edge*> edges;//当前顶点连接的边
	Vertex(int _id, string _name) :id(_id), name(_name) {}
};

class Edge {
public:
	Vertex* last;//边的终点
	int weight;//权重
	Edge(Vertex* p, int _weight) :last(p), weight(_weight) {}
};

class Graph {
public:
	vector<Vertex*> vertexs;//顶点集合


	//Floyd-Warshall算法
	void FloydWarshall(Graph* s) {
		//创建二维数组，并以顶点个数为数组分配空间,并初始化全部元素为0
		int size = s->vertexs.size();
		vector<vector<int>> myvec(size, vector<int>(size, 0));//存储权值
		vector<vector<Vertex*>> prev(size, vector<Vertex*>(size, NULL));//存储来时的顶点

		//1.k=0  直接连通(INT_MAX代表无穷大）

		//外层顶点
		for (int i = 0; i < size; i++) {
			Vertex* tw = s->vertexs[i];
			//内层顶点
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

		//2.k=i,i=1,2,3...V,借助vi到达其他顶点(INT_MAX代表无穷大）
		//进行size轮循环
		for (int k = 0; k < size; k++) {//k可以看做被借助顶点的索引

			for (int i = 0; i < size; i++) {//竖顶点索引
				if (s->vertexs[i]->id != s->vertexs[k]->id && myvec[i][k] != INT_MAX) {//竖顶点不等于被借助顶点、权值不等于无穷大
					for (int j = 0; j < size; j++) {//横顶点索引
						if (myvec[k][j] != INT_MAX && myvec[i][k] + myvec[k][j] < myvec[i][j]) {
							myvec[i][j] = myvec[i][k] + myvec[k][j];
							prev[i][j] = prev[k][j];//记录来时的路径
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

	//创建顶点
	Vertex* a = new Vertex(0, "v1");
	Vertex* b = new Vertex(1, "v2");
	Vertex* c = new Vertex(2, "v3");
	Vertex* d = new Vertex(3, "v4");

	//创建边
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

	//创建图
	Graph* graph = new Graph;

	graph->vertexs.push_back(a);
	graph->vertexs.push_back(b);
	graph->vertexs.push_back(c);
	graph->vertexs.push_back(d);

	graph->FloydWarshall(graph);

	system("pause");
	return 0;
}