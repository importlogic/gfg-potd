/*

Author : Manas Rawat
Date : 23/06/2023
Problem : Task Scheduler
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/task-scheduler/1
Video Solution : https://youtu.be/Qzfd3hxS3Gs

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        vector<int> f(26, 0);
        
        for(auto i : tasks)
            ++f[i - 'A'];
            
        int nax = -1;
        int count = 0;
        
        for(int i = 0; i < 26; i++){
            if(f[i] == nax)
                ++count;
            else if(f[i] > nax){
                nax = f[i];
                count = 1;
            }
        }
        
        int ans = max(N, nax + (nax - 1) * K + count - 1);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends