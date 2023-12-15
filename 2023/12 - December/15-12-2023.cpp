/*

Author : Manas Rawat
Date : 15/12/2023
Problem : Reach the Nth point
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/reach-the-nth-point5433/1
Video Solution : https://youtu.be/nOZd178Lu0I

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		    long long a, b;
		    a = b = 1;
		    
		    const long long mod = 1e9 + 7;
		    
		    for(int i = 1; i < n; i++){
		        long long c = (a + b) % mod;
		        a = b;
		        b = c;
		    }
		    
		    return b;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends