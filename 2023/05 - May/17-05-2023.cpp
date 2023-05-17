/*

Author : Manas Rawat
Date : 17/05/2023
Problem : Trace Path
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/trace-path3840/1
Video Solution : https://youtu.be/vdF2VghKq6U

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int dx, dy;
        dx = dy = 0;
        
        int maxx, minx, maxy, miny;
        maxx = maxy = minx = miny = 0;
        
        for(auto i : s){
            if(i == 'L'){
                --dy;
            }
            else if(i == 'R'){
                ++dy;
            }
            else if(i == 'D'){
                --dx;
            }
            else{
                ++dx;
            }
            
            maxx = max(dx, maxx);
            maxy = max(dy, maxy);
            
            minx = min(dx, minx);
            miny = min(dy, miny);
            
            if(maxx - minx >= n or maxy - miny >= m)
                return 0;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends