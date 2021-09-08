// rotton oranges 

#include<bits/stdc++.h>
using namespace std;


class Point{
    public:
    int idx,idy,lvl;
    Point(int a ,int b,int c){
        idx=a;idy=b;lvl=c;
    }
};
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int isSafe(int i ,int j, int n ,int m, vector< vector<int> >& grid){
        if(i<n && j<m && i>=0 && j>=0 && grid[i][j]==1){
            grid[i][j]=2;
            return true;
        }
        
        return false;
    }
    int orangesRotting(vector< vector<int> >& grid) {
        queue<Point>q;
        int n = grid.size(),m=grid[0].size();
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++ ){
                if(grid[i][j]==2){
                    q.push(Point(i,j,0));
                }
            }
        }
        int maxx =0;
        
        while(!q.empty()){
           Point p = q.front();q.pop();
           maxx = max( maxx , p.lvl); 
           if(isSafe(p.idx,p.idy-1,n,m,grid)){q.push(Point(p.idx,p.idy-1,p.lvl+1));}
           if(isSafe(p.idx,p.idy+1,n,m,grid)){q.push(Point(p.idx,p.idy+1,p.lvl+1));}
           if(isSafe(p.idx-1,p.idy,n,m,grid)){q.push(Point(p.idx-1,p.idy,p.lvl+1));}
           if(isSafe(p.idx+1,p.idy,n,m,grid)){q.push(Point(p.idx+1,p.idy,p.lvl+1));}
        }
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++ ){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return maxx;
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector< vector<int> >grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends