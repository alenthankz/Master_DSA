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

void levelOrderTraversal(Node * root){
    if(root==NULL)return;
    queue<Node* >q;
    q.push(root);
    while(!q.empty()){
        Node * node =q.front();q.pop();
        cout<<node->data<<endl;
        if(node->left)
        q.push(node->left);
        if(node->right)
        q.push(node->right);
    }
}



Node * insert(Node* root,int dat){
    if(root==NULL){
        root=new Node(dat);
        return root;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node * node =q.front();q.pop();
        if(node->left)q.push(node->left);
        else {
            node->left=new Node(dat);return root;
        }
        if(node->right)q.push(node->right);
        else{
            node->right=new Node(dat);return root;
        }
    }
}



// level order spiral

void spiral(Node * root){
    stack<Node * >s1;
    stack<Node * >s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node * node =s1.top();s1.pop();
            if(node->left)s2.push(node->right);
            if(node->right)s2.push(node->left); //right left
        }
        while(!s2.empty()){
            Node * node =s2.top();s2.pop();
            if(node->left)s1.push(node->left);
            if(node->right)s1.push(node->right);//left right
        }
    }
}