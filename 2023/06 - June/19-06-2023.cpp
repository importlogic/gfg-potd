/*

Author : Manas Rawat
Date : 19/06/2023
Problem : Rearrange an array with O(1) extra space
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/1
Video Solution : https://youtu.be/1Lm_Uc5LqvU

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        for(int i = 0; i < n; i++){
            long long need = arr[arr[i]];
            for(int j = 0; j < 17; j++){
                if((need >> j) & 1)
                    arr[i] |= (1LL << (j + 17));
            }
        }
        
        for(int i = 0; i < n; i++)
            arr[i] >>= 17;
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin>>t;
    while(t--){
        
        int n;
        //size of array
        cin>>n;
        long long A[n];
        
        //adding elements to the array
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        Solution ob;
        //calling arrange() function
        ob.arrange(A, n);
        
        //printing the elements 
        for(int i=0;i<n;i++){
            cout << A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends