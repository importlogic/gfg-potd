/*

Author : Manas Rawat
Date : 27/08/2023
Problem : Reverse a String
Difficulty : Basic
Problem Link : https://practice.geeksforgeeks.org/problems/reverse-a-string/1
Video Solution : https://youtu.be/hH-x23FCC5s

*/


//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    string reverseWord(string str)
    {
        for(int i = 0; i < str.size() / 2; i++){
            swap(str[i], str[str.size() - i - 1]);
        }
        
        return str;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends