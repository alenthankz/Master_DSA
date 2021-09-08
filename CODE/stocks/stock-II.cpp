// you can buy and sell stocks any no of times . i,e any number of transaction is allowded

#include<bits/stdc++.h>
using namespace std;

int maxProfit(int * price ,int n){
    int i =0,profit=0;
    while(i<n-1){
        while(i<n-1 && price[i+1]<=price[i])i++; //find local min to buy 
        if(i==n-1)break;
        int buy = price[i++];
        while(i<n && price[i-1]<=price[i])i++;  //find local max to sell
        int sell = price[i-1];
        profit+= (sell-buy);
    }
    return profit;
}

int main(){
    return 0;
}
