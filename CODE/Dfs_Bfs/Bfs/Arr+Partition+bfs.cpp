// check if a given sum is achevied from a subset such that the array is minimaly sliced by the average of max and min values of array
// slicing : 1) take average of min and max 2)either remove all elements <=avg or elements >avg.

#include<bits/stdc++.h>
using namespace std;
class Point{
    public:
    int l;
    int r ;
    int lvl;
    Point (int x,int y,int z){
        l =x;
        r=y;
        lvl=z;
    }
};

int upperBound(int * arr, int l,int r,int val){
    for(int i=l;i<=r;i++ ){
        if(arr[i]>val)return i;
    }
    return r+1;
}
int fn (){
    int arr[]={4,8,5,6,2,3,1,7,9};

    int sum =15;
    sort(arr,arr+9);
    int prefix[9]={arr[0]};
    cout<<"1 ";
    for(int i =1;i<9;i++){
        prefix[i]=arr[i]+prefix[i-1];
        cout<<prefix[i]<<" ";
    }
    cout<<endl;
    queue< Point >Q;
    Q.push(Point(0,8,0));
    
    while(!Q.empty()){
        
        int l =Q.front().l;
        int r =Q.front().r; 
        cout<<l<<" "<<r<<"| ";
        int lvl =Q.front().lvl;Q.pop();
        if(l==r ||arr[l]==arr[r]){
            continue;
        }
        if(sum == ( prefix[r]-prefix[l] + arr[l] )  ) return lvl;

        int avg = (arr[l]+arr[r])/2 ;
        int mid = upperBound(arr,l,r, avg) -1;

        int pl =(prefix[mid]-prefix[l])+arr[l];
        int pr = (prefix[r]-prefix[mid+1])+arr[mid+1];
        

        if(pl>=sum && l<=mid)
        Q.push(Point(l,mid,lvl+1));
        if(pr>=sum && r>=(mid+1))
        Q.push(Point(mid+1,r,lvl+1));
        
    }
    return -1;
}

int main(){
    cout<<fn();
    return 0;    
}