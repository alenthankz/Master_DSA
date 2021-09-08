#include<bits/stdc++.h>
using namespace std;

struct Interval{
    int start,end;
};

int myComp(const Interval& a ,const Interval&b){
    if(a.end==b.end)return a.start<b.start;
    return a.end<b.end; 
}

int main(){
    Interval intvls[6]={{1,2},{3,4},{0,6}, {5,7},{8,9},{5,9}};
    sort(intvls,intvls+6,myComp);//o(nlogn)
    int i =0;
    cout<<"Start: "<<" End :"<<endl;
    cout<<intvls[i].start<<"       "<<intvls[i].end<<endl;
    for(int j =1;j<6;j++){
        if(intvls[j].start>=intvls[i].end){
            i =j;
            cout<<intvls[i].start<<"       "<<intvls[i].end<<endl;
        }
    }
}