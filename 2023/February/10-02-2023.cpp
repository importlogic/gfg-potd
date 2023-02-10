/*

Author : Manas Rawat
Date : 10/02/2023
Problem : Balloon Everywhere
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/45fa306a9116332ece4cecdaedf50f140bd252d4/1
Video Solution : https://www.youtube.com/watch?v=4yDDD0Dq1Bo

*/




//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        map<char,int> mp;
        
        for(auto i : s) ++mp[i];
        
        mp['l'] >>= 1; //dividing by 2
        mp['o'] >>= 1;
        
        int ans = min({mp['b'], mp['a'], mp['l'], mp['o'], mp['n']});
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends