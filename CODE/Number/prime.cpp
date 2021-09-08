#include<bits/stdc++.h>
using namespace std;
// usually good to precalculate if many test cases
// 1--> prime
void normalSieve(int n){
    vector<int>prime(n+1,1);
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j =i*i;j<=n;j+=i){
                if(prime[j])
                    prime[j]=0;
            }
        }
    }
}

void rangeSeive(int a,int b){
    vector<int>prime(b-a+1,0);
    for(int i =2;i<a;i++){
        int j =ceil(1.0*a/i)*i;
        for(;j<=b;j+=i){
            prime[j-a]=1;
        }
    }
}

void primeFactors(int n){
    vector<int>fact(n+1,0);
    for(int i=2;i<=n;i++)fact[i]=i;
    for(int i=4;i<=n;i+=2)fact[i]=2;

    for(int i =3;i*i<=n;i++){
        if(fact[i]==i){
            for(int j =i*i;j<=n;j+=i){
                if(fact[j]==j)
                    fact[j]=i;
            }
        }
    }
}


int sumOfFactors(int a){
    int sum =0;
    for(int i =2;i*i<=a;i++){
        if(a%i==0){
            if( (a/i)==i )sum+=i;
            else sum =a/i + i;
        }
    }
}




int main(){
    return 0;
}