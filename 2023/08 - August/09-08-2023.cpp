/*

Author : Manas Rawat
Date : 09/08/2023
Problem : Largest prime factor
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/largest-prime-factor2601/1
Video Solution : https://youtu.be/RVa7siUvzxs

*/


//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        int ans;
        
        for(int i = 2; i * i <= N; i++){
            if(N % i == 0){
                ans = i;
                while(N % i == 0){
                    N /= i;
                }
            }    
        }
        
        if(N > 1)
            ans = max(ans, N);
            
            
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
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends