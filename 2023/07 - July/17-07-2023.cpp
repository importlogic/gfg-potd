/*

Author : Manas Rawat
Date : 17/07/2023
Problem : First non-repeating character in a stream
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
Video Solution : https://youtu.be/dClj1JrcMsM

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    queue<char> q;
		    vector<int> f(26, 0);
		    string ans = "";
		    
		    for(auto i : A){
		        ++f[i - 'a'];
		        
		        if(f[i - 'a'] == 1)
		            q.push(i);
		            
		        while(q.size() and f[q.front() - 'a'] > 1)
		            q.pop();
		            
		        if(q.size())
		            ans += q.front();
		        else
		            ans += '#';
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends