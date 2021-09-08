#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next,*prev;
    Node(int val){
        data=val;
        next=prev=NULL;
    }
};

class QLLModifed{
    public:
    Node *front,*rear;
    map<int,Node*>mp;
    capacity;

    QLLModifed(int cp){
        front=rear=NULL;
        capacity=cp;
    }

    int isThere(int val){
        if(mp[val]){
            reorder(val);
            return 1;
        }
        else {
            insert(val);
            return 0;
        }
    }

    void insert(int val){
        push(val);
        mp[val]=rear;
        if(capacity){
            capacity--;
            return;
        }
        mp.erase(front->data);
        pop();
    }

    void reorder(int val){
        Node *tNode =mp[val];
        if(tNode==rear)return;
        if(tNode==front){
            pop();
        }else{
            tNode->prev->next=tNode->next;
            if(tNode->next){
                tNode->next->prev=tNode->prev;
            }
        }
        push(val);
        mp[val]=rear;

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

    return 0;
}
