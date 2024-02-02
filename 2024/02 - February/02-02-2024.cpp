/*

Author : Manas Rawat
Date : 02/02/2024
Problem : Implement Atoi
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/implement-atoi/1
Video Solution : https://youtu.be/LoBYi_Tzhso

*/


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int index = 0;
        int ans = 0;
        bool neg = 0;
        
        if(s[index] == '-'){
            neg = 1;
            ++index;
        }
        
        
        for(; index < s.size(); index++){
            if(isdigit(s[index])){
                ans *= 10;
                ans += (s[index] - '0');
            }
            else{
                return -1;
            }
        }
        
        return ans * (neg ? -1 : 1);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends