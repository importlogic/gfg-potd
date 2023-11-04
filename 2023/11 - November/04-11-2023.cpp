/*

Author : Manas Rawat
Date : 04/11/2023
Problem : Find Transition Point
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/find-transition-point-1587115620/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) {
        if(arr[0] == 1)
            return 0;
            
        int low = 0;
        int high = n;
        
        while(low < high - 1){
            int mid = low + (high - low) / 2;
            
            if(arr[mid] == 0)
                low = mid;
            else
                high = mid;
        }
        
        return high == n ? -1 : high;
    }
};

//{ Driver Code Starts.
int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends