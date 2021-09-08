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

int sizeL(Node * head){
    int count =0;
    while(head){
        count ++;
        head=head->next;
    }
    return count;
}

void swapp(Node ** head1,Node **head2){
    Node * temp =(*head1);
    (*head1)=(*head2);
    (*head2)=temp;
}

int addEqual(Node * tNode1,Node * tNode2,Node ** res){
    if(!tNode2)return 0;
    int carry =addEqual(tNode1->next,tNode2->next,res);
    int sum =tNode2->data+tNode1->data;
    carry=sum/10;
    sum=sum%10;
    Node * n =new Node(sum);
    n->next=(*res);
    (*res)=n;
    return carry;
}

int addNeq(Node *head1,Node * tNode1,Node ** res,int carry){
    if(head1==tNode1)return carry;
    carry =addNeq(head1->next,tNode1,res,carry);
    int sum =head1->data+carry;
    carry =sum/10;
    sum =sum%10;
    Node * n =new Node (sum);
    n->next=(*res);
    (*res)=n;
    return carry;
}

Node * add(Node * head1,Node *head2){
    Node * res=NULL;
    int s1 =sizeL(head1);
    int s2 =sizeL(head2);
    if(s1==s2){
        addEqual(head1,head2,&res);
        return res;
    }
    if(s1<s2)swapp(&head1,&head2);
    int diff =abs(s2-s1);
    Node * curr=head1;
    for(int i=0;i<diff;i++){
        curr=curr->next;
    }
    int carry =addEqual(curr,head2,&res);
    carry=addNeq(head1,curr,&res,carry);
    if(carry){
        Node * n =new Node(1);
        n->next=(res);
        (res)=n;
    }
    return res;
}


int main(){
    Node * head1=new Node(1);head1->next=new Node(2);head1->next->next=new Node(3);
    Node * head2=new Node(4);head2->next=new Node(5);
    printL(head1);cout<<endl;
    cout<<"  ";printL(head2);cout<<endl;
    printL(add(head1,head2));
}