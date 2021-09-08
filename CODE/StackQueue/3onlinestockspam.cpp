// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends




class Solution
{
    public:
    /* maximum number of consecutive days just before the given day,
    for which the price of the stock on the current day is less than
    or equal to its price on the given day.
    */
    vector <int> calculateSpan(int price[], int n)
    {
       stack<int>stk;
       vector<int>ans(n,1);
       for(int i =0;i<n;i++){
           while(!stk.empty() && price[stk.top()] <= price[i]){
               ans[i]+=ans[stk.top()];
               stk.pop();
           }
           stk.push(i);
       }
       return ans;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends