/*

Author : Manas Rawat
Date : 29/12/2023
Problem : Check if a string is repetition of its substring of k-length
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/check-if-a-string-is-repetition-of-its-substring-of-k-length3302/1
Video Solution : https://youtu.be/MdRdgnTwrck

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    if(n % k)
	        return 0;
	        
	    map<vector<int>, int> substr;
	    
	    vector<int> f(26, 0);
	    
	    for(int i = 0; i < n; i += k){
	        for(int j = i - k; j < i and j > -1; j++)
	            --f[s[j] - 'a'];
	        for(int j = i; j < i + k; j++)
	            ++f[s[j] - 'a'];
	        
	        substr[f]++;
	        
	        if(substr.size() > 2)
	            return 0;
	    }
	    
	    int freq = (*substr.begin()).second;
	    
	    return (freq == 1 or freq >= n / k - 1);
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends