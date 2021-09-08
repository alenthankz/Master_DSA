#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    int lcount;
    Node * left,*right;
    Node(int val){
        data=val;left=right=NULL;
        lcount=0;
    }
};
// instead of int , we can have Node * 
int  kthSmallest(Node * root, int * k ){
     if(!root)return 0;
     int a = kthSmallest(root->left,k);
     if(a!=0)return a;
     *k=*k-1;
     if(*k==0) return root->data;

     int b = kthSmallest(root->right,k);
     return b;
    
}

Node * kthSmallestLcount(Node * root , int k){
    if(!root)return NULL;

    int count = root->lcount+1;
    if(count ==k) return root;

    if(count>k)
       return kthSmallestLcount(root->left,k);
    return kthSmallestLcount(root->right , k-count);
}

Node* insert(Node*root,int val){
    if(!root) return new Node(val);
    if(val>root->data)
       root->right = insert(root->right,val);
    else
       root->left = insert(root->left,val);
       root->lcount++;
    return root;
}

void inorder(Node * root){
    if(!root)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
} 

int main(){
    Node* root = NULL;
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 };
    int n =7;
    for (int i=0;i<n;i++ )
        root = insert(root, keys[i]);
    int k =3;
    // inorder(root);
    cout<<kthSmallest(root,&k);
    return 0;
}


