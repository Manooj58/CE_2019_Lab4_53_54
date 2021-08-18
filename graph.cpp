#include <iostream>
#include "LinkedList.h"
#include "graph.h"
using namespace std;

bool graph::isEmpty() 
{
    if (vertex_head == nullptr) 
    {
    return true;
    }
    else 
    {
    return false;
    }
}
bool graph::isDirected(){
    return directed;
}

void graph::addVertex(vertex* v) 
{
    v->next_vertex = vertex_head;
    vertex_head = v;
}


void graph::addEdge(vertex* v1, vertex* v2) 
{
    if (!directed) 
    {
        v1->list.addToTail(v2->info);
        v2->list.addToTail(v1->info);
    }
    else 
    {
        v1->list.addToTail(v2->info);
    }
    cout << "edge has been added" << endl;
}

void graph::removeEdge(vertex* v1, vertex* v2) 
{
    if (!directed) 
    {
        Node *node1 = v1->list.retrieve(v2->info);
        Node *node2 = v2->list.retrieve(v1->info);
        v1->list.remove(node1->info);
        v2->list.remove(node2->info);
        cout << "Edge Removed" << endl;
    }
    else 
    {
        Node *node = v1->list.retrieve(v2->info);
        v1->list.remove(node->info);
        cout << "Edge Removed" << endl;
    }
}
int graph::numVertices() 
{
    int count = 0;
    vertex* v = new vertex();
    v = vertex_head;
    while (v != nullptr) 
    {
        v=v->next_vertex;
        count++;
}
return count;
}
int graph::numEdge() 
{
    int edges = 0;
    vertex* v = new vertex();
    v = vertex_head;
    while (v != nullptr) 
    {
        Node* node = new Node();
        node = v->list.Head;
        int edge_in_v = 0;
        while (node != nullptr) 
        {
            edge_in_v++;
            node = node->next;
        }
        edges += edge_in_v;
        v = v->next_vertex;
    }

    if(!directed) 
    {
    return edges/2;
    }
    else 
    {
    return edges;
    }
}

void graph::neighbours (vertex* v) {
    cout << "neighbours of " << v->info << " are:" <<endl;
    Node* n = new Node();
    n = v->list.Head;
    while (n != nullptr) {
        cout << n->info << "\t";
        n = n->next;
    }
    cout << endl;
}

int graph::outdegree(vertex* v) 
{
      
        int outdegree = 0;
        Node* n = new Node();
        n = v->list.Head;

        while (n != nullptr)
        {
            outdegree++;
            n = n->next;
        }
        return outdegree;
    }
   


int graph::indegree(vertex* v) 
{
    int indegree = 0;
    vertex* vl = new vertex();
    vl = vertex_head;
    while (vl != nullptr) 
    {
         if(vl->info==v->info){
                            vl=vl->next_vertex;

                continue;
            }
        Node* node = new Node();
        node = vl->list.Head;
        while (node != nullptr) 
        {
            if(node->info==v->info){
                indegree++;
            }
            node = node->next;
        }
        vl = vl->next_vertex;
    }
return indegree;
}
int graph::degree(vertex* v){
    
        int outdegree = 0;
        Node* n = new Node();
        n = v->list.Head;

        while (n != nullptr)
        {
            outdegree++;
            n = n->next;
        }

    int indegree = 0;
    vertex* vl = new vertex();
    vl = vertex_head;
    while (vl != nullptr) 
    {
         if(vl->info==v->info){
                            vl=vl->next_vertex;

                continue;
            }
        Node* node = new Node();
        node = vl->list.Head;
        while (node != nullptr) 
        {
            if(node->info==v->info){
                indegree++;
            }
            node = node->next;
        }
        vl = vl->next_vertex;
    }
    if(isDirected()){
    return indegree + outdegree;
    }
    else{
        return outdegree;
    }
} 

bool graph::isNeighbour(vertex* v1, vertex* v2) 
{
    bool neighbour = false;
    Node* n = new Node();
    n = v1->list.Head;
    while (n != nullptr) 
    {
        if(n->info == v2->info) 
        {
            neighbour = true;
            break;
        }
        n = n->next;
    }
    if (neighbour) {
        cout << v1->info << " and " << v2->info << " are neighbours." <<endl;
    }
    else {
        cout <<v1->info << " and " << v2->info<< "are not neighbours" <<endl;
    }
    return neighbour;
}


