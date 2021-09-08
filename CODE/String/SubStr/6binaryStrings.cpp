#include<bits/stdc++.h>
using namespace std;

// Split the binary string into max no of substrings with equal number of 0s and 1s
int split(string str){
    int cnt =0;
    int count0=0,count1=0;
    for(int i =0;str[i]!='\0';i++){
        if(str[i]=='0')count0++;
        else count1++;
        if(count0==count1)cnt++;
    }
    return cnt;
}

// Count of sub-strings with equal consecutive 0’s and 1’s
// 000111 is ok but 010011 is not ok as it is not concecutive
// 000111 => 000111 , 0011 ,01

int consecutive(string str){
    int n =str.size();
    int ans=0;
    int i =0;
    while(str[i]!='\0'){
        int count0=0,count1=0;
        if(str[i]=='0'){
            while(i<n && str[i]=='0'){count0++;i++;}
            int j =i;
            while(j<n && str[j]=='1'){count1++;j++;}

        }else{
            while(i<n && str[i]=='1'){count1++;i++;}
            int j =i;
            while(j<n && str[j]=='0'){count0++;j++;}
        }
        ans+=min(count0,count1);
    }
}


int countEqual01substr(){
    // IMPORTANT !!!!
    // UNDERSTAND "5substrContainEqlNoof" WELL .
}

int main(){
    /*
        To understand the difference of split , concecutive , nonconcecutive (all possible substr)
    */
    return 0;
}