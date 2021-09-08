/*
Given the arrival and departure times of all trains that reach a railway station,
 the task is to find the minimum number of platforms required for the railway station so that no train waits. 
*/

#include<bits/stdc++.h>
using namespace std;

// ensure that there is no clash in platforms

int findPlatforms(int arr[],int dept[] ,int n){
    sort(arr,arr+n);
    sort(dept,dept+n);
    
    int i =0,j=0;
    int platforms=1,result=1;

    while(i<n && j<n){
        if(arr[i]<=dept[i]){
            platforms++;
            i++;
        }else{
            platforms--;
            j++;
        }

        if(platforms>result)result=platforms;
    }
    return result;
}

int main(){

    return 0;
}