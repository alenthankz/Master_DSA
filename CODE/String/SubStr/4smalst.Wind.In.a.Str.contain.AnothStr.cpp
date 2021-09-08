// Find the smallest window in a string containing all characters of another string
//not substr but window
#include<bits/stdc++.h>
using namespace std;

/*
void check(string  text , string pat){
    vector<int>hP(256,0);
    vector<int>hT(256,0);
    vector<int>last(256,INT_MAX);
    int count =0;
    for(int i =0;i<pat.size();i++)hP[pat[i]]++;
    int len =INT_MAX;
    for(int i =0;i<text.size();i++){
        hT[text[i]]++;
        if(hP[text[i]]){
            if(hT[text[i]] <= hP[text[i]])count++;
            last[text[i]]=i;
        }
        if(count==pat.size()){
            int st = *min_element(last.begin(),last.end());
            len = min(len , i-st+1);
        }
    }

}
*/

int main(){
    string text ="this is a test string"; 
    string pat ="tist";

    vector<int>hText(256,0);
    vector<int>hPat(256,0);

    for(int i =0;i<pat.size();i++)hPat[pat[i]]++;
    int count =0;
    int start=0;
    int len =INT_MAX;
    int st=0;
    for(int i =0;i<text.size();i++){
        hText[text[i]]++;
        if(hText[text[i]]<=hPat[text[i]] && hPat[text[i]]!=0){
            count++;
        } //this technique here is important 
        if(count ==pat.size()){
            while(hText[text[start]]>hPat[text[start]]  || hPat[text[start]]==0)
                if(hText[text[start]]>hPat[text[start]] )hText[text[start]]--;
                 start++;
            
            len =min(len,i-start+1);
            if(len ==i-start+1)st=start;
        }
    }
    cout<<text.substr(start,len)<<endl;
    return 0;
}