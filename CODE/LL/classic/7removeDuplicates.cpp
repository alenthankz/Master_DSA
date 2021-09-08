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

void removeDuplicates(Node *head){
    Node * ptr1=head,*ptr2=head;
    while(ptr1){
        if(ptr1->next){
            if(ptr1->data!=ptr1->next->data ){
                ptr2->data=ptr1->data;
                ptr2=ptr2->next;
            }
        }else{
            ptr2->data=ptr1->data;
            ptr2->next=NULL;
        }
         ptr1=ptr1->next;
    }
}

int main(){
    Node *head1=new Node(1);head1->next=new Node(2);head1->next->next=new Node(4);head1->next->next->next=new Node(4);head1->next->next->next->next=new Node(4);head1->next->next->next->next->next=new Node(6);
    printL(head1);cout<<endl;
    removeDuplicates(head1);
    printL(head1);
}