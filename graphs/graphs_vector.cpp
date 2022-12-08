#include <iostream>
#include <vector>
#include <list>
#include "graphs_vector.h"

using namespace std;

VectorGraph::VectorGraph(int V)
{
    this->V = V;
    adj.resize(V);
}

void VectorGraph::addEdge(int v , int w)
{
    adj[v].push_back(w);
}

void VectorGraph::BFS(int s)
{
    vector<bool> visited;
    visited.resize(V, false);

    list<int> queue;

    visited[s] = true;

    queue.push_back(s);

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (auto i : adj[s])
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    VectorGraph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}
