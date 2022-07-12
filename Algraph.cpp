#include <iostream>
#include <string>
#include <queue>
using namespace std;
const int MaxSize = 10;
const int MaxWeight = 1000;
const int MaxEdge = 100;
bool visited[MaxSize] = {false};


struct Edge{
    int from, to;
    int weight;
};


class Graph
{
public:
    Graph(string a[], int n, int e);
    ~Graph(){}
    void DFSTraverse();
    void DFS(int v);
    void BFSTraverse();
    void BFS(int v);
    void BFS_minDistance(int v);
    void Prim(int v);
    void Kruskal();
    void Dijkstra(int v);
    void Floyd();
private:
    string vertex[MaxSize];
    int arc[MaxSize][MaxSize];
    int vertexNum, arcNum;
    Edge edge[MaxEdge];
};


// 初始化图的邻接矩阵
Graph::Graph(string a[], int n, int e)
{
    int weight; // 每个边的权重
    vertexNum = n;
    arcNum = e;
    for(int i = 0; i < vertexNum; i++)
        vertex[i] = a[i];
    for(int i = 0; i < vertexNum; i++)  // 初始化邻接矩阵
        for(int j = 0; j < vertexNum; j++)
        {
            if(i == j)
                arc[i][j] = 0;
            else
                arc[i][j] = MaxWeight;
        }

    for(int k = 0; k < arcNum; k++)
    {
        int i, j;
        cin >> i >> j >> weight;
        edge[k].from = i - 1;
        edge[k].to = j - 1;
        edge[k].weight = weight;
        arc[i - 1][j - 1] = weight;
    }
}


void Graph::BFS(int v)
{
    queue<int> Q;
    cout << vertex[v] << " ";
    Q.push(v);
    visited[v] = true;
    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        for(int j = 0; j < vertexNum; j++)
            if(arc[v][j] != MaxWeight && arc[v][j] != 0 && visited[j] != true)
            {
                cout << vertex[j] << " ";
                visited[j] = true;
                Q.push(j);
            }
    }
}

void Graph::BFSTraverse()
{
    for(int i = 0; i < vertexNum; i++)
        visited[i] = false;
    for(int i = 0; i < vertexNum; i++)
        if(!visited[i])
            this->BFS(i);
}

void Graph::BFS_minDistance(int v)
{
    int *d = new int[MaxSize];
    int *path = new int[MaxSize];
    for(int i = 0; i < vertexNum; i++)
    {
        visited[i] = false;
        d[i] = MaxEdge;
        path[i] = -1;
    }
    d[v] = 0;
    visited[v] = true;
    queue<int> Q;
    Q.push(v);
    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        for(int j = 0; j < vertexNum; j++)
        {
            if(arc[v][j] != MaxWeight && arc[v][j] != 0 && visited[j] == false)
            {
                d[j] = d[v] + 1;
                cout << "d[" << vertex[v] << "]到d[" << vertex[j] << "]的距离为:" << d[j] << endl;
                path[j] = v;
                cout << "path[" << vertex[v] << "]的下一个点是path[" << vertex[j] << "]" << endl;
                visited[j] = true;
                Q.push(j);
            }
        }
    }

}


void Graph::DFS(int v)
{
    cout << vertex[v];
    visited[v] = true;
    for(int i = 0; i < vertexNum; i++)
        if(arc[v][i] != 0  && arc[v][i] != MaxWeight && visited[v] == false)
            DFS(i);
}

void Graph::DFSTraverse()
{
    for(int i = 0; i < vertexNum; i++)
        visited[i] = false;
    for(int i = 0; i < vertexNum; i++)
        if(!visited[i])
            this->DFS(i);
}

int MinEdge(int lowcost[MaxSize], int vertexNum)
{
    int min = MaxWeight;
    int j = 0;
    for(int i = 0; i < vertexNum; i++)
    {
        if((lowcost[i] < min) && (lowcost[i] != 0))
        {
            min = lowcost[i];
            j = i;
        }
    }
    return j;
}

void Graph::Prim(int v)
{
    int adjvex[MaxSize], lowcost[MaxSize];
    for(int i = 0; i < vertexNum; i++)
    {
        lowcost[i] = arc[v][i];
        adjvex[i] = v;
    }
    lowcost[v] = 0;
    for(int k = 1; k < vertexNum; k++)
    {
        int j = MinEdge(lowcost, vertexNum);
        cout << "{" << vertex[j] << ", " << vertex[adjvex[j]] << "}" << lowcost[j] << endl;
        lowcost[j] = 0;
        for(int i = 0; i < vertexNum; i++)
        {
            if(arc[i][j] < lowcost[i])
            {
                lowcost[j] = arc[i][j];
                adjvex[i] = j;
            }
        }
    }

}

int FindRoot(int parent[], int v)
{
    int t = v;
    while(parent[t] > -1)
        t = parent[t];
    return t;
}

void Graph::Kruskal()
{
    int parent[6];
    for(int i = 0; i < vertexNum; i++)
        parent[i] = -1;
    for(int i = 0; i < arcNum - 1; i++)
        for(int j = 0; j < arcNum - 1 - i; j++)
            if(edge[j].weight > edge[j + 1].weight)
                swap(edge[j], edge[j+1]);
    for(int num = 0, i = 0; num < vertexNum - 1; i++)
    {
        int vex1 = FindRoot(parent, edge[i].from);
        int vex2 = FindRoot(parent, edge[i].to);
        if(vex1 != vex2)
        {
            cout << "{" << vertex[edge[i].from] << ", " << vertex[edge[i].to] << "}" << endl;
            parent[vex2] = vex1;
            num++;
        }
    }
}

void Graph::Dijkstra(int v)
{
    int* dist = new int[MaxSize];
    string* path = new string[MaxSize];
    for(int i = 0; i < vertexNum; i++)
    {
        visited[i] = false;
        dist[i] = arc[v][i];
        if(dist[i] != MaxWeight)
            path[i] = vertex[v] + vertex[i];
        else
            path[i] = "";
    }
    for(int num = 1; num < vertexNum; num++)
    {
        int k = MinEdge(dist, vertexNum);
        cout << path[k] << dist[k] << endl;
        for(int i = 0; i < vertexNum; i++)
            if(dist[i] > dist[k] + arc[k][i])
            {
                dist[i] = dist[k] + arc[k][i];
                path[i] = path[k] + vertex[i];
            }
        dist[k] = 0;
    }
}

void Graph::Floyd()
{
    int dist[MaxSize][MaxSize];
    string path[MaxSize][MaxSize];
    for(int i = 0; i < vertexNum; i++)
        for(int j = 0; j < vertexNum; j++)
        {
            dist[i][j] = arc[i][j];
            if(dist[i][j] != MaxWeight)
                path[i][j] = vertex[i] + vertex[j];
            else
                path[i][j] = "";
        }
    
    for(int k = 0; k < vertexNum; k++)
        for(int i = 0; i < vertexNum; i++)
            for(int j = 0; j < vertexNum; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[i][k] + path[k][j];
                }
            }
    for(int i = 0; i < vertexNum; i++)
    {
        for(int j = 0; j < vertexNum; j++)
        {
            cout << dist[i][j] << "\t";
        }
        cout << endl;
    }

    for(int i = 0; i < vertexNum; i++)
    {
        for(int j = 0; j < vertexNum; j++)
        {
            cout << path[i][j] << "\t";
        }
        cout << endl;
    }
}

int main(void)
{
    string ch[6] = {"A", "B", "C", "D", "E", "F"};
    Graph g(ch, 6, 8);
    g.BFSTraverse();
    g.Prim(0);
    g.Kruskal();
    g.BFS_minDistance(0);
    g.Dijkstra(0);
    g.Floyd();
    system("pause");
    return 0;
}