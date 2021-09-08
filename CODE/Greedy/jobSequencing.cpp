#include<bits/stdc++.h>
using namespace std;
struct Job{
    char name;
    int deadline,profit;
};

int myComp(const Job& a,const Job &b){
    return a.profit>b.profit;
}

int main(){
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
                   {'d', 1, 25}, {'e', 3, 15}};
    int n =sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,myComp);

    vector<bool>slots(n,false);
    vector<char>result(n,'a');

    for(int i =0;i<n;i++){
        for(int j =min(n,arr[i].deadline)-1;j>=0;j--){
            if(slots[j]==false){
                result[j]=arr[i].name;
                slots[j]=true;
                break;
            }
        }
    }
    for(int i =0;i<n;i++){
        if(slots[i]){
            cout<<result[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}