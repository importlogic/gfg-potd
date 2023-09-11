/*

Author : Manas Rawat
Date : 11/09/2023
Problem : Lucky Numbers
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/lucky-numbers2911/1
Video Solution : https://youtu.be/80L_6Z6uTso

*/


//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
public:
    bool isLucky(int n) {
        int x = 2;
        
        while(x <= n){
            if(n % x == 0)
                return 0;
                
            n -= n / x;
            ++x;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends