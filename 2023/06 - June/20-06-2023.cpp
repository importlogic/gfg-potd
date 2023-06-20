/*

Author : Manas Rawat
Date : 20/06/2023
Problem : Matchsticks game
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/-matchsticks-game4906/1
Video Solution : https://youtu.be/7czmPnMeO9g

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int matchGame(long long N) {
        if(N % 5 == 0)
            return -1;
        else
            return N % 5;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.matchGame(N) << endl;
    }
    return 0;
}
// } Driver Code Ends