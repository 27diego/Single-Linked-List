#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};


class LinkedList{
private:
    int size = 0;
    Node* head;
    Node* tail;
    
public:
    int getSize();
    bool isEmpty();
    void addFirst(int data);
    void addLast(int data);
    int peakFirst();
    int peakLast();
    Node* removeFirst();
    Node* removeLast();
    Node* removeNodeByData(int data);
    Node* removeNodeByIndex(int index);
    int getByIndex(int index);
    bool contains(int data);
    void traverse();
};


int LinkedList::getSize(){
    return size;
}

bool LinkedList::isEmpty(){
    return size==0 ? true: false;
}

void LinkedList::addFirst(int data){
    Node* node = new Node(data, nullptr);
    if(isEmpty()){
        head = node;
        tail = node;
    }
    else{
        node->next = head;
        head = node;
    }
    size++;
}

void LinkedList::addLast(int data){
    Node* node = new Node(data, nullptr);
    if(isEmpty()){
        head = node;
        tail = node;
    }
    else{
        tail->next = node;
        tail = node;
    }
    
    size++;
}

int LinkedList::peakFirst(){
    return head->data;
}

int LinkedList::peakLast(){
    return tail->data;
}

Node* LinkedList::removeFirst(){
    if(isEmpty()){
        return nullptr;
    }
    
    Node* temp = head;
    head = temp->next;
    
    size--;
    
    return temp;
}

Node* LinkedList::removeLast(){
    if(isEmpty()){
        return nullptr;
    }
    
    Node* temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
    //exits when before to tail
   
    Node* free = temp->next;
    temp->next = nullptr;
    
    size--;
    
    return free;
}


Node* LinkedList::removeNodeByData(int data){
   //need 2 ptrs, 1 before target, 1 at target
    if(head->data == data){
        return removeFirst();
    }
    else if(tail->data == data){
        return removeLast();
    }
    auto temp = head;
    auto temp2 = head;
    
    while(temp->next->data != data){
        temp = temp->next;
    }
    //stops before item to be deleted
    temp2 = temp->next->next;
    temp->next = temp2;
    
    return temp->next;
}
Node* LinkedList::removeNodeByIndex(int index){
    if(getSize()<index){
        return nullptr;
    }
    
    auto temp = head;
    for(int x=0;x<index;x++){
        temp = temp->next;
    }
    
    if(temp->next == tail){
        temp->next = nullptr;
        auto free = tail;
        tail = temp;
        size--;
        return free;
    }
    
    //temp is at one before needs to be deleted
    auto temp2 = temp ->next ->next;
    auto free = temp->next;
    temp -> next = temp2;
    
    size--;
    return free;
}
int LinkedList::getByIndex(int index){
    auto temp = head;
    for(int x=0;x<=index;x++){
        temp = temp->next;
    }
    return temp->data;
}
bool LinkedList::contains(int data){
    int size = getSize();
    auto temp = head;
    for(int x=0;x<size;x++){
        if(temp->data==data){
            return true;
        }
        temp = temp->next;
    }
    
    return false;
}


void LinkedList::traverse(){
    cout<<"size: "<<getSize()<<endl;
    if(isEmpty()){
        cout<<"List is Empty"<<endl;
        return;
    }
    
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp -> data<<endl;
        temp = temp ->next;
    }
    
}
