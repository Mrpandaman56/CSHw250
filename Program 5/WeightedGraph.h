#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include "Vertex.h"
#include <vector>

using namespace std;

class WeightedGraph
{
public:
    WeightedGraph(int size);
    void addVertex(Vertex* v);
    void addEdge(int from, int to, int weight);
    void DFS(Vertex* start);
    void BFS(Vertex* start);
    void findPath(Vertex* source, Vertex* destination);

private:
    static const int NULL_EDGE = 0;
    int m_numVertices;
    int m_maxVertices;
    vector<vector<int>> m_edges;
    vector<Vertex*> m_vertices;
    vector<bool> m_marks;

    int indexOf(Vertex* v);
    void resetMarks();
    void dfsFromIndex(int startIndex, int& runningCost);
    void bfsFromIndex(int startIndex, int& runningCost);
};

#endif
