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

void push(Node**head,int val){
    Node *tNode = new Node(val);
    tNode->next=*head;
    (*head)=tNode;
}
void printList(Node*head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

void rotate(Node**head,int k){
    Node*tNode =*head,*temp=*head;
    int count=0;
    while(count<k-1){   //k-1 because next is the ouput of eachtime in loop.
        count++;
        tNode=tNode->next;
    }
    (*head)=tNode->next;
    tNode->next=NULL;
    tNode=*head;
    while(tNode->next){
        tNode=tNode->next;
    }
    tNode->next=temp;
}

int main(){
    Node*head=NULL;
    for(int i=60;i>0;i=i-10){
        push(&head,i);
    }
    // printList(head);
    rotate(&head,3);
    cout<<endl;
    printList(head);

}