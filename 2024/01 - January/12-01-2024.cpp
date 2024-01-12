/*

Author : Manas Rawat
Date : 12/01/2024
Problem : Reverse First K elements of Queue
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
Video Solution : NA

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        queue<int> q2;
        stack<int> s;
        
        int n = q.size();
        
        for(int i = 0; i < n; i++){
            if(i < k)
                s.push(q.front());
            else
                q2.push(q.front());
                
            q.pop();
        }
        
        while(s.size()){
            q.push(s.top());
            s.pop();
        }
        
        while(q2.size()){
            q.push(q2.front());
            q2.pop();
        }
        
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends