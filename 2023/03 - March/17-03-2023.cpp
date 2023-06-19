/*

Author : Manas Rawat
Date : 17/03/2023
Problem : Number of Subarrays of 0's
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/0960a833f70b09c59444ea487f99729929fc8910/1
Video Solution : https://youtu.be/H_1y6dvtYTQ

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
    long long ans, count;
    ans = count = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            ans += ((count + 1) * count) / 2;
            count = 0;
        }
        else{
            ++count;
        }
    }
    
    ans += ((count + 1) * count) / 2;
    
    return ans;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends