/*

Author : Manas Rawat
Date : 26/12/2023
Problem : Largest rectangular sub-matrix whose sum is 0
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/largest-rectangular-sub-matrix-whose-sum-is-0/1
Video Solution : https://youtu.be/UQADCH6nx8w

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
        int n = a.size();
        int m = a[0].size();
        
        vector<vector<int>> rowPrefix(n + 1, vector<int> (m + 1, 0));
        
        for(int i = 1; i < n + 1; i++){
          for(int j = 1; j < m + 1; j++)
            rowPrefix[i][j] += rowPrefix[i][j - 1] + a[i - 1][j - 1];
        }
        
        int best = 0;
        int sx, sy, ex, ey;
        
        
        // starting column
        for(int i = 1; i < m + 1; i++){
            // ending column
          for(int j = i; j < m + 1; j++){
              map<int,int> pre;
              pre[0] = 0;
              
              int csum = 0;
              
              // through the rows
              for(int k = 1; k < n + 1; k++){
                  csum += rowPrefix[k][j] - rowPrefix[k][i - 1];
                  
                  if(pre.count(csum)){
                      int area = (j - i + 1) * (k - pre[csum]);
                      
                      if(area > best){
                          best = area;
                          
                          sx = pre[csum] + 1;
                          sy = i;
                          
                          ex = k;
                          ey = j;
                      }
                  }
                  else{
                      pre[csum] = k;
                  }
              }
          }
        }
      
        vector<vector<int>> ans;
      
        if(best == 0)
            return ans;
        
        for(int i = sx; i < ex + 1; i++){
            vector<int> curRow;
            
            for(int j = sy; j < ey + 1; j++)
                curRow.push_back(a[i - 1][j - 1]);
            
            ans.emplace_back(curRow);
        }
        
        return ans;
  }
};


//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends