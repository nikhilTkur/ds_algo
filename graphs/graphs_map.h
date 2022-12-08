#include <iostream>
#include <map>
#include <list>


using namespace std;

class Graph
{
    void DFSUtil(int v);
public:
    map<int, bool> visited;
    map<int , list<int>> adj;

    void addEdge(int v , int w);

    void DFS();
};
