/*
拓扑排序：
  1.统计每个顶点的入度
  2.将入度为0的顶点加入队列
  3.队列中不断移除顶点，每移除一个顶点，把它相邻的边的顶点的入度减一，若减到0则入队

*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;



//定义顶点
class Vertex {
public:
	int id;//顶点id
	string name;//顶点名
	bool visited = false;//用在 DFS 和 BFS
	int inDegree = 0;//入度，用在拓扑排序
	int status=0;//状态 0-未访问，1-访问中，2-访问过 ，用在拓扑排序
	Vertex(int _id, string _name) :id(_id), name(_name) {}

};
//定义边
class Edge {
public:
	Vertex* last;//边的终点
	int weight;//边的权重
	Edge(Vertex* _linked, int _weight) :last(_linked), weight(_weight) {}
};



//定义图
class Graph {
public:

	vector<Vertex*> vertexs;//顶点集合
	vector<vector<Edge*>> ljlist; //邻接表
	stack< Vertex*> mystack;


	//添加顶点
	void addvertexs(Vertex* p) {
		vertexs.push_back(p);
		ljlist.push_back(vector<Edge*>());//添加空的vector<Edge*>类型，为后面使用[]铺垫
	}

	//添加边和入度
	void addEdges(Vertex* p, Vertex* z, int w) {
		z->inDegree++;//添加入度
		Edge* newedge = new Edge(z, w);
		ljlist[p->id].push_back(newedge);
	}



	//拓扑排序-DFS
	void topsort_dfs(Vertex*p,Graph* s) {
		if (p->status==2) {
			return;
		}
		if (p->status == 1) {
			cout << "发现环" << endl;
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

	Vertex* a = new Vertex(0, "网页基础");
	Vertex* b = new Vertex(1, "Java基础");
	Vertex* c = new Vertex(2, "JavaWeb");
	Vertex* d = new Vertex(3, "Spring框架");
	Vertex* e = new Vertex(4, "微服务框架");
	Vertex* f = new Vertex(5, "数据库");
	Vertex* g = new Vertex(6, "实战项目");

	//添加顶点
	graph->addvertexs(a);
	graph->addvertexs(b);
	graph->addvertexs(c);
	graph->addvertexs(d);
	graph->addvertexs(e);
	graph->addvertexs(f);
	graph->addvertexs(g);

	//添加边
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