/*

Author : Manas Rawat
Date : 18/02/2023
Problem : Apple Sequences
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/38f100615d0b2efa755e7b07f905e0f8cd2fe5df/1
Video Solution : https://youtu.be/Cyc9CsNh8Rc

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        int l = 0;
        int h = n + 1;
        
        while(l < h - 1){
            int mid = l + (h - l) / 2;
            
            bool found = 0;
            int cntA = 0;
            
            for(int i = 0; i < mid; i++) cntA += arr[i] == 'A';
            
            if(cntA + min(mid - cntA, m) == mid) {
                found = 1;
            }
            
            for(int i = mid; i < n; i++){
                cntA += arr[i] == 'A';
                cntA -= arr[i - mid] == 'A';
                
                
                if(cntA + min(mid - cntA, m) == mid){
                    found = 1;
                    break;
                }
            }
            
            
            if(found) l = mid;
            else h = mid;
        }
        
        return l;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends