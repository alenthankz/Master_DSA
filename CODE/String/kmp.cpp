#include<bits/stdc++.h>
using namespace std;

//lps :   longest proper prefix which is also suffix.
void computeLps(vector<int>&lps,string pat){
    int i =0;
    lps[i]=0;
    i++;
    int j =0;
    while(i<pat.size()){
        if(pat[i]==pat[j]){
            j++;
            lps[i]=j;
            i++;
        }
        else{
            if(j==0){
                lps[i]=0;
                i++;
            }
            else{
                j=lps[i-1];
            }
        }
    }
}

void checktext(string text,string pat,vector<int>lps)
{
    int N =pat.size();
    int M =text.size();
    int n=0,m=0;
    while(m<M){
        if(text[m]==pat[n]){
            n++;m++;
            if(n==N){
                cout<<"pat at: "<<m-n<<"endl";
                n=lps[n-1];
            }
        }
        else{
            if(lps[n]!=0){
                n=lps[n-1];
            }
            else{
                m++;
            }
        }
    }
}
int main(){
    string pat="",text="";
    vector<int>lps(pat.size(),0);
    computeLps(lps,pat);
    checktext(text,pat,lps);
    return 0;
}