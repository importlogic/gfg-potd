/*

Author : Manas Rawat
Date : 08/06/2023
Problem : Find Kth permutation
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/find-kth-permutation-0932/1
Video Solution : https://youtu.be/1WswXRFmwh0

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        string ans = "";
        vector<int> fact(10);
        fact[0] = fact[1] = 1;
        
        --k;
        
        for(int i = 2; i < 10; i++)
            fact[i] = fact[i - 1] * i;
            
        vector<bool> values(n + 1, 0);
        
        for(int i = 0; i < n; i++){
            int rem = n - i - 1;
            int comb = fact[rem];
            
            int up = k / comb;
            
            int val = 1;
            
            while(1){
                if(!values[val]){
                    if(up == 0)
                        break;
                    
                    --up;
                }
                
                ++val;
            }
            
            k = k % comb;
            
            ans += to_string(val);
            values[val] = 1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends