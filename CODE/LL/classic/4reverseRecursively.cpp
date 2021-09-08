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

Node* revRecur(Node* tnode , Node**head){
    if(!tnode)return NULL;
    if(!tnode->next){*head=tnode;return tnode;}
    Node* nodeHere = revRecur(tnode->next,head);
    nodeHere->next=tnode;tnode->next=NULL;
    return tnode;
}