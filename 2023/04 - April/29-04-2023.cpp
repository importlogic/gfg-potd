/*

Author : Manas Rawat
Date : 29/04/2023
Problem : Find Number
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/35bff0ee40090b092e97b02f649085bf1390cc67/1
Video Solution : https://youtu.be/ZACMG6WDTVM

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long n){
        vector<int> v = {9, 1, 3, 5, 7};
        
        function<string(long long)> base5 = [&](long long x) -> string {
        	if(x == 0)
        		return "";
    
        	string ans = base5(x / 5 - ((x % 5 == 0) ? 1 : 0)) + to_string(v[x % 5]);
        	return ans;
        };
        
        return stol(base5(n));
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends