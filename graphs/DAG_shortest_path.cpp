#include <bits/stdc++.h>

using namespace std;

class AdjListNode
{
    int v;
    int wt;

    public:
    AdjListNode(int _v , int _w) {v = _v ; wt = _w;}
    int getV() {return v;}
    int getWt() {return wt;}
};

class Graph
{
    int V;
    list <AdjListNode> * adj;

    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
    public:
    Graph(int V);

    void addEdge(int u, int v, int wt);

    void shortestPath(int s);
};


Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, int wt)
{
    AdjListNode node (v, wt);
    adj[u].push_back(node);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;

    for (auto i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visited[(*i).getV()])
        {
            topologicalSortUtil((*i).getV(), visited, Stack);
        }
    }
    Stack.push(v);
}

void Graph::shortestPath(int s)
{
    stack<int> Stack;
    int dist[V];

    bool *visited = new bool[V];
    
    for (int i = 0; i < V; i++)
        visited[i] = false;
    
    for (int i = 0; i < V ; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, visited, Stack);
        }
    }

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[s] = 0;

    while (!Stack.empty())
    {
        int u = Stack.top();
        Stack.pop();

        if (dist[u] != INT_MAX)
        {

            for (auto i = adj[u].begin(); i != adj[u].end(); i++)
            {
                if (dist[i->getV()] > dist[u] + i->getWt())
                {
                    dist[i->getV()] = dist[u] + i->getWt();
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        (dist[i] == INT_MAX)? cout << "INF ": cout << dist[i] << " ";
    }
}

int main()
{
    // Create a graph given in the above diagram.
    // Here vertex numbers are 0, 1, 2, 3, 4, 5 with
    // following mappings: 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
 
    int s = 1;
    cout << "Following are shortest distances from source " << s <<" n";
    g.shortestPath(s);
 
    return 0;
}