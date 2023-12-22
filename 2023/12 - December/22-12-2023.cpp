/*

Author : Manas Rawat
Date : 22/12/2023
Problem : Maximum Meetings in One Room
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1
Video Solution : https://youtu.be/gZlCW3H4Rqc

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class meet {
    public:
    int start, end, index;
    
    meet(int a, int b, int c){
        start = a;
        end = b;
        index = c;
    }
};

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<meet> times;
        
        for(int i = 0; i < N; i++){
            times.emplace_back(meet(S[i], F[i], i + 1));
        }
        
        sort(times.begin(), times.end(), [](meet &a, meet &b){
            if(a.end == b.end){
                return a.index < b.index;
            }
            
            return a.end < b.end;
        });
        
        vector<int> ans;
        int lastEnd = -1;
        
        for(int i = 0; i < N; i++){
            if(times[i].start > lastEnd){
                ans.push_back(times[i].index);
                lastEnd = times[i].end;
            }    
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends