/*

Author : Manas Rawat
Date : 13/04/2023
Problem : Partition the Array
Difficulty : Hard
Problem Link : https://practice.geeksforgeeks.org/problems/84912de770541b2a56bee869cf603fab990fd3e5/1
Video Solution : https://youtu.be/U5xkY-ugHvU

*/


//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long minDifference(int N, vector<int> &A) {
        vector<long long> prefix(N);
        
        prefix[0] = A[0];
        for(int i = 1; i < N; i++)
            prefix[i] = prefix[i - 1] + A[i];
            
        long long best = 1e18; 
        
        auto findSum = [&](long long left, long long right) -> long long {
            if(left == 0)
                return prefix[right];
                
            return prefix[right] - prefix[left - 1];
        };
        
        
        for(long long i = 1; i < N - 2; i++){
            long long p, q, r, s;
            
            long long low = 0;
            long long high = i;
            
            while(low < high - 1){
                long long mid = low + (high - low) / 2;
                
                if(findSum(0, mid) <= findSum(mid + 1, i))
                    low = mid;
                else
                    high = mid;
            }
            
            p = findSum(0, low);
            q = findSum(low + 1, i);
            
            long long pp, qq;
            pp = qq = 1e18;
            
            if(low < i - 1){
                pp = findSum(0, low + 1);
                qq = findSum(low + 2, i);
            }
            
            low = i + 1;
            high = N - 1;
            
            while(low < high - 1){
                long long mid = low + (high - low) / 2;
                
                if(findSum(i + 1, mid) <= findSum(mid + 1, N - 1))
                    low = mid;
                else
                    high = mid;
            }
            
            r = findSum(i + 1, low);
            s = findSum(low + 1, N - 1);
            
            long long rr, ss;
            rr = ss = 1e18;
            
            if(low < N - 2){
                rr = findSum(i + 1, low + 1);
                ss = findSum(low + 2, N - 1);
            }
             
            best = min(best, max({p, q, r, s}) - min({p, q, r, s}));
            if(pp != 1e18)
                best = min(best, max({pp, qq, r, s}) - min({pp, qq, r, s}));
            if(rr != 1e18)
                best = min(best, max({p, q, rr, ss}) - min({p, q, rr, ss}));
            if(pp != 1e18 and rr != 1e18)
                best = min(best, max({pp, qq, rr, ss}) - min({pp, qq, rr, ss}));
            
        }
        
        return best;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        long long ans = ob.minDifference(N, A);
        cout<<ans<<endl;
    }
    return 0;
} 
// } Driver Code Ends