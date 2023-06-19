/*

Author : Manas Rawat
Date : 07/05/2023
Problem : String Mirror
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/d385b9d635b7b10eef6bf365b84922aaeec9eb98/1
Video Solution : https://youtu.be/rUVBSdmqGHE

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        int index = 1;
        while(index < str.size() and str[index] <= str[index - 1])
            ++index;
        
        
        string ans = "";
        for(int i = 0; i < index; i++)
            ans += str[i];
            
        string y = ans;
        reverse(y.begin(), y.end());
        
        ans += y;
        
        string ans2 = "";
        ans2 += str[0];
        ans2 += str[0];
        
        return min(ans, ans2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends