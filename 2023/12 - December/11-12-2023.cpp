/*

Author : Manas Rawat
Date : 11/12/2023
Problem : Max Sum Subarray of size K
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
Video Solution : https://youtu.be/DlmwTN6sFig

*/


//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long long sum = 0;
        long long best = 0;
        
        for(int i = 0; i < K; i++)
            sum += Arr[i];
            
        best = sum;
        
        for(int i = K; i < N; i++){
            sum -= Arr[i - K];
            sum += Arr[i];
            
            best = max(best, sum);
        }
        
        return best;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends