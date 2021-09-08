// its head as front and an extra pointer for back
// very very similar to orginal queue only.
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    Node* next;
    int data;
    Node(int dat){
        next=NULL;
        data=dat;
    }
};

class Queue{
    public:
    Node * front,*rear;
    Queue(){
        this->rear=NULL;
        this->front=NULL;
    }
    void Enqueue(int dat){
        Node *n =new Node(dat);
        if(rear==NULL){
            front =rear=n;
            return;
        }
        rear->next=n;
        rear=n; 
    }
    void dequeue(){
        front =front->next;
        if(!front)rear=NULL;
    }
    int peek(){
        return front->data;
    }
};
int main(){
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    return 0;
}