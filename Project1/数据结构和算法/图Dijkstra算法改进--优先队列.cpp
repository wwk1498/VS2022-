/*
Dijkstra（迪克斯特拉）:单源最短路径算法(要求边的权值非负），时间复杂度：O((V + E)logV)，其中V--顶点数，E--边数，使用优先队列:

1.创建一个优先队列，放入所有顶点。

2.为每个顶点分配一个临时距离值:
       1.对于我们的初始顶点，设置其为零。
       2.对于所有其他顶点，将其设置为无穷大。

3.每次选择最小临时距离的顶点，作为新的当前顶点

4.对于当前顶点，遍历其所有的邻居，并更新它们的临时距离为更小:
      例如1--＞6的距离是14，而1--＞3-->6的距离是11。这时将距离更新为11，
      否则，将保留上次距离值
      同时，把邻居节点的前一个节点更新为当前节点

5.记录路径，并输出

6.当前顶点的邻居处理完成后，把它从队列中删除

*/
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<limits.h>//int inf=INT_MAX表示整数类型的最大值

using namespace std;

class Edge;
class Vertex {
public:
    int id;
    string name;//顶点名字
    int dist = INT_MAX;//距离
    Vertex* per;
    vector<Edge*> edges;//当前顶点连接的边
    Vertex(int _id, string _name) :id(_id), name(_name) {}
};

class Edge {
public:
    Vertex* last;//边的终点
    int weight;//权重
    Edge(Vertex* p, int _weight) :last(p), weight(_weight) {}
};

//比较器
class comparevertex {
public:
    bool operator()(Vertex* v1,Vertex*v2){
        return v1->dist > v2->dist;//从小到大
    }
};

class Graph {
public:
    vector<Vertex*> vertexs;//顶点集合
    stack<Vertex*>mystack;
    priority_queue<Vertex*, vector<Vertex*>, comparevertex> myqueue;//创建优先队列，从小到大

    

    //记录路径，并输出路径
    void lujin(Vertex* mindisk) {
        Vertex* tep = mindisk;
        while (tep->per != NULL) {
            mystack.push(tep->per);
            tep = tep->per;
        }

        while (!mystack.empty()) {
            Vertex* p = mystack.top();
            mystack.pop();
            cout << p->name << "-->";
        }
    }


    //Dijkstra算法
    void dijkstra(Graph* s) {

        //1.把所有顶点放入优先队列
        for (Vertex* r : s->vertexs) {
            myqueue.push(r);
        }
        myqueue.top()->dist = 0;//2.设置初始顶点的距离为0
        while (!myqueue.empty()) {
            //3.选取当前节点
            Vertex* mindisk = myqueue.top();
            //4.更新当前节点邻居的距离
            for (Edge* m : mindisk->edges) {
                int tepdisk = mindisk->dist + m->weight;
                if (tepdisk < m->last->dist) {
                    m->last->dist = tepdisk;
                    m->last->per = mindisk;
                }
            }
            //5.记录路径，并输出路径
            lujin(mindisk);
            //6.输出当前节点的距离
            cout << mindisk->name << ": " << mindisk->dist << endl;
            //7.移除当前节点
            myqueue.pop();

        }
    }

};


int main() {
    //创建顶点
    Vertex* a = new Vertex(0, "v1");
    Vertex* b = new Vertex(1, "v2");
    Vertex* c = new Vertex(2, "v3");
    Vertex* d = new Vertex(3, "v4");
    Vertex* e = new Vertex(4, "v5");
    Vertex* f = new Vertex(5, "v6");

    //创建边
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

    //创建图
    Graph* grap = new Graph;

    //给图添加顶点
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