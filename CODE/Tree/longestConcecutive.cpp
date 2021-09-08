
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node *left,*right;
    int data;
    Node(int dat){
        left=NULL;right=NULL;
        data=dat;
    }
};
// Longest consecutive sequence in Binary tree
/*
            1
        2      3
                  4
                    5

ans: 3 (3->4->5)
*/
void longestConsecutive(Node*root , int length , int expected , int &res){
    
    if(!root)return;
    if(root->data==expected)length++;
    else length =1;
    res = max(res , length);
    longestConsecutive(root->left,length,root->data+1,res);
    longestConsecutive(root->right,length,root->data+1,res);
        
}