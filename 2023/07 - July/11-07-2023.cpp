/*

Author : Manas Rawat
Date : 11/07/2023
Problem : Find kth element of spiral matrix
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/find-nth-element-of-spiral-matrix/1
Video Solution : https://youtu.be/n6f37j0Aw7k

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int dx[] = { 0, 1, 0, -1};
 		int dy[] = { 1, 0, -1, 0}; 
 		
 		int cur = 0;
 		int x, y;
 		x = y = 0;
 		
 		vector<vector<bool>> vis(n, vector<bool> (m, 0));
 		
 		auto valid = [&](int xx, int yy) -> bool {
 		    if(xx < 0 or xx >= n or yy < 0 or yy >= m)
 		        return 0;
 		    
 		    return !vis[xx][yy];
 		};
 		
 		for(int i = 1; i <= n * m; i++){
 		    vis[x][y] = 1;
 		    
 		    if(i == k)
 		        return a[x][y];
 		       
 		    if(!valid(x + dx[cur], y + dy[cur]))
 		        cur = (cur + 1) % 4;
 		        
 		    x = x + dx[cur];
 		    y = y + dy[cur];
 		}
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends