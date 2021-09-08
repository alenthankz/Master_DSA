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
void mergeAlternate(Node *tNode1,Node **head2){
    Node * tNode2=(*head2),*next1,*next2;
    while(tNode1 && tNode2){
        next1=tNode1->next;
        next2=tNode2->next;
        tNode1->next=tNode2;
        tNode2->next=next1;
        tNode1=next1;
        tNode2=next2;
    }
    (*head2)=tNode2;
}

void printL(Node *tNode){
    while(tNode!=NULL){
        cout<<tNode->data<<" ";
        tNode=tNode->next;
    }
}

int main(){
     Node *head1=new Node(1);head1->next=new Node(2);head1->next->next=new Node(3);
     Node  *head2=new Node(5);head2->next=new Node(10);head2->next->next=new Node(15);head2->next->next->next=new Node(20);
     mergeAlternate(head1,&head2);
     printL(head1);
}
