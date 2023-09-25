/*

Author : Manas Rawat
Date : 23/09/2023
Problem : Equilibrium Point
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        if(n == 1)
            return 1;
    
        vector<int> pre(n), suf(n);
        pre[0] = a[0];
        suf[n - 1] = a[n - 1];
        
        for(int i = 1; i < n; i++){
            pre[i] = pre[i - 1] + a[i];
            suf[n - i - 1] = suf[n - i] + a[n - i - 1];
        }

        for(int i = 1; i < n - 1; i++){
            if(pre[i - 1] == suf[i + 1])
                return i + 1;
        }
        
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends