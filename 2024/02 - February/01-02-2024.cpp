/*

Author : Manas Rawat
Date : 01/02/2024
Problem : Panagram Checking
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1
Video Solution : https://youtu.be/MXys6geV9jQ

*/


//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        vector<int> f(26, 0);
        
        for(auto i : s){
            char cur = tolower(i);
            
            if(cur >= 'a' and cur <= 'z'){
                f[cur - 'a'] = 1;
            }
        }
            
        return accumulate(f.begin(), f.end(), 0) == 26;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends