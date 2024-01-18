/*

Author : Manas Rawat
Date : 18/01/2024
Problem : Water the plants
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/water-the-plants--170646/1
Video Solution : https://youtu.be/M5Xb6tFZwr8

*/


//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<pair<int,int>> cover(n);
        
        for(int i = 0; i < n; i++){
            if(gallery[i] == -1)
                cover[i] = {1e7, 1e7};
            else
                cover[i] = {i - gallery[i], i + gallery[i]};
        }
        
        sort(cover.begin(), cover.end());
        
        int take = 0, index = 0, ans = 0;
        
        while(take < n){
            int nax = take - 1;
            
            while(index < n and cover[index].first <= take){
                nax = max(nax, cover[index++].second);
            }
            
            if(nax + 1 > take){
                ++ans;
                take = nax + 1;
            }
            else
                return -1;
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
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends