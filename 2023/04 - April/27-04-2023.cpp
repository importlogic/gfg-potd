/*

Author : Manas Rawat
Date : 27/04/2023
Problem : Easy Task
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/c928f229cc972671d91c5e9f6b222414912cc88a/1
Video Solution : https://youtu.be/TPPDHpTEk08

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        vector<vector<int>> tree(4 * n, vector<int> (26));
        
        function<void(int, int, int)> build = [&](int node, int low, int high){
            if(low == high){
                vector<int> f(26, 0);
                ++f[s[low - 1] - 'a'];
                tree[node] = f;
                return;
            }
        
            int mid = low + (high - low) / 2;
            build(2 * node, low, mid);
            build(2 * node + 1, mid + 1, high);
            
            for(int i = 0; i < 26; i++)
                tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
        };
        
        function<void(int, int, int, int, int, int)> update = [&](int node, int low, int high, int rangelow, int rangehigh, char dx){
            if(low > rangehigh or high < rangelow)
                return;
        
            if(low >= rangelow and high <= rangehigh){
                vector<int> f(26, 0);
                ++f[dx - 'a'];
                tree[node] = f;
                
                return;
            }
        
            int mid = low + (high - low) / 2;
        
            update(2 * node, low, mid, rangelow, rangehigh, dx);
            update(2 * node + 1, mid + 1, high, rangelow, rangehigh, dx);
            
            for(int i = 0; i < 26; i++)
                tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
        };
        
        function<vector<int>(int, int, int, int, int)> query = [&](int node, int low, int high, int rangelow, int rangehigh) -> vector<int> {
            vector<int> f(26, 0);
            
            if(low > rangehigh or high < rangelow)
                return f;
        
            if(low >= rangelow and high <= rangehigh)
                return tree[node];
        
            int mid = low + (high - low) / 2;
        
            vector<int> x = query(2 * node, low, mid, rangelow, rangehigh);
            vector<int> y = query(2 * node + 1, mid + 1, high, rangelow, rangehigh);
            
            for(int i = 0; i < 26; i++)
                f[i] = x[i] + y[i];
        
            return f;
        };
        
        build(1, 1, n);
        
        vector<char> ans;
        
        for(int i = 0; i < q; i++){
            int ch = stoi(queries[i][0]);
            
            if(ch == 1){
                int index = stoi(queries[i][1]);
                ++index;
                
                char c = queries[i][2][0];
                
                update(1, 1, n, index, index, c);
            }
            else{
                int l, r, k;
                l = stoi(queries[i][1]);
                r = stoi(queries[i][2]);
                k = stoi(queries[i][3]);
                
                ++l; ++r;
                
                vector<int> f = query(1, 1, n, l, r);
                
                int count = 0;
                for(int i = 25; i > -1; i--){
                    count += f[i];
                    
                    if(count >= k){
                        ans.push_back((char)(i + 'a'));
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends