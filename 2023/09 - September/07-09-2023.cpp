/*

Author : Manas Rawat
Date : 07/09/2023
Problem : Minimum Multiplications to reach End
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
Video Solution : https://youtu.be/41kXuPbLqHU

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        const int mod = 1e5;
        
        vector<int> d(mod, 1e9);
        queue<int> q;
        q.push(start);
        d[start] = 0;
        
        if(start == end)
            return 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto i : arr){
                int child = (i * node) % mod;
                
                if(d[child] > d[node] + 1){
                    d[child] = d[node] + 1;
                    
                    if(child == end)
                        return d[child];
                        
                    q.push(child);
                }
            }
        }
        
        return -1;
    }
};



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
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends