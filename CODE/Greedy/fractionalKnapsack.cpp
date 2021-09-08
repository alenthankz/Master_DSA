#include<bits/stdc++.h>
using namespace std;
typedef vector< pair<int,int> > VII;
typedef pair<int,int> II;
#define value first 
#define weight second 

int myComp(II&a ,II&b){
    double r1 = double(a.value)/double(a.weight);
    double r2 = double(b.value)/double(b.weight);
    return r1>r2;
}
double fractionalKp(VII arr,int n ,int W){
    sort(arr.begin(),arr.end(),myComp);
    int weightNow =0;
    double valueNow =0;
    for(int i =0;i<n;i++){
        if(weightNow+arr[i].weight<=W){
            weightNow+=arr[i].weight;
            valueNow+=arr[i].value;
        }
        else{
            int remain = W-weightNow;
            valueNow+=arr[i].value * ( double(remain)/double(arr[i].weight) );
            break;
        }
    }
    return valueNow;
}

int main(){
    return 0;
}