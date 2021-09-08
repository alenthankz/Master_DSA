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

int height(Node * root){
    if(root==NULL)return 0;
    return 1+max(height(root->right),height(root->left));
}

int diameter(Node * root){
    if(root==NULL)return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    int ld =diameter(root->left);
    int rd =diameter(root->right);

    return max(lh+rh+1,max(ld,rd));
}

// diameter is the longest path between leaf nodes
// it can also be done using 2 dfs in a undirected tree , with first dfs at anynode and find the longest dist and longest node
// next dfs from that longestnode and find the longest ditance it is the diameter.

//or also using maximum path sum
// IMPORTANT !
/* 
int height(Node * root ,int &ans){
    if(root==NULL)return 0;
    int lh = height(root->left,ans);
    int rh = height(root->right,ans);
    ans = max(ans , lh+rh+1 );
    return 1+max(lh,rh);
}
int diameter(Node * root){
    int ans = INT_MIN;
    height(root,ans);
    return ans;
}
*/