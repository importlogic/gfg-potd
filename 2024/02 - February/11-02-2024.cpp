/*

Author : Manas Rawat
Date : 11/02/2024
Problem : Recamans sequence
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/recamans-sequence4856/1
Video Solution : https://youtu.be/qywWZ6zwztE

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        vector<int> ans = {0};
        unordered_set<int> included;
        
        for(int i = 1; i < n; i++){
            int add, sub;
            add = ans.back() + i;
            sub = ans.back() - i;
            
            if(sub > 0 and (included.find(sub) == included.end())){
                ans.push_back(sub);
                included.insert(sub);
            }
            else{
                ans.push_back(add);
                included.insert(add);
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
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends