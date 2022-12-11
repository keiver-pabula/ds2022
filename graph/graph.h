#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <cmath>
using namespace std;

struct Edge
{
  int start;//起始点
  int final;//终止点
  int weight=1;//权值默认值为1
  struct Edge *next;//下一边的链接指针
};

struct vertexnode
{
  int data;//顶点信息
  int value;//顶点值
  Edge *first;//边链头指针
};

struct Adjlist //图的邻接表
{
    vertexnode VexList[100];//邻接表
    int n,e;//图中当前的顶点个数与边数
};


class Graph
{
private:
  int vertex_nums;//顶点数
  int edge_nums;//边数
  vector<vertexnode> vertex;
  vector<Edge> edge;
  vector<vector<int> > adjmatrix;//邻接矩阵

public:
  void graph1()//有向图
{
  int n1,n2;
  cout<<"创建邻接矩阵\n顶点个数和边个数分别为:\t";
  cin>>n1>>n2;
  vertex_nums=n1;
  edge_nums=n2;
  for(int i=0;i<=vertex_nums;i++)//顶点表
        {
            vertexnode a;
            a.data=i;
            a.value=0;
            vertex.push_back(a);
        }

   for(int i=0;i<vertex_nums;i++)//邻接矩阵初始化
        {
            vector<int> mat(vertex_nums,0);//矩阵中每一行有vertex_nums个值都为0
            adjmatrix.push_back(mat);
        }

    int u,v,w;
     cout<<"逐条边输入，分别输入头，为，权重:\n";
    for(int i=0;i<edge_nums;i++)
        {
            cin>>u>>v>>w;
            Edge temp_edge;
            temp_edge.start=u;
            temp_edge.final=v;
            temp_edge.weight=w;
            edge.push_back(temp_edge);
            adjmatrix[u][v]=w;
        }
}
  void graph1_5()//无向图
{
  int n1,n2;
  cout<<"创建邻接矩阵\n顶点个数和边个数分别为:\t";
  cin>>n1>>n2;
  vertex_nums=n1;
  edge_nums=n2;
  for(int i=0;i<=vertex_nums;i++)//顶点表
        {
            vertexnode a;
            a.data=i;
            a.value=0;
            vertex.push_back(a);
        }

   for(int i=0;i<vertex_nums;i++)//邻接矩阵初始化
        {
            vector<int> mat(vertex_nums,0);//矩阵中每一行有vertex_nums个值都为0
            adjmatrix.push_back(mat);
        }

    int u,v,w;
     cout<<"逐条边输入，分别输入头，为，权重:\n";
    for(int i=0;i<edge_nums;i++)
        {
            cin>>u>>v>>w;
            Edge temp_edge;
            temp_edge.start=u;
            temp_edge.final=v;
            temp_edge.weight=w;
            edge.push_back(temp_edge);
            adjmatrix[u][v]=w;
	    adjmatrix[v][u]=w;
        }
}
    
    void graph2(Adjlist &G)
{
    int u,v,w;
    int n1,n2;
    cout<<"创建邻接表\n顶点个数和边个数分别为:\t";
    cin>>n1>>n2;
    vertex_nums=n1;
    edge_nums=n2;
    for(int i=0;i<vertex_nums;i++)//顶点表
        {
          G.VexList[i].data=i;
          G.VexList[i].first=NULL;

        }

    cout<<"逐条边输入，分别输入头，尾，权重:\n";
    for(int i=0;i<edge_nums;i++)
    {
        cin >> u >> v >> w;//逐条边输入
        Edge *p=new Edge;
	p->final=v;p->weight=w;
        p->next=G.VexList[u].first;
        G.VexList[u].first=p;
    }
}


void print_graph2(Adjlist G)//输出邻接表
{
    cout<<"邻接表为:\n";
    for(int i=0;i<vertex_nums;i++)
    {
        cout<<"v"<<G.VexList[i].data;
        Edge *p=G.VexList[i].first;
        while(p!=NULL)
        {
           cout<<" -> (v"<<p->final<<","<<p->weight<<")";
           p=p->next;
        }
    cout<<endl;
    }
}
void print_graph1()//输出邻接矩阵
    {
        cout<<endl;
        cout<<"邻接矩阵为:"<<endl;
        for(int i=0;i<vertex_nums;i++)
            cout<<"v"<<i<<" ";
        cout<<endl;

        for(int i=0;i<vertex_nums;i++)
        {
            cout<<"v"<<i<<"  ";
            for(int j=0;j<vertex_nums;j++)
            {
                cout<<adjmatrix[i][j]<<"  ";
            }
            cout<<endl;
        }
    }

    void listVertexes()
{
	cout<<"输出图的全部节点为:\n";
        for (int i=0;i<vertex_nums;i++)
        {
            cout<<"v"<<i<<" ";
        }
	cout<<endl;
    }

    void listEdges()
{
        cout<<"输出全部边"<<endl;
        cout<<endl;
        for(int i=0;i<edge_nums;i++)
        {
            cout<<"v"<<edge[i].start <<" v"<<edge[i].final<<" "<<edge[i].weight<<endl;
        }
	cout<<endl;
    }
};


#endif
