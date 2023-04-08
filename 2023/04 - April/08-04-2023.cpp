/*

Author : Manas Rawat
Date : 08/04/2023
Problem : Make the array beautiful
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/badefd58bace4f2ca25267ccfe0c9dc844415e90/1
Video Solution : https://youtu.be/TWpqjSsEEIg

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int> st;
        
        for(auto i : arr){
            if(st.size() == 0)
                st.push(i);
            else if(st.top() < 0 ^ i < 0)
                st.pop();
            else
                st.push(i);
        }
        
        vector<int> ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
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

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends