#include<bits/stdc++.h>
using namespace std;
// Merge Without Extra Space
// TC : O (m+n)(logm + logn)
void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i =0,j=0,k=n-1;
            
            while(i<=k && j<m){
                if(arr1[i]<arr2[j])i++;
                else{
                    swap(arr1[k],arr2[j]);
                    j++;k--;
                }
            } //TC : O(m+n)
            sort(arr1,arr1+n); //TC: O(nlogn)
            sort(arr2,arr2+m); //TC: O(mlogm)
            
        } 