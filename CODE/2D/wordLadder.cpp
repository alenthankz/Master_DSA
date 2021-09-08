#include<bits/stdc++.h>
using namespace std;

#define N 4
int wordLadder(set<string>dict,string start,string target){
    queue<string>Q;
    int level=0;
    Q.push(start);
    while(!Q.empty())
    {
        int siz = Q.size();
        level++;
        while(siz--){
            string str = Q.front();Q.pop();

            for(int i =0;i<N;i++){
                int ltrHere=str[i];
                for( char c='a'; c<='z';c++ ){
                    str[i]=c;
                    if(str==target)return level+1;
                    if(dict.count(str)){
                        Q.push(str);
                        dict.erase(str);
                    }
                }
                str[i]=ltrHere;
            }

        }
    }

}

int main(){
    set<string>D;
    D.insert("poon"); 
    D.insert("plee"); 
    D.insert("same"); 
    D.insert("poie"); 
    D.insert("plie"); 
    D.insert("poin"); 
    D.insert("plea"); 
    string start = "toon"; 
    string target = "plea";

    cout<<wordLadder(D,start,target);
// toon->poon->poin->poie->plie->plea
//  0     1     2     3     4     5

    return 0;
}