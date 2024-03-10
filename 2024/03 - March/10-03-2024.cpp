/*

Author : Manas Rawat 
Date : 10/03/2024
Problem : Remove all duplicates from a given string
Difficulty : Easy 
Problem Link : https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    unordered_map<char, bool> f;
	    string ans = "";
	    
	    for(auto i : str){
	        if(f.find(i) == f.end()){
	            ans += i;
	            f[i] = 1;
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
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
