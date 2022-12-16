#include <iostream>
#include <vector>
#include <string>
#include "graph.h"
using namespace std;

int main()
{
    clock_t t;
    Adjlist G;
    Graph graph;
    //graph.graph1();
    //graph.listVertexes();
    //graph.listEdges();
    //graph.print_graph1();
    //graph.graph2(G);
    //graph.listVertexes();
    // graph.listEdges();
    //graph.print_graph2(G);
    t = clock();
    {
    graph.init();//创建图
    if(graph.Bellman_Ford())//如果不是负权环才运行
        for(int i = 0 ;i <graph.vertex_nums; i++)
	  cout << i << "的值" << graph.dist[i] << endl;
    t=clock()-t;
    cout << "耗费的时间为： " << 1.0 * t / CLOCKS_PER_SEC << "秒" << endl;
    return 0;
    }
    
    
    system("pause");
    return 0;
}
