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

Node * constructFromPreorder(int pre[] , int * preIdx , int low ,int high ,int n){

    if(*preIdx>=n || low>high)return NULL;

    Node * root = new Node( pre[*preIdx] ); 
    *preIdx=*preIdx+1;

    if(low==high)return root;

    int i;
    for(i =low ;i<=high;i++){
        if(pre[i]>root->data)break;
    }
    root->left = constructFromPreorder(pre,preIdx,*preIdx,i-1,n);
    root->right = constructFromPreorder(pre,preIdx,i,high,n);
    return root;
}

Node * frmSrtArr( int arr[] ,int low ,int high ){
    if(low>high) return NULL;
    int mid = (low+high)/2;
    Node * root = new Node(arr[mid]);
     if(low==high)return root;            //this condition only in trees
    root->left = frmSrtArr(arr,low,mid-1);
    root->right = frmSrtArr(arr,mid+1,high);
    return root;
}

int main(){
    return 0;
}