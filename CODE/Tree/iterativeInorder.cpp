#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node *left,*right;
    int val;
    Node(int dat){
        left=NULL;right=NULL;
        val=dat;
    }
};

void iterativeInorder(Node* root){
    stack<Node*>stk;
    while(!stk.empty() || root){
        while(root){
            stk.push(root);
            root=root->left;
        }
        root = stk.top();stk.top();
        cout<<root->val<<" ";
        root=root->right;
    }
}

int main(){
    Node *root = new Node(1);
    root->left =new Node(2);
    root->right =new Node(3);
    root->left->right=new Node(5);
    root->left->left=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    iterativeInorder(root);cout<<endl;

   
    return 0;
}