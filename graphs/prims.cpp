#include <bits/stdc++.h>

using namespace std;

#define V 5

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int i = 0 ; i < V ; i++)
    {
        if (mstSet[i] == false && key[i] < min)
        {
            min = key[i] , min_index = i;
        }

    }
    return min_index;
}

void printMst(int parent[] , int graph[V][V])
{
    cout << "Edge \tWeight\n";

    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
            << graph[i][parent[i]] << " \n";
}

void primMst(int graph[V][V])
{
    int parent [V];

    int key[V];

    bool mstSet[V];

    for (int i = 0 ; i < V ; i++)
    {
        key[i] = INT_MAX , mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int c = 0 ; c < V - 1; c++)
    {
        int u = minKey(key , mstSet);

        mstSet[u] = true;

        for (int v = 0 ; v < V ; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }

    }

    printMst(parent , graph);
}

int main()
{
    /* Let us create the following graph
        2 3
    (0)--(1)--(2)
    | / \ |
    6| 8/ \5 |7
    | / \ |
    (3)-------(4)
            9     */
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    // Print the solution
    primMst(graph);
 
    return 0;
}