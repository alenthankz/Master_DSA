#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int dat){
        left =right =NULL;
        data=dat;
    }
};

void tree2DLL(Node *root , Node**head , Node**tail){
    if(root==NULL)return ;
    tree2DLL(root->left,head,tail);
    if(*tail==NULL)*head=root;
    else{
        root->left=*tail;
        (*tail)->right=root;
    }
    *tail=root;
    tree2DLL(root->right,head,tail);
}
      

void printList(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->right;
    }
}


int main(){
    Node *root        = new Node(10);
    root->left        =  new Node(12);
    root->right       = new Node(15);
    root->left->left  = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);
 
    // Convert to DLL
    Node *head = NULL,*tail=NULL;
    tree2DLL(root, &head,&tail);
    printList(head);
    return 0;
}