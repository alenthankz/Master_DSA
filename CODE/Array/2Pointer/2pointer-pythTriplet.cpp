#include<bits/stdc++.h>
using namespace std;

int countTriplet(int arr[], int n)
	{
	    map<int,int>mp;
	    int count=0;
	    for(int i =0;i<n;i++)mp[arr[i]]++;
	    
	    for(int i =0;i<n;i++){
	        for(int j =i+1;j<n;j++){
	            if(mp[(arr[i]+arr[j])])count++;
	        }
	    }
	    return count;
	}



int main(){
    // this is wrong check the above fn
    int input[5]={1,4,9,16,25};
    int l,r;
    for(int i =0;i<5-2;i++){
        l =i+1;r=5-1;
        while(l<r){
            if(input[i]+input[l]==input[r]){cout<<"True";break;}
            else{
                input[l]+input[i]<input[r]?r--:l++;
            }
        }
    }


   
    return 0;
}