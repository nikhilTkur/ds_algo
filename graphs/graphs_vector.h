#include <vector>
#include <list>
#include <iostream>

using namespace std;

class VectorGraph
{
    int V;
    vector<list<int>> adj;
public:
    VectorGraph(int V);

    void addEdge(int v, int w);

    void BFS(int s);
};
