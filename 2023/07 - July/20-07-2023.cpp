/*

Author : Manas Rawat
Date : 20/07/2023
Problem : Non Repeating Character
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/non-repeating-character-1587115620/1
Video Solution : https://youtu.be/E4IipZ3AANI

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        unordered_map<int, int> f;
        queue<char> q;
        
        for(auto i : S){
            ++f[i];
            
            if(f[i] == 1)
                q.push(i);
                
            while(q.size() and f[q.front()] > 1)
                q.pop();
        }
        
        return q.size() ? q.front() : '$';
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends