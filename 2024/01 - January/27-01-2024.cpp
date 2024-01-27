/*

Author : Manas Rawat
Date : 27/01/2024
Problem : Brackets in Matrix Chain Multiplication
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1
Video Solution : https://youtu.be/O7H_Pmk1vAg

*/


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    string matrixChainOrder(int p[], int n){
        vector<vector<pair<long long,int>>> dp(n, vector<pair<long long, int>> (n, {1e18, -1}));
        
        for(int i = 0; i < n - 1; i++){
            dp[i][i] = dp[i][i + 1] = {0, -1};
        }
        
        dp[n - 1][n - 1] = {0, -1};
        
        for(int i = n - 1; i > -1; i--){
            for(int j = i + 2; j < n; j++){
                for(int k = i + 1; k < j; k++){
                    long long cur = (long long)p[i] * (long long)p[j] * (long long)p[k] + dp[i][k].first + dp[k][j].first;
                    
                    if(cur < dp[i][j].first){
                        dp[i][j].first = cur;
                        dp[i][j].second = k;
                    }
                }
            }
        }
        
        vector<string> res(n + n - 1, "");
        char in;
        
        for(int i = 1, in = 'A'; i < n + n - 1; i += 2, in++)
            res[i] += in;
        
        function<void(int, int)> helper = [&](int i, int j) {
            if(j - i < 2)
                return;
            
            int start_pos = i * 2;
            int end_pos = j * 2;
            
            res[start_pos] += '(';
            res[end_pos] += ')';
            
            helper(i, dp[i][j].second);
            helper(dp[i][j].second, j);
        };
        
        helper(0, n - 1);
        
        string ans = "";
        
        for(auto i : res)
            ans += i;
        
        return ans;
    }
};

//{ Driver Code Starts.

int get(int p[],int n)
{
    int m[n][n],ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++){ 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                { 
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int find(string s,int p[])
{
    vector<pair<int,int>> arr;
    int ans = 0;
    for(auto t:s)
    {
        if(t=='(')
        {
            arr.push_back({-1,-1});
        }
        else if(t==')')
        {
            pair<int,int> b=arr.back();
            arr.pop_back();
            pair<int,int> a=arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first,b.second});
            ans += a.first*a.second*b.second;
        }
        else 
        {
            arr.push_back({p[int(t-'A')],p[int(t-'A')+1]});
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
        {
            cin>>p[i];
        }
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result,p)==get(p,n))
        {
            cout<<"True"<<endl;
        }
        else
        {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends