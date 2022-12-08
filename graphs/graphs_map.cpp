#include <iostream>
#include <map>
#include <list>
#include "graphs_map.h"

using namespace std;

void Graph::addEdge(int v , int w)
{
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v)
{
    visited[v] = true;
    cout << v << " ";

    for (auto i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visited[*i])
        {
            DFSUtil(*i);
        }
    }
}

void Graph::DFS()
{
    for (auto i : adj)
    {
        if (!visited[i.first])
        {
            DFSUtil(i.first);
        }
    }
}

// Driver's code
int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
 
    cout << "Following is Depth First Traversal \n";
       
      // Function call
    g.DFS();
 
    return 0;
}
