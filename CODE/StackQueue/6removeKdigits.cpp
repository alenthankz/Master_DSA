#include <bits/stdc++.h>
using namespace std;

// remove k digits to form the smallest number possible
// this is simple stack idea or next smallest element (i,e smallest element to left and right )
class Solution{
    public:
    string removeKdigits(string S, int K) {
        stack<char>mystack;
        int count =0;
        for (int i =0;i<S.size();i++) {
            char c = S[i];
            while (!mystack.empty() && K > 0
                   && mystack.top() > c) {
                mystack.pop();
                K -= 1;
            }
     
            if (mystack.empty() && c == '0')continue;
            mystack.push(c);
        }
        
        string str="";
        while(!mystack.empty()){
            str=mystack.top()+str;mystack.pop();
        }
        
        return str;
}
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout<<obj.removeKdigits(S,K)<<endl;
    }
    return 0;
}
  // } Driver Code Ends