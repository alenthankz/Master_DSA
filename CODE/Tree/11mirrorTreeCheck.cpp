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


bool isMirror(Node * root1, Node*root2 ){
    if(!root1 && !root2)return true; 
    if(!root1 || !root2)return false;
    
    return (root1->data==root2->data) &&
           (isMirror(root1->left,root2->right))&&
           (isMirror(root1->right,root2->left));
}

// to check a tree is symetric , pass root1& root2 as root