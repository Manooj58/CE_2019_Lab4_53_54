#include "LinkedList.h"

class vertex 
{
    public:
    int info;
    LinkedList list;
    vertex* next_vertex;
    
    vertex() 
    {
        this->next_vertex = nullptr;
    }
    vertex(int info) 
    {
        this->info = info;
        this->next_vertex = nullptr;
    }
};

class graph {
    private:
    vertex * vertex_head;
    bool directed;

    public:
    graph(int directed): vertex_head(nullptr), directed(directed) {};

    bool isEmpty(); //
    bool isDirected(); 
    void addVertex(vertex*); //
    void addEdge(vertex*, vertex*);  //
    void removeVertex(vertex*);  
    void removeEdge(vertex*, vertex*); //
    int numVertices();  
    int numEdge();     //
    int indegree(vertex*); 
    int outdegree(vertex*); // 
    int degree(vertex*); 
    void neighbours(vertex*); //
    bool isNeighbour(vertex* , vertex*); //
};