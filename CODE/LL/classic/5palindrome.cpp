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

bool method1(Node * head){
    Node * slow=head,*fast=head;
    int count=0;
    while(fast && fast->next){
        count++;
        fast=fast->next->next;
        slow=slow->next;
    }

    Node *prev =NULL,*curr=head,*next;
    while(curr!=slow){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    Node * ptr1=prev;
    
    Node *ptr2=(count%2==0)?slow:slow->next;
    cout<<slow->data<<endl;
    while(ptr1 && ptr2){
        if(ptr1->data!=ptr2->data)return false;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return true;
}

int main(){
    Node *head1=new Node(1);head1->next=new Node(2);head1->next->next=new Node(3);head1->next->next->next=new Node(2);;head1->next->next->next->next=new Node(1);
    printL(head1);cout<<endl;
    cout<<method1(head1);
    // method2(head1,2);
    return 0;
}