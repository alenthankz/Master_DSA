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



Node * mergge(Node * a,Node *b){
    Node * result =NULL;
    if(a==NULL)return b;
    if(b==NULL)return a;

    if(a->data<=b->data){
        result=a;
        result->next=mergge(a->next,b);
    }else{
        result=b;
        result->next=mergge(a,b->next);
    }
    return result;
}

void findMid(Node * head,Node ** a,Node **b){
    Node * slow=head;
    Node * fast=head->next;
    while(fast){
        fast=fast->next;
            while(fast ){
            fast=fast->next;
            slow=slow->next;
        }
    }
    (*a)=head;
    (*b)=slow->next;
    slow->next=NULL;
}
// void FrontBackSplit(Node* source,Node** frontRef, Node** backRef) 
// { 
//     Node* fast; 
//     Node* slow; 
//     slow = source; 
//     fast = source->next;
//     while (fast != NULL) { 
//         fast = fast->next; 
//         if (fast != NULL) { 
//             slow = slow->next; 
//             fast = fast->next; 
//         } 
//     } 
//     *frontRef = source; 
//     *backRef = slow->next; 
//     slow->next = NULL; 
// } 

void mergeSort(Node ** head){
    Node * front,*back;
    if((*head)==NULL | (*head)->next==NULL) return;
    findMid(*head,&front,&back);
    mergeSort(&front);
    mergeSort(&back);
    *head=mergge(front,back);
}

int main(){
     Node *head=new Node(5);head->next=new Node(2);head->next->next=new Node(4);head->next->next->next=new Node(3);
     mergeSort(&head);
     printL(head);
}