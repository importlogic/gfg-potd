/*

Author : Manas Rawat
Date : 30/11/2023
Problem : Shortest path from 1 to n
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1
Video Solution : https://youtu.be/pazYhH19QXE

*/


//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minimumStep(int n){
        int ans = 0;
        
        while(n >= 3){
            ans += n % 3 + 1;
            n /= 3;
        }
        
        return ans + (n - 1);
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
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 


// } Driver Code Ends