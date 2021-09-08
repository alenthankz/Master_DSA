#include<bits/stdc++.h>
using namespace std;

int myComp(string a , string b){
    string ab = a.append(b);
    string ba = b.append(a);

    return (ab.compare(ba)>0)?1:0;
}

void maxFormed(int arr[],int n){
    string arrstr[n];

    for(int i =0;i<n;i++){
        arrstr[i]=to_string(arr[i]);
    }

    sort(arrstr,arrstr+n,myComp);

    string str="";
    for(int i =0;i<n;i++){
        str+=arrstr[i];
    }
    cout<<str;
}

int main(){
   
    int input[]={3,30,40,4,9};
    int n =sizeof(input)/sizeof(input[0]);
    maxFormed(input,n);
    return 0;
  
}
