#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution{
public:
    int nextHappy(int n){
        n++;
        while(n<=1e5){
            if(solve(n)) return n; 
            n++;
        }
        return -1;
    }
    bool solve(int n){
        //2 -> 4, 3 -> 4, 4 -> 4, 5 -> 4, 6 -> 4 , 8 ->4 , 9 -> 4
        if(n == 2 || n==3 || n==4 || n==5 || n==6 || n==8 || n==9) return false;
        if( n == 1||n==7) return true; // 1 returns 1, 7 returns 1 too
        int sum=0;
        while(n > 0){
            sum+=((n%10)*(n%10));
            n=n/10;
        }
        if(solve(sum)) return true; 
        return false;
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
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
