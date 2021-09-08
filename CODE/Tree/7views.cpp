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

void topView(Node * root){
    if(root==NULL){cout<<root->data;return;}
    queue<pair<Node*,int> >q;
    q.push( make_pair(root,0) );
    map<int,int>m;
    while(!q.empty()){
        pair<Node*,int>p =q.front();q.pop();
        
        if(m[p.second]==0){
            // cout<<p.second<<"  "<<p.first->data<<" "<<endl;
           m[p.second]=p.first->data;
        }
        if(p.first->left){
            q.push(make_pair(p.first->left,p.second+1));
        }
        if(p.first->right){
            q.push(make_pair(p.first->right,p.second-1));
        }
    }

    for(map<int,int>::iterator it =m.begin();it!=m.end();it++){
        cout<<it->second<<" ";
    }
}
void bottomView(Node * root){
    if(root==NULL){cout<<root->data;return;}
    queue<pair<Node*,int> >q;
    q.push( make_pair(root,0) );
    map<int,int>m;
    while(!q.empty()){
        pair<Node*,int>p =q.front();q.pop();
        
        m[p.second]=p.first->data;
        
        if(p.first->left){
            q.push(make_pair(p.first->left,p.second+1));
        }
        if(p.first->right){
            q.push(make_pair(p.first->right,p.second-1));
        }
    }

    for(map<int,int>::iterator it =m.begin();it!=m.end();it++){
        cout<<it->second<<" ";
    }
}

void leftView(Node * root){
    if(root==NULL){cout<<root->data;return;}
    queue<pair<Node*,int> >q;
    q.push( make_pair(root,0) );
    map<int,int>m;

    while(!q.empty()){
        pair<Node*,int>p =q.front();q.pop();
        if(m[p.second]==0){
            m[p.second]=p.first->data;
        }
       
        if(p.first->left){
            q.push(make_pair(p.first->left,p.second+1));
        }
        if(p.first->right){
            q.push(make_pair(p.first->right,p.second+1));
        }
    }

    for(map<int,int>::iterator it =m.begin();it!=m.end();it++){
        cout<<it->second<<" ";
    }
}

void rightView(Node * root){
    if(root==NULL){cout<<root->data;return;}
    queue<pair<Node*,int> >q;
    q.push( make_pair(root,0) );
    map<int,int>m;

    while(!q.empty()){
        pair<Node*,int>p =q.front();q.pop();
        if(m[p.second]==0){
            m[p.second]=p.first->data;
        }
       
        if(p.first->right){
            q.push(make_pair(p.first->right,p.second+1));
        }
        if(p.first->left){
            q.push(make_pair(p.first->left,p.second+1));
        }
    }

    for(map<int,int>::iterator it =m.begin();it!=m.end();it++){
        cout<<it->second<<" ";
    }
}


int main(){
    Node* root = new Node(1); 

    root->left = new Node(2); 

    root->right = new Node(3); 

    root->left->right = new Node(4); 

    root->left->right->right = new Node(5); 

    root->left->right->right->right = new Node(6); 

    cout<<"TopView:\n";  
    topView(root); 
    cout<<"\nBottomView:\n";  
    bottomView(root); 
    cout<<"\nLeftView:\n";  
    leftView(root); 
    cout<<"\nRightView:\n";  
    rightView(root); 

    return 0; 
}