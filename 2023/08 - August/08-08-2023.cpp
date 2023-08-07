/*

Author : Manas Rawat
Date : 08/08/2023
Problem : Fraction pairs with sum 1
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/fraction-pairs-with-sum-1/1
Video Solution : https://youtu.be/V6yehqaZdms

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
    int countFractions(int n, int numerator[], int denominator[])
    {
        map<pair<int,int>, int> f;
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int gcd = __gcd(numerator[i], denominator[i]);
            numerator[i] /= gcd;
            denominator[i] /= gcd;
            
            int x, y;
            x = numerator[i];
            y = denominator[i];
            
            int z = y - x;
            
            if(f.count({z, y}))
                ans += f[{z, y}];
            
            ++f[{numerator[i], denominator[i]}];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends