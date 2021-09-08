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


void serializeUtil(Node* root , vector<int>&arr){
    if(!root){
        arr.push_back(-1);return ;
    }
    arr.push_back(root->data);
    serializeUtil(root->left,arr);
    serializeUtil(root->right,arr);
}

Node * deSerializeUtil(queue<int>&q){
        int val=q.front();q.pop();
        if(val==-1)return NULL ;
        Node *root= new Node(val);
        root->left = deSerializeUtil(q);
        root->right = deSerializeUtil(q);
        return root;
}
Node * deSerialize(vector<int> arr)
{ 
    int num=0;
    queue<int>q;
    for(int i =0;i<arr.size();i++){
        q.push(arr[i]);
    }
    return deSerializeUtil(q);    
}