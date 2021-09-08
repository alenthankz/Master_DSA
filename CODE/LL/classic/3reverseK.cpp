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

void printL(Node *tNode){
    while(tNode!=NULL){
        cout<<tNode->data<<" ";
        tNode=tNode->next;
    }
}


Node * reverse(Node * head,int k){
    Node* prev=NULL,*curr=head,*next;
    int count=0;
    while(count<k && curr){
        next =curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next)
        head->next = reverse(next,k);
    return prev;
}



int main(){
    Node *head1=new Node(1);head1->next=new Node(2);head1->next->next=new Node(3);head1->next->next->next=new Node(4);head1->next->next->next->next=new Node(5);head1->next->next->next->next->next=new Node(6);
    Node * head =reverse(head1,2);
    printL(head);
    return 0;
}