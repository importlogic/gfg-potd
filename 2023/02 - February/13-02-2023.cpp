/*

Author : Manas Rawat
Date : 13/02/2023
Problem : Arithmetic Number
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1
Video Solution : https://youtu.be/ZzFrr6kKK5I

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        int x = B - A;
        
        if(C == 0) return A == B;
        
        bool conditionOne = x / C * C == x; //checking if x / C is a whole number
        bool conditionTwo = x / C + 1 > 0; // n > 0
        
        return conditionOne and conditionTwo;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends