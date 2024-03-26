/*

Author : Manas Rawat 
Date : 26/03/2024
Problem : Additive sequence
Difficulty : Medium 
Problem Link : https://www.geeksforgeeks.org/problems/additive-sequence/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool isAdditiveSequence(string str) {
        int n = str.size();
        if(n<3)
            return 0;
            
        string ans,s1;
        
        for(int i=0;i<min(n-1,10);i++){
            s1.push_back(str[i]);
            string s2 = "";
            for(int j=i+1;j<min(n,10);j++){
                s2.push_back(str[j]);
                ans = s1+s2;
                int a = stoi(s1);
                int b = stoi(s2);
                while(ans.size()<n){
                    int sum = a+b;
                    string s = to_string(sum);
                    if(n-ans.size() < s.size())
                        break;
                    ans += s;
                    a=b;
                    b=sum;
                    if(ans == str)
                        return 1;
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends
