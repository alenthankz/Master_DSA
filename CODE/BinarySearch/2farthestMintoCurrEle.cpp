#include<bits/stdc++.h>
using namespace std;

vector<int> farthestMinNumberIndex(int N,vector<int> Arr){
        vector<int>V(N,-1);
        vector<int>suffMin(N);
        suffMin[N-1]=Arr[N-1];
        for(int i =N-2;i>=0;i--){
            suffMin[i]=min(suffMin[i+1],Arr[i]);
        }
        for(int i =0;i<N;i++){
            int high=N-1;
            int low=i+1;
            while(low<=high){
                int mid = (low+high)/2;
                if(suffMin[mid]<Arr[i]){
                    V[i]=mid;
                    low =mid+1;
                }else{
                    high =mid-1;
                }
            }
        }
        
        return V;
    }