/*

Author : Manas Rawat
Date : 02/11/2023
Problem : Minimum distance between two numbers
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/minimum-distance-between-two-numbers/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        int last = -1;
        int pos = -1;
        int ans = 1e9;
        
        for(int i = 0; i < n; i++){
            if(a[i] == x){
                if(last == y)
                    ans = min(ans, i - pos);
                
                last = x;
                pos = i;
            }
            else if(a[i] == y){
                if(last == x)
                    ans = min(ans, i - pos);
                    
                last = y;
                pos = i;
            }
        }
        
        return ans == 1e9 ? -1 : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends