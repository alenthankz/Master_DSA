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
int isLeftLeaf(Node * root){
    if (root == NULL)
       return 0;
    if(root->left == NULL && root->right == NULL)return 1;
    else return 0;
}


int sumOfLeftLeaves(Node * root){
    if(!root)return 0;
    int lval=0,rval=0;
    if(isLeftLeaf(root->left)) lval+= root->left->data; //just like in LL we are looking ahead next 
    else 
        lval+=sumOfLeftLeaves(root->left);
    rval =sumOfLeftLeaves(root->right);

    return lval+rval;
}

int main(){

    Node *root                = new Node(20);
    root->left                = new Node(9);
    root->right               = new Node(49);
    root->right->left         = new Node(23);
    root->right->right        = new Node(52);
    root->right->right->left  = new Node(50);
    root->left->left          = new Node(5);
    root->left->right         = new Node(12);
    root->left->right->right  = new Node(12);
    cout<<sumOfLeftLeaves(root);
    return 0;
}