/*

Author : Manas Rawat
Date : 03/05/2023
Problem : Make Palindrome
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/8d0e8785cef59cf4903b926ceb7100bcd16a9835/1
Video Solution : https://youtu.be/u4RYqEsfJt0

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        map<string, int> need;
        
        for(auto current : arr){
            if(need.find(current) != need.end()){
                if(need[current]){
                    --need[current];
                    continue;
                }
            }
                
            string rev = current;
            reverse(rev.begin(), rev.end());
            ++need[rev];
        }
        
        bool ok = 1;
        for(auto i : need){
            if(i.second > 0){
                if(ok){
                    string current = i.first;
                    string rev = current;
                    
                    reverse(rev.begin(), rev.end());
                    
                    if(rev != current)
                        return 0;
                        
                    ok = 0;
                }
                else
                    return 0;
            }
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends