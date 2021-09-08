#include<bits/stdc++.h>
using namespace std;

int main()
{
    int input[5]={1,0,3,4,5};
    int min1 =INT_MAX,min2 =INT_MAX;
    for(int i=0;i<5;i++)
    {
        if(input[i]<min1){
            min2 =min1;
            min1=input[i];
        }
        else if(input[i]<min2){
            min2=input[i];
        }
    }
    cout<<min1<<endl<<min2;
    return 0;
}