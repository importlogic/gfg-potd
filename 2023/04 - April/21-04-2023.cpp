/*

Author : Manas Rawat
Date : 21/04/2023
Problem : Prefix Suffix String
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/5be83263c7f2cb866c60b23b73bb38f88de2461c/1
Video Solution : https://youtu.be/m0Eh1DOjMOQ

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

struct trieNode{
    vector<trieNode*> next = vector<trieNode*> (26, nullptr);
};

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> &s2){
        trieNode * root = new trieNode;
        
        function<void(string &)> build = [&](string &s) {
            trieNode * current = root;
            
            for(int i = 0; i < s.size(); i++){
                char nextChar = s[i];
                trieNode * nextNode;
                
                if(current -> next[nextChar - 'a'] == nullptr){
                    nextNode = new trieNode;
                    current -> next[nextChar - 'a'] = nextNode;
                }
                else{
                    nextNode = current -> next[nextChar - 'a'];
                }
                
                current = nextNode;
            }
        };
        
        for(auto &current : s1){
            build(current);
            reverse(current.begin(), current.end());
            build(current);
        }
        
        int ans = 0;
        
        function<bool(string &)> check = [&](string &s) -> bool {
            trieNode * current = root;
            
            int index = 0;
            
            while(index < s.size()){
                char nextChar = s[index];
                
                if(current -> next[nextChar - 'a'] == nullptr)
                    break;
                    
                current = current -> next[nextChar - 'a'];
                
                ++index;
            }
            
            return index == s.size();
        };
        
        for(auto &s : s2){
            bool ok = check(s);
            reverse(s.begin(), s.end());
            ok |= check(s);
            
            ans += ok;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends