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

bool isidentical(Node * root1,Node * root2){
    if(root1==NULL && root2==NULL)return true;
    if(root1 ==NULL || root2==NULL)return false;
    return (root1->data ==root2->data) && isidentical(root1->left,root2->left) &&isidentical(root1->right,root2->right);
}

bool isSubTree(Node * T,Node * S){
    if(S==NULL)return true;
    if(T==NULL)return false;
    if(isidentical(T,S))return true;
    return isSubTree(T->left,S) ||isSubTree(T->right,S);
}