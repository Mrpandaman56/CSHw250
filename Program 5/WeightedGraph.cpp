#include "WeightedGraph.h"
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

WeightedGraph::WeightedGraph(int size)
{
    m_numVertices = 0;
    m_maxVertices = size;
    m_edges.assign(size, vector<int>(size, NULL_EDGE));
    m_vertices.assign(size, nullptr);
    m_marks.assign(size, false);
}

int WeightedGraph::indexOf(Vertex* v)
{
    for (int i = 0; i < m_numVertices; i++)
    {
        if (m_vertices[i] == v)
        {
            return i;
        }
    }
    return -1;
}

void WeightedGraph::resetMarks()
{
    for (int i = 0; i < m_maxVertices; i++)
    {
        m_marks[i] = false;
    }
}

void WeightedGraph::addVertex(Vertex* v)
{
    if (m_numVertices < m_maxVertices)
    {
        m_vertices[m_numVertices] = v;
        m_numVertices++;
    }
}

void WeightedGraph::addEdge(int from, int to, int weight)
{
    if (from >= 0 && from < m_numVertices && to >= 0 && to < m_numVertices)
    {
        m_edges[from][to] = weight;
    }
}

void WeightedGraph::dfsFromIndex(int startIndex, int& runningCost)
{
    m_marks[startIndex] = true;
    cout << m_vertices[startIndex]->getTitle() << " ";

    for (int j = 0; j < m_numVertices; j++)
    {
        if (m_edges[startIndex][j] != NULL_EDGE && !m_marks[j])
        {
            runningCost += m_edges[startIndex][j];
            dfsFromIndex(j, runningCost);
        }
    }
}

void WeightedGraph::DFS(Vertex* start)
{
    resetMarks();
    int idx = indexOf(start);
    if (idx == -1) return;

    int totalCost = 0;
    cout << "Order: ";
    dfsFromIndex(idx, totalCost);
    cout << endl;
    cout << "Total cost: " << totalCost << endl;
}

void WeightedGraph::bfsFromIndex(int startIndex, int& runningCost)
{
    queue<int> q;
    m_marks[startIndex] = true;
    q.push(startIndex);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << m_vertices[cur]->getTitle() << " ";

        for (int j = 0; j < m_numVertices; j++)
        {
            if (m_edges[cur][j] != NULL_EDGE && !m_marks[j])
            {
                m_marks[j] = true;
                runningCost += m_edges[cur][j];
                q.push(j);
            }
        }
    }
}

void WeightedGraph::BFS(Vertex* start)
{
    resetMarks();
    int idx = indexOf(start);
    if (idx == -1) return;

    int totalCost = 0;
    cout << "Order: ";
    bfsFromIndex(idx, totalCost);
    cout << endl;
    cout << "Total cost: " << totalCost << endl;
}

void WeightedGraph::findPath(Vertex* source, Vertex* destination)
{
    int s = indexOf(source);
    int d = indexOf(destination);

    if (s == -1 || d == -1)
    {
        cout << "Source or destination not in graph" << endl;
        return;
    }

    vector<int> parent(m_numVertices, -1);
    vector<bool> seen(m_numVertices, false);
    queue<int> q;

    seen[s] = true;
    q.push(s);

    while (!q.empty() && !seen[d])
    {
        int cur = q.front();
        q.pop();

        for (int j = 0; j < m_numVertices; j++)
        {
            if (m_edges[cur][j] != NULL_EDGE && !seen[j])
            {
                seen[j] = true;
                parent[j] = cur;
                q.push(j);
            }
        }
    }

    if (!seen[d])
    {
        cout << "No path from " << source->getTitle()
             << " to " << destination->getTitle() << endl;
        return;
    }

    vector<int> path;
    for (int v = d; v != -1; v = parent[v])
    {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    int cost = 0;
    for (size_t i = 1; i < path.size(); i++)
    {
        cost += m_edges[path[i - 1]][path[i]];
    }

    cout << "Path from " << source->getTitle()
         << " to " << destination->getTitle() << ": ";

    for (size_t i = 0; i < path.size(); i++)
    {
        cout << m_vertices[path[i]]->getTitle();
        if (i + 1 < path.size()) cout << " -> ";
    }

    cout << "  cost = " << cost << endl;
}
