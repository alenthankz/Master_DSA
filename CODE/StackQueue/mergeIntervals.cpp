#include<bits/stdc++.h>
using namespace std;

class Interval{
    public:
    int start,end;
};

int myComp( const Interval& a, const Interval& b){
    return a.start<b.start;
}

//opposite to activity selection
void mergee(Interval *intervals,int n){
    stack<Interval>s;
    s.push(intervals[0]);
    for(int i =1;i<n;i++){
        Interval I =s.top();
        if(I.end<intervals[i].start)s.push(intervals[i]);
        else if( I.end<intervals[i].end){
            s.pop();
            I.end=intervals[i].end;
            s.push(I);
        }
        
    }
    while(!s.empty()){
        cout<<s.top().start<<" "<<s.top().end<<endl;s.pop();
    }

}
int main(){
    Interval intervals[]={ {6,8}, {1,9}, {2,4}, {4,7} }; 
    int n =sizeof(intervals)/sizeof(intervals[0]);

    sort(intervals,intervals+n,myComp);

    mergee(intervals,n);
    return 0;
}