/*

Author : Manas Rawat
Date : 25/09/2023
Problem : Maximum Sum Combination
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/maximum-sum-combination/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class node {
    public:
        int sum, i, j;
        
        node(int a, int b, int c){
            sum = a;
            i = b;
            j = c;
        };
};

class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end(), greater<>());
        sort(B.begin(), B.end(), greater<>());
        
        set<pair<int,int>> points;
        points.insert({0, 0});
        
        auto comp = [](node &a, node &b){
            return a.sum < b.sum;
        };
        
        priority_queue<node, vector<node>, decltype(comp)> pq(comp);
        node first(A[0] + B[0], 0, 0);
        pq.push(first);
        
        vector<int> ans;
        
        while(K--){
            node cur = pq.top();
            pq.pop();
            
            ans.push_back(cur.sum);
            
            if(!points.count({cur.i + 1, cur.j})){
                node newnode(A[cur.i + 1] + B[cur.j], cur.i + 1, cur.j);
                points.insert({cur.i + 1, cur.j});
                pq.push(newnode);
            }
            
            if(!points.count({cur.i, cur.j + 1})){
                node newnode(A[cur.i] + B[cur.j + 1], cur.i, cur.j + 1);
                points.insert({cur.i, cur.j + 1});
                pq.push(newnode);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends