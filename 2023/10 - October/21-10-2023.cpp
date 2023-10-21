/*

Author : Manas Rawat
Date : 21/10/2023
Problem : Sum of all divisors from 1 to n
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1
Video Solution : NA

*/


//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long ans = 0;
        
        for(int i = 1; i < N + 1; i++){
            ans += i * (N / i);
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
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends