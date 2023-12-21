/*

Author : Manas Rawat
Date : 21/12/2023
Problem : Candy
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/candy/1
Video Solution : https://youtu.be/bqWHPw1S57c

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        vector<int> ans(N, 1);
        
        for(int i = 1; i < N; i++){
            if(ratings[i] > ratings[i - 1])
                ans[i] = max(ans[i], ans[i - 1] + 1);
        }
        
        for(int i = N - 2; i > -1; i--){
            if(ratings[i] > ratings[i + 1])
                ans[i] = max(ans[i], ans[i + 1] + 1);
        }
        
        return accumulate(ans.begin(), ans.end(), 0LL);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends