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

int maxPathSum(Node* root,int &res){
    if(root ==NULL)return 0;
    int lm =maxPathSum(root->left,res);
    int rm =maxPathSum(root->right,res);
    int max_here=0;
    int max_single=max(max(lm,rm)+root->data,root->data);
    max_here=max(lm+rm+root->data,max_single);
    res =max(res,max_here);
    return max_single;
}


int main(){
Node *root = new Node(10); 

    root->left        = new Node(2); 

    root->right       = new Node(10); 

    root->left->left  = new  Node(20); 

    root->left->right = new Node(1); 

    root->right->right = new Node(-25); 

    root->right->right->left   = new Node(3); 

    root->right->right->right  = new Node(4); 
    int res;
    maxPathSum(root,res);
    cout<<res<<endl;
    return 0;
}