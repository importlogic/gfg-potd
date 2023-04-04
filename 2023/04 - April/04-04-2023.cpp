/*

Author : Manas Rawat
Date : 04/04/2023
Problem : Minimum Steps Required
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/6a1b365b520f10c8a29b533eb72951b4b4237b57/1
Video Solution : https://youtu.be/HEuGRMU8dUk

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int cnta, cntb;
    cnta = cntb = 0;
    
    if(str[0] == 'a')
        ++cnta;
    else
        ++cntb;
        
    for(int i = 1; i < str.size(); i++){
        if(str[i] == str[i - 1])
            continue;
        
        if(str[i] == 'a')
            ++cnta;
        else
            ++cntb;
    }
    
    return min(cnta, cntb) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends