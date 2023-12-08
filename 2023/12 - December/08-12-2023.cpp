/*

Author : Manas Rawat
Date : 08/12/2023
Problem : Transform to prime
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/transform-to-prime4635/1
Video Solution : https://youtu.be/cJABKOJLOj8

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool computed = 0;
vector<int> primes;

class Solution
{
    public:
    int minNumber(int arr[],int N)
    {
        if(!computed){
            vector<int> isPrime(1e6 + 10, 1);
            isPrime[0] = isPrime[1] = 0;
            
            for(int i = 2; i * i < 1e6 + 10; i++){
                if(isPrime[i]){
                    for(int j = i + i; j < 1e6 + 10; j += i)
                        isPrime[j] = 0;
                }
            }
            
            for(int i = 0; i < 1e6 + 10; i++)
                if(isPrime[i])
                    primes.push_back(i);
                    
            computed = 1;
        }
                
        int sum = 0;
        for(int i = 0; i < N; i++)
            sum += arr[i];
            
        auto p = lower_bound(primes.begin(), primes.end(), sum);
        
        return *p - sum;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends