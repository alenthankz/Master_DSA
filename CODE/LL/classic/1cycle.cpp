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

void detectCycle(Node *head1){
    Node * slow =head1,*fast=head1;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head1;
            while(slow->next!=fast->next){
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=NULL;
            return;
        }
    }
}

int main(){
     Node *head1=new Node(1);head1->next=new Node(2);head1->next->next=new Node(3);head1->next->next->next=head1->next;
     detectCycle(head1);
     printL(head1);
}
