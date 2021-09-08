#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node * left,*right;
    Node(int val){
        data=val;left=right=NULL;
    }
};

void inorder(Node * root ,vector<int>&arr){
    if(root==NULL)return ;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

void bTToBST(Node * root , vector<int>&sortedArr , int * idxPtr){
    if(root==NULL)return ;
    bTToBST(root->left,sortedArr,idxPtr);
    root->data = sortedArr[*idxPtr]; *idxPtr=*idxPtr+1;
    bTToBST(root->right,sortedArr,idxPtr);
}