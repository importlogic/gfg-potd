/*

Author : Manas Rawat
Date : 22/06/2023
Problem : Lemonade Change
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/lemonade-change/1
Video Solution : https://youtu.be/kXbw6y19ND0

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        vector<int> f(3, 0);
        
        for(auto i : bills){
            if(i == 5)
                ++f[0];
            else if(i == 10){
                if(f[0])
                    --f[0];
                else
                    return 0;
                    
                ++f[1];
            }
            else if(i == 20){
                if(f[1] and f[0])
                    --f[0], --f[1];
                else if(f[0] > 2)
                    f[0] -= 3;
                else
                    return 0;
                    
                ++f[2];
            }
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends