/*

Author : Manas Rawat
Date : 11/03/2023
Problem : Yet another query problem
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/ad6699d4aaf84c74b119fac3b65e9ceb3fc8ef14/1
Video Solution : https://youtu.be/JJBLP_13Xp0

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        vector<int> freq(1e5 + 10, 0);
        vector<int> suffix(N), ans(num);
        
        for(int i = N - 1; i > -1; i--)
            suffix[i] = ++freq[A[i]];
            
        for(int i = 0; i < num; i++){
            int l, r, k;
            l = Q[i][0];
            r = Q[i][1];
            k = Q[i][2];
            
            int count = 0;
            for(int j = l; j < r + 1; j++)
                count += suffix[j] == k;
                
            ans[i] = count;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends