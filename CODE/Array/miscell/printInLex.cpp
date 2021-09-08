#include<bits/stdc++.h>
using namespace std;

vector<string> fn(int n){
    int len =log10(n)+1;
    vector<string>v;
    if(len ==0){
        v.push_back("Empty");
        return v;
    }
    string single_digits[] ={ "zero", "one", "two", "three", "four",
            "five", "six", "seven", "eight", "nine"};
    string double_digits[] ={"", "ten", "eleven", "twelve",
            "thirteen", "fourteen", "fifteen", "sixteen",
            "seventeen", "eighteen", "nineteen"};
    string tens_mult[]={
         "", "", "twenty", "thirty", "forty",
            "fifty", "sixty", "seventy", "eighty", "ninety"};
    string tens_power[]={"hundred", "thousand" };
    
}

int main(){
    int n;
    cin>>n;

    return 0;
}