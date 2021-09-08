#include<bits/stdc++.h>
using namespace std;
// stack is just normal push operation with a top as head

class Node {
    public:
    Node* next;
    int data;
    Node(int dat){
        next=NULL;
        data=dat;
    }
};

class Stack{
    public:
    Node * top;
    Stack(){
        this->top=NULL;}
    void push(int dat){
        Node *n =new Node(dat);
        n->next=top;
        top=n; 
    }
    bool isEmpty(){
        return top==NULL?1:0;
    }
    void pop(){
        top=top->next;
    }
    int peek(){
        return top->data;
    }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.peek();
    s.pop();
    cout<<s.peek(); 
    return 0;
}