/*

Author : Manas Rawat
Date : 08/03/2023
Problem : Max min Height
Difficulty : Hard
Problem Link : https://practice.geeksforgeeks.org/problems/899540d741547e2d75d1c5c03a4161ab53affd13/1
Video Solution : https://youtu.be/cpQet-NTpVA

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

bool checker(int n, int k, int w, vector<int> &a, long long mid){
    vector<long long> dp(n, 0), start(n, 0), end(n, 0);
    
    if(a[0] < mid){
        long long need = mid - a[0];
        if(k < need)
            return 0;
        
        k -= need; 
        
        start[0] += need;
        end[w - 1] += need;
        
        dp[0] += need;
    }
    
    for(int i = 1; i < n; i++){
        dp[i] = dp[i - 1] - end[i - 1];
        
        if(a[i] + dp[i] < mid){
            long long need = mid - (a[i] + dp[i]);
            if(k < need)
                return 0;
                
            k -= need;
                
            start[i] += need;
            end[min(i + w - 1, n - 1)] += need;
            
            dp[i] += need;
        }
    }
    
    return 1;
}

class Solution
{
    public:
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            long long low = *min_element(a.begin(), a.end());
            long long high = 1e10;
            
            while(low < high - 1){
                long long mid = low + (high - low) / 2;
                
                if(checker(n, k, w, a, mid))
                    low = mid;
                else
                    high = mid;
            }
            
            return low;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends