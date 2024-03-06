/*

Author : Mrpankajpandey_
Date : 05/03/2024
Problem : Maximum Index
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/maximum-index-1587115620/1
Video Solution : NA

*/

//{ Driver Code Starts
// Driver Code

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        vector<int>preMin(n,0);
        vector<int>suffMax(n,0);

        int maxi=a[n-1];
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi, a[i]);
            suffMax[i]=maxi;
        }

        int mini=a[0];
        for(int i=0;i<n;i++){
            mini=min(mini, a[i]);
            preMin[i]=mini;
        }

        int i=0, j=0;
        int ans=-1;
        while(i<n && j<n){
            if(preMin[i]<=suffMax[j]){
                ans=max(ans, j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends
