/*

Author : Manas Rawat
Date : 09/06/2023
Problem : Permutations of a given string
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
Video Solution : https://youtu.be/-9C3ZDCGVhs

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    set<string> ans;
		    int n = S.size();
		    vector<bool> vis(n, 0);
		    
		    function<void(int, string)> traverse = [&](int p, string current) {
		        if(p == n){
		            ans.insert(current);
		            return;
		        }  
		        
		        for(int i = 0; i < n; i++){
		            if(!vis[i]){
		                vis[i] = 1;
		                current += S[i];
		                traverse(p + 1, current);
		                current.pop_back();
		                vis[i] = 0;
		            }
		        }
		    };
		    
		    traverse(0, "");
		    
		    vector<string> toreturn;
		    for(auto i : ans)
		        toreturn.push_back(i);
		    
		    return toreturn;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends