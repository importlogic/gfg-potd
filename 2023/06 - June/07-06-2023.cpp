/*

Author : Manas Rawat
Date : 07/06/2023
Problem : Least Prime Factor
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/least-prime-factor5216/1
Video Solution : https://youtu.be/HrsYg-uI164

*/


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        vector<int> ans(n + 1);
        
        for(int i = 0; i < n + 1; i++)
            ans[i] = i;
            
        for(int i = 2; i * i < n + 1; i++){
            if(ans[i] == i){
                for(int j = i + i; j < n + 1; j += i)
                    ans[j] = min(ans[j], i);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends