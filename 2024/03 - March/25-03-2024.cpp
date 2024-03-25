/*

Author : Manas Rawat 
Date : 25/03/2024
Problem : Print N-bit binary numbers having more 1s than 0s
Difficulty : Medium 
Problem Link : https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<string> NBitBinary(int n)
	{
	    vector<string> ans;
	    string cur = "";
	    
	    function<void(int, int)> permute = [&](int p, int c) {
	        if(c < p - c) 
	            return;
	            
	        if(p == n){
                ans.push_back(cur);
	            return;
	        }  
	        
	        cur.push_back('1');
	        permute(p + 1, c + 1);
	        cur.pop_back();
	        cur.push_back('0');
	        permute(p + 1, c);
	        cur.pop_back();
	    };
	    
	    permute(0, 0);
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends
