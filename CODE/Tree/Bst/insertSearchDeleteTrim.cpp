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

Node* search(Node* root, int val){
    if(root==NULL|| root->data==val){
        return root;
    }
    if(root->data<val){
        return search(root->right,val);
    }
    return search(root->left,val);
}

Node* insert(Node*root,int val){
    if(!root) return new Node(val);
    if(val>root->data)
       root->right = insert(root->right,val);
    else
       root->left = insert(root->left,val);
    return root;
}

Node * delette(Node* root,int val){
    if(!root)return NULL;
    if(val>root->data) root->right = delette(root->right,val);
    else if(val<root->data) root->left = delette(root->left,val);
    else{
        if(!root->left && !root->right)return NULL;
        else if(!root->left) return root->right;
        else if(!root->right) return root->left;
        else {
            Node * parent =root;
            Node * rt = root->right;
            while(rt && rt->left){parent =rt; rt = rt->left;}
            if(parent !=root) parent->left = rt->right;
            else parent->right = rt->right;

            root->data = rt->data;
            return root;
        }
   }
}

//trim
Node* deleteRange(Node*root,int min ,int max){
    if(!root)return NULL;
    
    root->left = deleteRange(root->left,min,max);
    root->right = deleteRange(root->right,min,max);

    if(root->data<min) return root->right;
    if(root->data>max) return root->left;

    return root;
}

void inorderTraversal(Node*root){
    if(!root)return ;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){

    Node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);
 
    cout << "Inorder traversal of the given tree is: ";
    inorderTraversal(root);
    
    root = deleteRange(root, -10, 13);
 
    cout << "\nInorder traversal of the modified tree is: ";
    inorderTraversal(root);
    return 0;
}