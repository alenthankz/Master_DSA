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

bool isFull(Node * root){
    if(root==NULL) return true;
    if(root->left ==NULL && root->right==NULL)return true;
    if(root->left && root->right)
    return isFull(root->left )&& isFull(root->right);
    else return false;
}

bool isBalanced(Node * root,int * height){
    if(root==NULL){
        *height =0;
        return true;
    }
    int lh,rh;
    bool l =isBalanced(root->left,&lh);
    bool r =isBalanced(root->right,&rh);
    *height=max(lh,rh)+1;
    if(abs(lh-rh)>=2)return false;
    else return l&&r;
}

// count number of leaf nodes

int count(Node * root){
    if(root==NULL)return 0;
    if(root->left ==NULL && root->right==NULL)return 1;
    return count(root->left) + count(root->right);
}

int main(){
    Node * root=NULL;
    return 0;
}