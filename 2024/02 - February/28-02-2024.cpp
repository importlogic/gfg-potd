/*

Author : Manas Rawat 
Date : 28/02/2024
Problem : Check if a number is divisible by 8
Difficulty : Easy 
Problem Link : https://www.geeksforgeeks.org/problems/check-if-a-number-is-divisible-by-83957/1
Video Solution : NA

*/


//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        int n = stoi(s.substr(max((int)s.size() - 3, 0)));
        
        return n % 8 ? -1 : 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends
