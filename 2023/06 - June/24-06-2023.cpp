/*

Author : Manas Rawat
Date : 24/06/2023
Problem : Prefix match with other strings
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/prefix-match-with-other-strings/1
Video Solution : https://youtu.be/44CdVQ7pq9U

*/


//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        int count = 0;
        for(int i = 0; i < n; i++){
            int ok = 1;
            for(int j = 0; j < k; j++){
                if(arr[i][j] != str[j])
                    ok = 0;
            }
            
            count += ok;
        }
        
        return count;
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
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends