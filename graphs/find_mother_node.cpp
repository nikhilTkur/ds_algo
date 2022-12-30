#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    list<int> * adjList;

    void DFSUtil(int v, vector<bool> & visited);

    public:
    Graph(int V);
    void addEdge(int v , int w);
    int findMother();
};

Graph::Graph(int V)
{
    this->V = V;
    adjList = new list<int> [V];
}

void Graph::DFSUtil(int v , vector<bool> & visited)
{
    visited[v]  = true;

    for (auto i = adjList[v].begin(); i != adjList[v].end(); i++)
    {
        if (!visited[*i])
        {
            DFSUtil(*i, visited);
        }
    }
}

void Graph::addEdge(int v, int w)
{
    adjList[v].push_back(w);
}

int Graph::findMother()
{
    vector<bool> visited (V , false);

    int maybe_mother = 0;

    for (int i = 0; i < V ; i++)
    {
        if (!visited[i])
        {
            DFSUtil(i, visited);
            maybe_mother = i;
        }
    }

    fill(visited.begin(), visited.end(), false);

    DFSUtil(maybe_mother, visited);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i]) return -1;
    }
    return maybe_mother;
}

// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);
 
      // Function call
    cout << "A mother vertex is " << g.findMother();
 
    return 0;
}