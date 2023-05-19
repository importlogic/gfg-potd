/*

Author : Manas Rawat
Date : 19/05/2023
Problem : Find k-th smallest element in given n ranges
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-given-n-ranges/1
Video Solution : https://youtu.be/FOm3yugop4I

*/


//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        sort(range.begin(), range.end());
        
        vector<int> ans(q);
        for(int p = 0; p < q; p++){
            int current = range[0][0];
            int pos = 1;
            
            for(int i = 0; i < n; i++){
                int need = queries[p] - pos;
                
                if(need and range[i][0] > current){
                    --need;
                    ++pos;
                    current = range[i][0];
                }
                
                int cango = range[i][1] - current;
                int change = min(cango, need);
                change = max(0, change);
                
                pos += change;
                current += change;
            }
            
            
            ans[p] = (pos == queries[p]) ? current : -1;
        }
        
        return ans;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends