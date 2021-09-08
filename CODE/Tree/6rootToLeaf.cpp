// here is a couple of questions related to traversal from root to leaf


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

//Check if there is a root to leaf path with given sequence

bool checkPathSeq(Node* root ,int idx ,int n ,int arr[]){
    if(root==NULL || idx==n)return false;

    if(!root->left && !root->right)
        if(idx==n-1 && arr[n-1]==root->data )
            return true;
        else 
            return false;

    if(root->data==arr[idx]){
        bool l = checkPathSeq(root->left,idx+1,n,arr);
        bool r = checkPathSeq(root->right,idx+1,n,arr);

        return l||r;
    }else return false;

}


// check if sum is possible from root to any leaf
bool checkPathSum(Node* root , int sum,vector<int>&ans,vector<int>&cal){
    if(!root)return false;

    sum=sum-root->data;
    if(!root->left && !root->right )
        if(!sum)
    //    {   cal.push_back(root->data);
    //        ans=cal;
    //        cal.pop_back(); 
           return true;
        // }
        else return false;
    // cal.push_back(root->data);
    bool l = checkPathSum(root->left,sum,ans,cal);
    bool r = checkPathSum(root->right,sum,ans,cal);
    // cal.pop_back();
    return l||r;
}

// check if sum is possible in a pair from root to any leaf
bool checkIfPairSum(Node * root , map<int,int>&mp , int sum){
    if(!root)return false;
    int rem=sum-root->data;
    if(mp[rem])return true;
    
    mp[rem]=1;
    bool l = checkIfPairSum(root->left,mp,sum);
    bool r = checkIfPairSum(root->right,mp,sum);
    mp.erase(rem);
    return l||r;
}

bool checkSumBST(Node * root , int sum){
    if(!root)return false;
    sum-=root->data;
    if(!root->left && !root->right){
        if(!sum)return true;
        else return false;
    }
    bool l =false,r=false;
    l = checkSumBST(root->left,sum);
    if(sum>=root->data){
        r=checkSumBST(root->right,sum);
    }
    return l||r;
}

int main(){
   
    return 0;
}