/*

Author : Manas Rawat
Date : 03/11/2023
Problem : Pythagorean Triplet
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	int findroot(int n){
	    int low = 1;
	    int high = n;
	    
	    while(low < high - 1){
	        int mid = low + (high - low) / 2;
	        
	        if(mid * mid > n)
	            high = mid;
	        else
	            low = mid;
	    }
	    
	    return low;
	}
	
	bool checkTriplet(int arr[], int n) {
	    int MAX = *max_element(arr, arr + n);
	    
	    vector<int> f(MAX + 1, 0);
	    
	    for(int i = 0; i < n; i++)
	        ++f[arr[i]];
	        
	    for(int i = 1; i < MAX + 1; i++){
	        for(int j = 1; j < MAX + 1; j++){
	            int sq = i * i + j * j;
	            int k = findroot(sq);
	            
	            if(k > MAX or k * k != sq)
	                continue;
	            
	            --f[i];
	            --f[j];
	            --f[k];
	            
	            if(f[i] >= 0 and f[j] >= 0 and f[k] >= 0){
	                return 1;
	            }
	            
	            ++f[i];
	            ++f[j];
	            ++f[k];
	        }
	    }
	    
	    return 0;
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
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends