#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next,*prev;
    Node(int va){
        data=va;
        next=prev=NULL;
    }
};

class QLLModifed{
    public:
    Node *front,*rear;
    map<char,Node*>mp;
    map<char,int>repeated;

    QLLModifed(){
        front=rear=NULL;
    }

    char firstNonRepeat(char val){
        if(repeated[char])
            return front!=NULL?front->data:'#';
        
        if(!mp[val]){
            push(val);
            mp[val]=rear;
            return front!=NULL?front->data:'#';
        }

        Node*tNode=mp[val];
        mp.erase(val);
        repeated[val]=1;
        if(tNode==front)pop();
        else{
            tNode->prev->next=tNode->next;
            if(tNode->next){
                tNode->next->prev=tNode->prev;
            }
        }
    }



    void push(int val){
        Node*tnode=new Node(val);
        if(front==NULL){
            rear=front=temp;
            return;
        }
        (rear)->next=tnode;
        tnode->prev=(rear);
        (rear)=tnode;
    }

    void pop(){
        if(front==rear){
            front=rear=NULL;
            return;
        }
        (front)=(front)->next;
        (front)->prev=NULL;
    }


};




int main(){
    Node *root     = new Node(1);
    root->left     = new Node(2);
    root->right     = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return 0;
}
