/*

Author : Manas Rawat
Date : 09/11/2023
Problem : Predict the Column
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/predict-the-column/1
Video Solution : https://youtu.be/gxdkI19HHKA

*/


//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    /*Function to count zeros in each column
    * N : Number of rows and columns in array
    M is the matrix that is globally declared
    */
    int columnWithMaxZeros(vector<vector<int>>arr,int N){
        int best = 0;
        int ans = -1;
        
        for(int j = 0; j < N; j++){
            int cur = 0;
            
            for(int i = 0; i < N; i++)
                cur += arr[i][j] == 0;
                
            if(cur > best){
                best = cur;
                ans = j;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    vector<vector<int>>arr(N,vector<int>(N));
	    // Taking elements input into the matrix
	    for(int i = 0;i<N;i++){
	        for(int j = 0;j<N;j++){
	            int x;
	            cin >> x; 
	            arr[i][j]=x;
	        }
	    }
	    Solution ob;
	    cout << ob.columnWithMaxZeros(arr,N) << endl;
	}
	
	return 0;
}
// } Driver Code Ends