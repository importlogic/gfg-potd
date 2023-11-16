/*

Author : Manas Rawat
Date : 16/11/2023
Problem : Find the String
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/find-the-string/1
Video Solution : https://youtu.be/5cGcJ3DmAa8

*/


//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    string findString(int n, int k) {
        set<string> vis;
        
        string start = "";
        for(int i = 0; i < n; i++)
            start += '0';
        
        string ans = start;
        
        function<void(string &)> dfs = [&](string &node) {
            vis.insert(node);
            string nextS = node.substr(1);
            
            for(int i = k - 1; i > -1; i--){
                string child = nextS + to_string(i);
                
                if(!vis.count(child)){
                    ans += to_string(i);
                    dfs(child);
                }
            }
        };
        
        dfs(start);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
} 
// } Driver Code Ends