/*

Author : Manas Rawat
Date : 10/11/2023
Problem : Number following a pattern
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1
Video Solution : https://youtu.be/fPFaXJwTsLg

*/


//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        int n = s.size();
        
        int i = 0;
        
        string ans = "1";
        int cur = 2;
        
        while(i < n){
            if(s[i] == 'D'){
                int pos = i;
                while(pos < n and s[pos] == 'D')
                    ++pos;
                    
                int dx = pos - i;
                int nx = cur + dx - 1;
                
                ans.pop_back();
                
                while(nx >= cur - 1){
                    ans += to_string(nx);
                    --nx;
                }
                
                cur += dx;
                i += dx;
            }
            else{
                ans += to_string(cur);
                ++cur;
                ++i;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends