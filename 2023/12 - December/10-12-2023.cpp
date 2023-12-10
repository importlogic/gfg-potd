/*

Author : Manas Rawat
Date : 10/12/2023
Problem : Subarray with 0 sum
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
Video Solution : https://youtu.be/odoutOKQY2M

*/


//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int, int> found;
        found[0] = 1;
        
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            if(found.count(sum))
                return 1;
                
            ++found[sum];
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends