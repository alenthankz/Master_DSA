#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * left,*right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

Node * lca(Node *root,int data1,int data2){
    if(root==NULL)return NULL;
    if(root->data==data1 || root->data==data2)return root;

    Node * left =lca(root->left,data1,data2);
    Node * right =lca(root->right,data1,data2);
    if(left && right)return root;
    else if(!left)return right;
    else left;
}

Node * lcaBST(Node * root,int data1,int data2){
    if(root==NULL)return NULL;
    if(root->data>data1 && root->data>data2){
        return lcaBST(root->left,data1,data2);
    }
    else if(root->data<data1 && root->data<data2){
        return lcaBST(root->right,data1,data2);
    }
    else return root;
}