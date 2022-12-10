#include <bits/stdc++.h>

using namespace std;

struct Graph
{
    int V;
    set<int> * adjList;
};

Graph * createGraph(int V)
{
    Graph * graph = new Graph;
    graph->V = V;

    graph->adjList = new set<int> [V];

    return graph;
}

void addEdge(Graph * graph, int src, int dest)
{
    graph->adjList[src].insert(dest);
    graph->adjList[dest].insert(src);
    auto x = graph->adjList[src];
}

void printGraph(Graph * graph)
{
    for (int i = 0; i < graph->V; i++)
    {
        set<int> lst = graph->adjList[i];
        cout << "Adjacency list of vertex " << i << endl;

        for (auto i = lst.begin(); i != lst.end(); i++)
        {
            cout << *i << " ";
        }
        cout << endl;
    }
}

void searchEdge(Graph * graph , int src, int dest)
{
    auto it = graph->adjList[src].find(dest);

    if (it == graph->adjList[src].end())
    {
        cout << "No edge here "<< endl;
    }
    else
    {
        cout << "Edge exists here "<< endl;
    }
}

// Driver code
int main()
{
    // Create the graph given in the above figure
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    // Print the adjacency list representation of
    // the above graph
    printGraph(graph);
 
    // Search the given edge in the graph
    searchEdge(graph, 2, 1);
    searchEdge(graph, 0, 3);
 
    return 0;
}