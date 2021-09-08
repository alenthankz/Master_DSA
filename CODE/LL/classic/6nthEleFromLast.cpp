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
void method2(Node * head,int n){
    Node * ptr1=head,*ptr2=head;
    int count =0;
    while(count<n && ptr1){
        count++;
        ptr1=ptr1->next;
    }
    if(!ptr1)return ;
    while(ptr1){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    cout<<ptr2->data;
}
void method1(Node* head,int n){
    Node * tNode=head;
    int size =0;
    while(tNode){
        size++;
        tNode=tNode->next;
    }
    if(n>size)return;
    tNode=head;
    for(int i =0;i<(size-n);i++){
        tNode=tNode->next;
    }
    cout<<tNode->data<<endl;
}

int main(){
    Node *head1=new Node(1);head1->next=new Node(2);head1->next->next=new Node(3);head1->next->next->next=new Node(4);
    method1(head1,2);
    method2(head1,2);
    return 0;
}