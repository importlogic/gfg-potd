/*

Author : Manas Rawat
Date : 03/03/2023
Problem : Cutting Rectangles
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/a7a4da81b20f4a05bbd93f5786fcf7478298f4f5/1
Video Solution : https://youtu.be/JYkuOHQAVqg

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        vector<long long int> ans(2);
        
        ans[1] = __gcd(L, B);
        
        ans[0] = (L * B) / (ans[1] * ans[1]);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int L, B;
        cin>>L>>B;
        
        Solution ob;
        vector<long long int> ans = ob.minimumSquares(L, B);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends