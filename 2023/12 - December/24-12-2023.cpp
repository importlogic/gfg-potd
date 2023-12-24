/*

Author : Manas Rawat
Date : 24/12/2023
Problem : Buy Maximum Stocks if i stocks can be bought on i-th day
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1
Video Solution : https://youtu.be/NzVwWYiA7nY

*/


//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>> info(n);
        
        for(int i = 0; i < n; i++){
            info[i].first = price[i];
            info[i].second = i + 1;
        }
        
        sort(info.begin(), info.end());
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int qty = k / info[i].first;
            qty = min(qty, info[i].second);
            
            ans += qty;
            k -= qty * info[i].first;
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
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends