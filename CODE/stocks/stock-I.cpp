// buy and sell a stock for 1 time to maximize the profit
#include<bits/stdc++.h>
using namespace std;

int maxProfit(int * price , int n){
    int profit =0;
    int min = INT_MAX;
    for(int i =0;i<n;i++){
        if(price[i]<min)min=price[i];
        else {
            profit = max ( profit , price[i]-min );
        }
    }
    return profit;
}

int main(){
    return 0;
}