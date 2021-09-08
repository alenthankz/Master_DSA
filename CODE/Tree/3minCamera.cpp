#include<bits/stdc++.h>>
using namespace std;
/*
Given a Binary Tree consisting of N nodes, the task is to find the number of 
cameras required to monitor the entire tree such that every camera placed at
 any node can monitor the node itself, its parent, and its immediate children.
*/

class Node {
    public:
    Node * left ,*right ;
    int val;
};


int minCameraSetupUtil(Node* root,int&count)
{
    // If root is NULL
    if (root == NULL)
        return 1;
 
    int L = minCameraSetupUtil(
        root->left,count);
    int R = minCameraSetupUtil(
        root->right,count);
 
    // Both the nodes are monitored
    if (L == 1 && R == 1)
        return 2;
 
    // If one of the left and the
    // right subtree is not monitored
    else if (L == 2 || R == 2) {
        count++;
        return 3;
    }
    
    else if(L==3 ||R==3)return 1;
 
    return 1;
}
// returning values:
// 1 - ente karyam oke ann , ningalde karyam ningal thanne nokkikonnam
// 2 - enik protection vennam
// 3 - ningale njan nokkikolam