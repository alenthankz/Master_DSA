#include<bits/stdc++.h>
using namespace std;
// push pop insert delete
class Node {
    public:
    Node* next;
    int data;
    Node(int dat){
        next=NULL;
        data=dat;
    }
};

void push(Node ** head,int dat){
    Node * tNode =new Node(dat);
    if((*head)==NULL){
        *head =tNode;
        return;
    }
    tNode->next=(*head);
    (*head) =tNode;
}

void insert(Node **head,int dat){
    Node *newNode =new Node(dat);
    if((*head)==NULL || (*head)->data<dat){
        newNode->next=(*head);
        (*head)=newNode;
        return;
    }
    Node * tNode =(*head);
    while(tNode && tNode->next->data>dat){
        tNode=tNode->next;
    }
    newNode->next=tNode->next;
    tNode->next=newNode;
}

void pop(Node **head){
    Node * tNode =(*head);
    (*head)=(*head)->next;
    free (tNode);
}

void delette(Node * head,int dat){
    if(head->data==dat){
        head->data=head->next->data;
        Node * tNode =head->next;
        head->next=head->next->next;
        free(tNode);
        return ;
    }
    Node * tNode =head;
    while(tNode && tNode->next->data!=dat){
        tNode=tNode->next;
    }
    Node * n =tNode->next;
    tNode->next=tNode->next->next;
    free(n);
}

void printL(Node *tNode){
    while(tNode!=NULL){
        cout<<tNode->data<<" ";
        tNode=tNode->next;
    }
}

int main(){
    Node *head =NULL;
    push(&head,4);
    push(&head,6);
    push(&head,7);
    push(&head,8);
    push(&head,10);
    insert(&head,9);
    insert(&head,11);
    pop(&head);
    delette(head,4);
    printL(head);
    return 0;   
}