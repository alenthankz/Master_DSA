#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

//onemore problemof subsequence
int findLongestConseqSubseq(int arr[], int N)
    {
      set<int>s;
      for(int i =0;i<N;i++){
          s.insert(arr[i]);
      }
      int max_count=0;
      for(int i =0;i<N;i++){
           int j =arr[i];
           if(s.count(j-1));
           else{
               int count=0;
               while(s.count(j)){
                   j++;count++;
               }
               max_count=max(max_count,count);
           }
      }
      return max_count;
      
    }