/*

Author : Manas Rawat
Date : 07/04/2023
Problem : Add Minimum Characters
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/55dbfdc246f3f62d6a7bcee7664cacf6be345527/1
Video Solution : https://youtu.be/1Zfj8CIIqS4

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

vector<int> z_function_trivial(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1; i < n; ++i)
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
    return z;
}

class Solution{   
public:
    int addMinChar(string str){    
        string x, y;
        x = str;
        y = str;
        reverse(y.begin(), y.end());
        
        string t = x + "?" + y;
        
        vector<int> z = z_function_trivial(t);
        
        for(int i = str.size() + 1; i < z.size(); i++){
            int need = z.size() - i;
            
            if(z[i] == need){
                return i - str.size() - 1;
            }
        }
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends