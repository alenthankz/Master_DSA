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

int compare(Node *head1,Node *head2){
    while(head1 && head2 && head1->data==head2->data){
        head1=head1->next;head2=head2->next;
    }
    if(!head1 && !head2)return 0;
    else if(!head1 )return -1;
    else if(!head2 )return 1;
    else{
        return (head1->data >head2->data)?1:-1;
    }
}

int main(){
    Node *head1=new Node(5);head1->next=new Node(6);head1->next->next=new Node(10);
    Node *head2=new Node(5);head2->next=new Node(6);head2->next->next=new Node(10);

    cout<<compare(head1,head2);
}