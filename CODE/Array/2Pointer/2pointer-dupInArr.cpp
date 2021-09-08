#include<bits/stdc++.h>
using namespace std;

int main(){
    int input[14]={1,1,1,1,2,2,2,2,3,3,3,3,3,4};
    int st =0,j =-1;
    int i;
    for( i=0;i<14-1;i++){
        if(input[i]!=input[i+1]){
            j++;
            input[j]=input[i];
        }
    }
    j++;
    input[j]=input[i];
    int len =j+1;
    for(int i =0;i<len;i++){
        cout<<input[i]<<" ";
    }
    return 0;
}