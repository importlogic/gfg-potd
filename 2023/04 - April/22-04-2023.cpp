/*

Author : Manas Rawat
Date : 22/04/2023
Problem : Smaller Sum
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/5877fde1c8e1029658845cd4bc94066ac1d4b09b/1
Video Solution : https://youtu.be/oVk5NEWSqjg

*/


//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<pair<int,int>> input(n + 1);
        vector<long long> pre(n + 1);
        
        pre[0] = 0;
        input[0] = {-10, -10};
        
        for(int i = 1; i < n + 1; i++){
            input[i].first = arr[i - 1];
            input[i].second = i - 1;
        }
        
        sort(input.begin(), input.end());
        
        for(int i = 1; i < n + 1; i++){
            pre[i] = pre[i - 1] + input[i].first;
        }
        
        vector<long long> ans(n);
        
        for(int i = 1; i < n + 1; i++){
            auto pos = lower_bound(input.begin(), input.end(), make_pair(input[i].first, -1)) - input.begin();
            --pos;
            
            ans[input[i].second] = pre[pos];
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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends