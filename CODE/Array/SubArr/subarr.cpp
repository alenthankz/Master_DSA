#include<bits/stdc++.h>
using namespace std;

int main(){
    int input[5]={1,2,3,4,5};
    // if instead start and end, start and count is given two loops is enough. 
    for(int st =0;st<5;st++){
        for(int en=st;en<5;en++){
            for(int k=st;k<=en;k++){
                cout<<input[k];
            }
            cout<<"|";
        }
         cout<<endl;
    }
}