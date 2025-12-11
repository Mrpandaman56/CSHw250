#include <iostream>
#include "Vertex.h"
#include "WeightedGraph.h"
using namespace std;

int main()
{
    WeightedGraph g(10);

    Vertex* A = new Vertex("A");
    Vertex* B = new Vertex("B");
    Vertex* C = new Vertex("C");
    Vertex* D = new Vertex("D");
    Vertex* E = new Vertex("E");

    g.addVertex(A);
    g.addVertex(B);
    g.addVertex(C);
    g.addVertex(D);
    g.addVertex(E);

    g.addEdge(1, 0, 10);
    g.addEdge(0, 2, 12);
    g.addEdge(2, 1, 20);
    g.addEdge(0, 3, 60);
    g.addEdge(2, 3, 32);
    g.addEdge(4, 0, 7);

    cout << "DFS starting at E" << endl;
    g.DFS(E);
    cout << endl << endl;

    cout << "BFS starting at E" << endl;
    g.BFS(E);
    cout << endl << endl;

    cout << "Path tests" << endl;
    g.findPath(E, D);
    g.findPath(B, E);

    return 0;
}
