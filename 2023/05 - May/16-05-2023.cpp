/*

Author : Manas Rawat
Date : 16/05/2023
Problem : Cutting Binary String
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/cutting-binary-string1342/1
Video Solution : https://youtu.be/Up9wcPU-WDI

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int cuts(string s){
        int n = s.size();
        
        vector<int> dp(n);
        
        auto gud = [&](int st, int en) -> bool {
            string current = s.substr(st, en - st + 1);
            
            long long val = 0;
            reverse(current.begin(), current.end());
            
            for(int i = 0; i < current.size(); i++){
                if(current[i] == '1')
                    val += 1LL << i;
            }
            
            while(val % 5 == 0)
                val /= 5;
                
            return val == 1;
        };
        
        for(int i = n - 1; i > -1; i--){
            if(s[i] == '0'){
                dp[i] = -1;
                continue;
            }
            
            dp[i] = 1e9;
            
            for(int j = i; j < n; j++){
                if(gud(i, j)){
                    if(j == n - 1)
                        dp[i] = 1;
                    else if(dp[j + 1] != -1)
                        dp[i] = min(1 + dp[j + 1], dp[i]);
                }
            }
            
            if(dp[i] == 1e9)
                dp[i] = -1;
        }
        
        return dp[0];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends