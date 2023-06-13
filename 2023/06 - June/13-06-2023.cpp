/*

Author : Manas Rawat
Date : 13/06/2023
Problem : k largest elements
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1
Video Solution : https://youtu.be/0vd8eZUoLr0

*/


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int, vector<int>, greater<int>> pq;
	    
	    for(int i = 0; i < k; i++)
	        pq.push(arr[i]);
	        
	    for(int i = k; i < n; i++){
	        if(arr[i] > pq.top()){
	            pq.pop();
	            pq.push(arr[i]);
	        }
	    }
	    
	    vector<int> ans(k);
	    for(int i = k - 1; i > -1; i--){
	        ans[i] = pq.top();
	        pq.pop();
	    }
	    
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends