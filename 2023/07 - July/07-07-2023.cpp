/*

Author : Manas Rawat
Date : 07/07/2023
Problem : Merge Without Extra Space
Difficulty : Hard
Problem Link : https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
Video Solution : https://youtu.be/s2S4vQeW79A

*/


//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i, j, k;
            i = j = k = 0;
            
            long long base = 1;
            
            for(int i = 0; i < 24; i++){
                base <<= 1;
                ++base;
            }
            
            while(i < n and j < m){
                long long newVal;
                
                long long x, y;
                x = (arr1[i] & base);
                y = (arr2[j] & base);
                
                if(x < y)
                    newVal = x << 30, ++i;
                else
                    newVal = y << 30, ++j;
                    
                if(k < n)
                    arr1[k++] |= newVal;
                else
                    arr2[k++ - n] |= newVal;
            }
            
            while(i < n){
                long long newVal = (arr1[i++] & base) << 30;
                if(k < n)
                    arr1[k++] |= newVal;
                else
                    arr2[k++ - n] |= newVal;
            }
            
            while(j < m){
                long long newVal = (arr2[j++] & base) << 30;
                if(k < n)
                    arr1[k++] |= newVal;
                else
                    arr2[k++ - n] |= newVal;
            }
            
            for(int i = 0; i < n; i++)
                arr1[i] >>= 30;
            for(int i = 0; i < m; i++)
                arr2[i] >>= 30;
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends