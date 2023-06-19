/*

Author : Manas Rawat
Date : 12/03/2023
Problem : Binary matrix having maximum number of 1s
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/77e1c3e12cd148f835d53eb168d4472b2ff539fa/1
Video Solution : https://youtu.be/9cU_tIOFyb4

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        int maxCount, maxRow;
        maxCount = maxRow = 0;
        
        int currentRow = 0;
        for(int i = N - 1; i > - 1; i--){
            while(currentRow < N and mat[currentRow][i] != 1)
                ++currentRow;
                
            if(currentRow >= N)
                break;
                
            maxCount = N - i;
            maxRow = currentRow;
        }
        
        vector<int> ans = {maxRow, maxCount};
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends