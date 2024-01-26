/*

Author : Manas Rawat
Date : 26/01/2024
Problem : Fractional Knapsack
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
Video Solution : https://youtu.be/hPweXx6sbN8

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double, int>> items;
        
        for(int i = 0; i < n; i++){
            double value_per_weight = (double)arr[i].value / (double)arr[i].weight;
            
            items.emplace_back(value_per_weight, arr[i].weight);
        }
        
        sort(items.begin(), items.end(), [](pair<double, int> &a, pair<double, int> &b){
            return a.first > b.first; 
        });
        
        double ans = 0;
        
        for(int i = 0; i < n; i++){
            int take_weight = min(W, items[i].second);
            W -= take_weight;
            ans += take_weight * items[i].first;
        }
        
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends