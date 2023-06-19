/*

Author : Manas Rawat
Date : 08/05/2023
Problem : Binary Modulo
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/7488b7721e8aa5e5fc37d56af8b9c89e329c796f/1
Video Solution : https://youtu.be/Duv0VDL19cs

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int m)
        {
            int ans = 0;
            
            reverse(s.begin(), s.end());
            
            int current = 1;
            
            for(int i = 0; i < s.size(); i++){
                if(s[i] == '1'){
                    ans = (ans + current) % m;
                }
                
                current = (current * 2) % m;
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
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends