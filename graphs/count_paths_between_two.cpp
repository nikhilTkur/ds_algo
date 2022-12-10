#include <bits/stdc++.h>

using namespace std;

class Graph
{
    public:
    Graph(int V);
    void addEdge(int v, int w);
    int count_paths(int src, int dest, int vertices);

    private:
    int mVertices;
    list<int> * adjList;

    void path_counter(int src, int dest, int & path_count, vector<bool>& visited);
};

Graph::Graph(int V)
{
    mVertices = V;
    adjList = new list<int> [V];
}

void Graph::addEdge(int v , int w)
{
    adjList[v].push_back(w);
}

int Graph::count_paths(int src, int dest, int vertices)
{
    int path_count = 0;
    vector<bool> visited(vertices, false);
    path_counter(src, dest, path_count, visited);
    return path_count;
}

void Graph::path_counter(int src, int dest, int & path_count, vector<bool>& visited)
{
     visited[src] = true;

    if (src == dest)
    {
    path_count++;
    }
    else
    {
        for (auto i : adjList[src])
        {
            if (!visited[i])
            {
                path_counter(i, dest, path_count, visited);
            }
        }
    }
    visited[src] = false;
}

// Driver code
int main()
{
    // Create a graph given in the above diagram - see link
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 4);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 1);
    g.addEdge(3, 2);
     
      // Function call
    cout << g.count_paths(0, 4, 5);
 
    return 0;
}