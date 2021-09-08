// given an 2d array of each row 1s and 0s in sorted order , find the first row with maximum 1s

#include<bits/stdc++.h>
using namespace std;
#define N 5
#define M 5

// the idea here is we check the first row from end to 0 for the first '0' . then from second row onwards
// we start from the index where we met the '0' to index0 decreasing the time complexity to O(M+N);
int rowWithMaxOne(int mat[N][M]){
    int row =0;
    int start=M-1;
    for(int i =0;i<N;i++){
        for(int j =start;j>=0;j--){
            if(mat[i][j]);
            else{
                if(start>j)row=i;
                start=j;
                break;
            }
        }
    }
    return row;
}

// alternative modifiedBs

int modifiedBsLastOccurence(int mat[N][M],int row,int last){
    int low =0,high =last-1;
    int key =0;
    int ans=-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(mat[row][mid]>key)high=mid-1;
        else if(mat[row][mid]==key){ans=mid;low=mid+1;}
    }
    return ans;
}

int main(){
    return 0;
}