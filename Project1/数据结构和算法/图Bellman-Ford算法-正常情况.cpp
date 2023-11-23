/*
Bellman-Ford算法(单源最短路径算法)：可处理有负权值的边,时间复杂度为O(VE)，V--顶点数，E--边数,在最坏情况下需要进行V-1次迭代

1.创建一个顶点的集合。

2.为每个顶点分配一个临时距离值:
       1.对于我们的初始顶点，设置其为零。
       2.对于所有其他顶点，将其设置为无穷大。

3.遍历V-1次，每次遍历一个顶点，更新其邻居顶点的距离，设置前一个顶点

*/

#include<iostream>
#include<vector>
#include<stack>
#include<climits>//int inf=INT_MAX表示整数类型的最大值

using namespace std;

class Edge;

class Vertex {
public:
    int id;
    string name;//顶点名字
    int dist = INT_MAX;//距离
    Vertex* per=NULL;//当前顶点从per来
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
    stack<Vertex*>mystack;

    //Bellman-Ford算法
    void bellmanFord(Graph*s) {
        s->vertexs[0]->dist = 0;

        //遍历V-1轮
        for (int i = 0; i < s->vertexs.size()-1; i++) {
            //获取当前顶点,及其对应的边，及边的终点
            for (Vertex*tp:s->vertexs) {
                for (Edge*w :tp->edges) {
                    int newdisk = tp->dist + w->weight;
                    if (newdisk<w->last->dist) {
                        w->last->dist = newdisk;
                        w->last->per = tp;
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
   

    //创建顶点
    Vertex* a = new Vertex(0, "V1");
    Vertex* b = new Vertex(1, "v2");
    Vertex* c = new Vertex(2, "v3");
    Vertex* d = new Vertex(3, "v4");

    //创建边
    Edge* n1 = new Edge(d, 1);
    c->edges.push_back(n1);

    Edge* n2 = new Edge(c, -2);
    b->edges.push_back(n2);

    Edge* n3 = new Edge(c, 1);
    a->edges.push_back(n3);

    Edge* n4 = new Edge(b, 2);
    a->edges.push_back(n4);
   
    //创建图
    Graph* graph = new Graph;
    //添加边
    graph->vertexs.push_back(a);
    graph->vertexs.push_back(b);
    graph->vertexs.push_back(c);
    graph->vertexs.push_back(d);

    graph->bellmanFord(graph);

    system("pause");
    return 0;
}