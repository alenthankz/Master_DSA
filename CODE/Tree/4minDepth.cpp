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
// please take time to understand this problem , why is it different from height problem
// what differences came because MAX() changed to MIN()
// here even if one side is null , it is considered as Leaf without extra lines;
int minDepth(Node * root){
    if(root==NULL)return 0;
    if(!root->left && !root->right)return 1; //extra line 1

    int ld = INT_MAX,rd = INT_MAX;//extra line 2
    if(root->left)                //extra line 3
    ld = minDepth(root->left);
    if(root->right)               //extra line 4
    rd = minDepth(root->right);

    return min(ld,rd)+1;
}
// another approach is to use bfs and i highly suggest it as it is amin problem

int main(){
     Node *root     = new Node(1); 

    root->left     = new Node(2); 

    root->right     = new Node(3); 

    root->left->left = new Node(4); 

    root->left->right = new Node(5); 

    cout <<"The minimum depth of binary tree is : "<< minDepth(root); 

    return 0; 
}