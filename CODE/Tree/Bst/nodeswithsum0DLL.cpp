// we can always store it in a sorted array and use two pointer approach but it would take more space. 
// so we better use the DLL.

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
void tree2DLL(Node *root , Node**head , Node**tail){
    if(root==NULL)return ;
    tree2DLL(root->left,head,tail);
    if(*head==NULL){*head=*tail=root;}
    else{
        root->left=*tail;
        (*tail)->right=root;
    }
    *tail=root;
    tree2DLL(root->right,head,tail);
}

bool ifExist(Node * head , Node*tail,int sum){
    while(head!=tail){
        if(head->data+tail->data==sum)return true;
        else if (head->data+tail->data<sum)head=head->right;
        else tail=tail->left;
    }
    return false;
}

bool checkTripletZero(Node * root){
    Node *head=NULL,*tail=NULL;
    tree2DLL(root,&head,&tail);
    while(head->right!=tail && head->data<0){
        if(ifExist(head->right , tail , -1*head->data)) return true;
        else head= head->right;
    }
    return false;
}

int main(){

}