/*

Author : Manas Rawat
Date : 14/08/2023
Problem : Non Repeating Numbers
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1
Video Solution : https://youtu.be/e3HsrtMYeZc

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int value = 0;
        for(auto i : nums)
            value ^= i;
        
        int rightmost = (value & (value - 1)) ^ value;
        
        vector<int> ans(2, 0);
        
        for(auto i : nums){
            if(i & rightmost)
                ans[0] ^= i;
            else
                ans[1] ^= i;
        }
        
        if(ans[0] > ans[1])
            swap(ans[0], ans[1]);
            
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends