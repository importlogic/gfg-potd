/*

Author : Manas Rawat
Date : 23/12/2023
Problem : Count More than n/k Occurences
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/count-element-occurences/1
Video Solution : https://youtu.be/ZKIP1GZwKSo

*/


//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        unordered_map<int, int> f;
        
        for(int i = 0; i < n; i++){
            ++f[arr[i]];
        }
        
        int ans = 0;
        
        for(auto i : f){
            ans += i.second > (n / k);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends