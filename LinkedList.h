#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class Node
{
public:
    int info;
    Node *next;

    Node() : next(nullptr) {};

    Node(int i, Node *n): info(i), next(n){};
    
    ~Node(){
        delete next;
    }
};

class LinkedList
{
public:
Node *Head;
Node *Tail;

LinkedList();
~LinkedList();
bool isEmpty();
void addToHead(int data);
void addToTail(int data);
void add(int data, Node *predecessor );
void removeFromHead ();
void removeFromTail ();
void remove(int data);
void top();
void rear();
void search(int data);
Node* retrieve(int data);
void traverse();
    
};

#endif