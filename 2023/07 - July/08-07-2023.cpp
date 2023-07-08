/*

Author : Manas Rawat
Date : 08/07/2023
Problem : Find triplets with zero sum
Difficulty : Basic
Problem Link : https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1
Video Solution : https://youtu.be/Bia9scDVvY8

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr, arr + n);
        
        for(int k = 0; k < n; k++){
            int i = 0;
            int j = n - 1;
            
            if(i == k)
                ++i;
            if(j == k)
                --j;
                
            while(i < j){
                if(arr[i] + arr[j] + arr[k] > 0)
                    --j;
                else if(arr[i] + arr[j] + arr[k] < 0)
                    ++i;
                else
                    return 1;
                    
                if(i == k)
                    ++i;
                if(j == k)
                    --j;                    
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends