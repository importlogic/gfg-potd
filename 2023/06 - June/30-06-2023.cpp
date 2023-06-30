/*

Author : Manas Rawat
Date : 30/06/2023
Problem : Is Binary Number Multiple of 3
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/is-binary-number-multiple-of-30654/1
Video Solution : https://youtu.be/iEpCR-T9Fq0

*/


//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    int cur = 0;
	    
	    for(auto i : s){
	        cur = (cur * 2 + (i - '0')) % 3;
	    }
	    
	    return cur == 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends