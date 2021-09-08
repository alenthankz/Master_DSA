// minimum flips needed to make A 'OR' B equal to C;
// OR properties 1or0 =1 , 0or0 =0 , 1or1 =1
#include<bits/stdc++.h>
using namespace std;


int main(){
    int A,B,C;
    int count =0;
    for(int i =0;i<31;i++){
        bool a = A&(1<<i) , b=B&(1<<i);
        if( (1<<i)&C){
            if(!a&&!b)count+=1;
        }else{
            if(a && b ) count+=2;
            else if(a || b)count+=1;
        }
    }
    return 0;
}