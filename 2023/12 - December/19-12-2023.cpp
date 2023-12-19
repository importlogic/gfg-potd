/*

Author : Manas Rawat
Date : 19/12/2023
Problem : Rightmost different bit
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1
Video Solution : https://youtu.be/XisBExBWpWw

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
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        for(int i = 0; i < 32; i++){
            int x = (m >> i) & 1;
            int y = (n >> i) & 1;
            
            if(x != y)
                return i + 1;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends