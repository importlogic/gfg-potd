/*

Author : Mrpankajpandey_
Date : 29/02/2024
Problem : Sum of bit differences
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/sum-of-bit-differences2937/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	     long long hai=0,nhiHai=0,ans=0,num=1;
	    for(int i=0;i<21;i++){
	        for(int j=0;j<n;j++){
	            if(arr[j]&num)hai++;
	            else nhiHai++;
	        }
	        ans+=2*hai*nhiHai;
	        num<<=1;
	        hai=0;
	        nhiHai=0;
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
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends