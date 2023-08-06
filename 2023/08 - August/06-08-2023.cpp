/*

Author : Manas Rawat
Date : 06/08/2023
Problem : String Permutations
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string-1587115620/1
Video Solution : https://youtu.be/xLkDUPioP-M

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector<string> permutation(string S)
    {
        vector<string> ans;
        string cur = "";
        vector<bool> vis(S.size(), 0);
        
        function<void()> helper = [&]() {
            if(cur.size() == S.size()){
                ans.push_back(cur);
                return;
            }
            
            for(int i = 0; i < S.size(); i++){
                if(!vis[i]){
                    cur.push_back(S[i]);
                    vis[i] = 1;
                    helper();
                    vis[i] = 0;
                    cur.pop_back();
                }
            }
        };
        
        helper();
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends