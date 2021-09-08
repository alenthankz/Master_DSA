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





typedef pair< int ,pair<int,int>  > Point;
#define val first
#define maxx second.first
#define minn second.second
Point mkp3(int a ,int b ,int c){
    Point p ;
    p.val=a;
    p.maxx=b;
    p.minn=c;
    return p;
}
bool ifArrLevelOrderBST(int * arr ,int n ){
    queue<Point>Q;
    int i =0;
    Q.push( mkp3(arr[i++],INT_MAX,INT_MIN) );

    while(!Q.empty() && i<n){
        Point p =Q.front();Q.pop();
        if(i<n && (arr[i]>p.minn && arr[i]<p.val) ){
            Q.push(mkp3(arr[i++],p.val,p.minn));
        }
        if(i<n && (arr[i]>p.val && arr[i]<p.maxx) ){
            Q.push(mkp3(arr[i++],p.maxx,p.val));
        }
    }
    if(i==n)return true;
    else return false;
}

// check if an array represent preorder traversal , just do by diving the array based on next greater ekement
// and if it is in the range of min , max

bool isValidPreorder(int pre[], int n) {
   stack<int> stk;
   int root = INT_MIN;
   for (int i=0; i<n; i++) {
      if (pre[i] < root)
         return false;
      while (!stk.empty() && stk.top()<pre[i]) {
         root = stk.top();
         stk.pop();
      }
      stk.push(pre[i]);
   }
   return true;
}



bool isBST(Node * root,int min,int max){
    if(root==NULL)return true;
    if(root->data<max && root->data>min){
        return isBST(root->left,root->data+1,max) && isBST(root->right,min,root->data-1);
    }
    else return false;
}



//  int isBSTBEST( Node* node)
// {
//   if (node == NULL)
//     return 1;
     
//   /* false if left is > than node */
//   if (node->left != NULL && node->left->data > node->data)
//     return 0;
     
//   /* false if right is < than node */
//   if (node->right != NULL && node->right->data < node->data)
//     return 0;
   
//   /* false if, recursively, the left or right is not a BST */
//   if (!isBSTBEST(node->left) || !isBSTBEST(node->right))
//     return 0;
     
//   /* passing all that, it's a BST */
//   return 1;
// }



int main(){
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};    
    int n = sizeof(arr) / sizeof(arr[0]); 
    int idx =0;
    cout<<ifArrLevelOrderBST(arr,n);
    return 0;
}