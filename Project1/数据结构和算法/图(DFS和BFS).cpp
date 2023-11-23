
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;



//定义顶点
class Vertex {
public:
	int id;//顶点
	bool visited = false;
	Vertex(int _id):id(_id){}
	
};
//定义边
class Edge {
public:
	Vertex* last;//边的终点
	int weight;//边的权重
	Edge(Vertex* _linked,int _weight):last(_linked),weight(_weight){}
};



//定义图
class Graph {
public:
	
	vector<Vertex*> vertexs;//顶点集合
	vector<vector<Edge*>> ljlist; //邻接表
	stack< Vertex*> mystack;
	queue< Vertex*> myqueue;


	//添加顶点
	void addvertexs(Vertex*p) {
		vertexs.push_back(p);
		ljlist.push_back(vector<Edge*>());//添加空的vector<Edge*>类型，为后面使用[]铺垫
	}

	//添加边
	void addEdges(Vertex*p,Vertex*z,int w) {
		Edge* newedge = new Edge(z, w);
		ljlist[p->id].push_back(newedge);
	}

	//递归实现DFS
	void dfs(Vertex* x,Graph*s) {
		x->visited = true;
		cout << x->id << endl;
		for (Edge* m : s->ljlist[x->id]) {
			if (!m->last->visited) {
				dfs(m->last,s);
			}
		}
	}

	//非递归实现DFS
	void dfsa(Vertex* x, Graph* s) {
		mystack.push(x);
		while (!mystack.empty()) {
			Vertex* tep = mystack.top();//获取栈顶元素
			mystack.pop();//移除栈顶元素
			tep->visited = true;
			cout << tep->id << endl;
			for (Edge* m : s->ljlist[tep->id]) {
				if (!m->last->visited) {
					mystack.push(m->last);
				}
			}
		}
	}

	//非递归实现BFS
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
		cout << "顶点" << graph->vertexs[i]->id<<": ";
		
		for (int j = 0; j < graph->ljlist[i].size(); j++) {
			cout <<"  ->" << graph->ljlist[i][j]->last->id<<" " << graph->ljlist[i][j]->weight;
		} 
		cout << endl;
	}

	//测试其一
	cout << "------------------------" << endl;
	//graph->dfsa(graph->vertexs[0], graph);


	cout << "--------------------------" << endl;
	graph->bfs(graph->vertexs[0], graph);
	system("pause");
	return 0;
}