/*

Author : Manas Rawat 
Date : 26/02/2024
Problem : Power Set
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/power-set4302/1
Video Solution : NA

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    string cur = "";
		    
		    function<void(int)> sub = [&](int p) {
		        if(p == s.size()){
		            if(cur.size())
    		            ans.push_back(cur);
		            return;
		        }
		        
		        cur.push_back(s[p]);
		        sub(p + 1);
		        cur.pop_back();
		        sub(p + 1);
		    };
		    
		    sub(0);
		    
		    sort(ans.begin(), ans.end());
		    
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
