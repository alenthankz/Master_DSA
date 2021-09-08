// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //the idea here is for a bar find bars left to it which is smaller than it 
    //and right to it which is smaller than it; that is exactly next smallest element
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long>stk;
        long long maxArea=1;
        long long i =0;
        while(i<n){
            if(stk.empty() || arr[stk.top()]<=arr[i]){
                stk.push(i);i++;
            }
            else{
                long long j = stk.top();stk.pop();
                long long area =1;
                if(stk.empty())area = i*arr[j];
                else area = arr[j]*(i-stk.top()-1);
                if(area>maxArea)maxArea=area;
            }
        }
        while(!stk.empty()){
            
                long long j = stk.top();stk.pop();
                long long area =1;
                if(stk.empty())area = i*arr[j];
                else area = arr[j]*(i-stk.top()-1);
                if(area>maxArea)maxArea=area;
            
        }
        return maxArea;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends