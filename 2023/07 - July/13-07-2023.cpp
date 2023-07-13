/*

Author : Manas Rawat
Date : 13/07/2023
Problem : Unique Number of Occurrences
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/unique-frequencies-of-not/1
Video Solution : https://youtu.be/y8vIsmJnsNI

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
    bool isFrequencyUnique(int n, int arr[])
    {
        vector<int> totalFrequency(n + 1, 0);
        
        unordered_map<int,int> f;
        for(int i = 0; i < n; i++)
            ++f[arr[i]];
        
        for(auto it : f){
            totalFrequency[it.second]++;
        }
        
        for(int i = 0; i < n + 1; i++)
            if(totalFrequency[i] > 1)
                return 0;
                
        return 1;
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
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends