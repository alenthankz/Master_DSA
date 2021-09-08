// given a number find the minimum no of squares such that sum of those squares add upto the given number 
// ex: 100 => 1 (10*10)  , 125 => 2 (10*10+5*5) , 98=> 2 (7*7+7*7)

#include<bits/stdc++.h>
using namespace std;

int recur(int num ){
    int root = sqrt(num);
    if(root*root==num)return 1;
    int ans =INT_MAX;
    for(int i =1;i*i<=num;i++){
        ans = min(ans , 1+recur(num-i*i));
    }
    return ans;
}

//NB largest square number can be done using modifed BS
int main(){

    return 0;
}