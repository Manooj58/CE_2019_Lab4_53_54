#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    graph graph(false);
    vertex v1(1);
    vertex v2(2);
    vertex v3(3);
    vertex v4(4);
cout<<"Directed "<<graph.isDirected()<<endl;
    cout << "Graph Empty: " << graph.isEmpty() <<endl;
    cout << "number of Edges: " << graph.numEdge() <<endl;
    graph.addVertex(&v1);
    graph.addVertex(&v2);
    graph.addVertex(&v3);
    graph.addVertex(&v4);
    graph.addEdge(&v1, &v2);
    graph.addEdge(&v1, &v3);
    graph.addEdge(&v2, &v3);
    graph.addEdge(&v2, &v4);
    cout<<"indegree of 1: "<<graph.indegree(&v1)<<endl;
    cout<<"outdegree of 1: "<<graph.outdegree(&v1)<<endl;
    cout<<"degree of 1: "<<graph.degree(&v1)<<endl;

    cout << "Graph Empty: " << graph.isEmpty() <<endl;
    cout << "number of Edges: " << graph.numEdge() <<endl;

    graph.removeEdge(&v2, &v3);
    cout << "number of Edges: " << graph.numEdge() <<endl;
    cout << "number of vertices: "<<graph.numVertices()<<endl;
    graph.outdegree(&v2);

    graph.isNeighbour(&v1,&v2);
    graph.isNeighbour(&v3,&v4);

    graph.neighbours(&v1);
    graph.neighbours(&v2);

}