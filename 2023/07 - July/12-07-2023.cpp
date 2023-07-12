/*

Author : Manas Rawat
Date : 12/07/2023
Problem : Power Of Numbers
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1
Video Solution : https://youtu.be/cIuMpX_VThE

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(long long N, long long R)
    {
        const int mod = 1e9 + 7;
        long long ans = 1;
        
        while(R){
            if(R & 1)
                ans = (ans * N) % mod;
                
            N = (N * N) % mod; 
                
            R >>= 1;
        }
        
        return ans;
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends