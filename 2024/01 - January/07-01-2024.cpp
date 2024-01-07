/*

Author : Manas Rawat
Date : 07/01/2024
Problem : Split Array Largest Sum
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1
Video Solution : https://youtu.be/-bg20RE63-k

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int N, int K) {
        int low = 0;
        int high = 0;
        
        for(int i = 0; i < N; i++)
            high += arr[i], low = max(low, arr[i] - 1);
            
        while(low < high - 1){
            int mid = low + (high - low) / 2;
            
            auto check = [&]() -> bool {
                int cuts = 0;
                
                int sum = 0;
                
                for(int i = 0; i < N; i++){
                    if(sum + arr[i] > mid){
                        ++cuts;
                        sum = arr[i];
                    }
                    else{
                        sum += arr[i];
                    }
                }
                
                return cuts < K;
            };
            
            if(check())
                high = mid;
            else
                low = mid;
        }
        
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends