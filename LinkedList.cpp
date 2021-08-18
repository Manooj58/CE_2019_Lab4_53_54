#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
Head = nullptr;
Tail = nullptr;
}
LinkedList::~LinkedList(){
delete Head;
delete Tail;
}

bool LinkedList::isEmpty()
{
    return Head == nullptr && Tail == nullptr;
}

void LinkedList::addToHead(int data)
{  
    Node *newNode = new Node();
    newNode->info = data;
    newNode->next = Head;
    Head = newNode;
    if (Tail == nullptr)
     {
         Tail = Head;
     }
     cout<<"Element is inserted at the head: "<<endl;
     cout<<data<<endl;
}

 void LinkedList::addToTail(int data){
    Node *newNode = new Node();
    newNode->info = data;
    newNode->next = nullptr;

if(Tail==nullptr){
    Tail=newNode;
    Head=Tail;
}
else{
Tail->next=newNode;
Tail = newNode;
}

}


void LinkedList::add(int data, Node *predecessor ){
    if(predecessor!=0){
    if(predecessor->info==Tail->info && predecessor->next==Tail->next){
        addToTail(data);    
    }
    Node *newnode=new Node(data,predecessor->next);
    predecessor->next=newnode;
    cout<<"Element is added. "<<endl;
}  
else{   
    cout<<"Predecessor Node doesn't exist."<<endl;
}
}

void LinkedList::removeFromHead()
{
    if (!isEmpty())
    {
        Node *nodeDelete=Head;

if (Head==Tail){
    Head=nullptr;
    Tail=nullptr;
    
}
else{
        Head = nodeDelete->next;        
}
    }  
    else 
    {
    cout<<"List is empty"<<endl;
    }
// Node *nodeDelete = new Node();
//     nodeDelete = Head;
//     Head = nodeDelete->next;
//     delete nodeDelete;
//     cout<<"Element is removed from Head "<<endl;
 }

 void LinkedList::removeFromTail(){
     if(!isEmpty()){

    Node *nodeDelete=Tail;
if (Head==Tail){
    Head=nullptr;
    Tail=nullptr;
    
}
else{ 
    Node *pred=Head;
    while (pred->next!=Tail){
        pred=pred->next;
    }
    Tail=pred;
    pred->next=nullptr;
    if (Head == nullptr)
        {
            Tail = nullptr;
        }

    }
     }
     else {
    cout<<" List is empty"<<endl;
    }
 }

//for stack and Queue
 void LinkedList::top(){
     if(!isEmpty()){
     cout<<"The Top most element: "<<endl;
     cout<<Head->info<<endl;
}
else{
    std::cout<<"List is empty"<<std::endl;
    }
 }

 //for stack and Queue
 void LinkedList::rear(){
     if(!isEmpty())
     {
     cout<<"The most rear element: "<<std::endl;
     cout<<Tail->info<<std::endl;
}
else{
    std::cout<<"list is empty"<<std::endl;
}

 }
  
void LinkedList::search(int data){
   if(!isEmpty()){
   Node *temp = Head;
   while(temp->next!=nullptr){
      if (temp->info==data){
         cout<<"Element is present in the list"<<endl;  
         break; 
          }  
    temp=temp->next;
}
if(temp->info!=data){
cout<<"Element is not present in the list"<<endl;  
}

}
else{
cout<<"the list is empty"<<endl;
}
 }

  void LinkedList::remove(int data){
if(!isEmpty()){
    if(Head->info==data){
        removeFromHead();

    }
    else if (Tail->info==data){
        removeFromTail();
    }
else{
Node *predecessor=Head;
Node *temp=Head->next;
while(temp->next!=Tail){
    if(temp->info==data){
        break;
    }
    else {
    predecessor=predecessor->next;
    temp=temp->next;
    }
}
if (temp->next!=nullptr){
    predecessor->next=temp->next;
    cout<<"Element is removed."<<endl;
}
else{
    cout<<"Element is not present."<<endl;
}
}
}
else {
cout<<"list is empty"<<endl;
}
  }

void LinkedList::traverse()
{

    if (isEmpty())
    {
        std::cout << "List is empty!!\n";
    }
    else
    {
        Node *temp = Head;

        while (temp != nullptr)
        {
            std::cout << temp->info << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

Node* LinkedList::retrieve(int data){

Node *temp=Head;
while(temp!=nullptr && temp->info!=data){
    temp=temp->next;
}
if(temp==nullptr){
    return nullptr;
}
else{
    return temp;
}
 }
