/*

Author : Manas Rawat
Date : 04/06/2023
Problem : Reversing the equation
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/reversing-the-equation2205/1
Video Solution : https://youtu.be/3KZWXbz5luQ

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            vector<string> eq;
            
            string current = "";
            
            for(auto i : s){
                if(isdigit(i))
                    current += i;
                else{
                    if(current != "")
                        eq.push_back(current);
                    string t = "";
                    t += i;
                    eq.push_back(t);
                    current = "";
                }
            }
            
            if(current != "")
                eq.push_back(current);
                
            reverse(eq.begin(), eq.end());
            
            string ans = "";
            
            for(auto i : eq)
                for(auto j : i)
                    ans += j;
                    
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends