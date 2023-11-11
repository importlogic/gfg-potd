/*

Author : Manas Rawat
Date : 11/11/2023
Problem : Isomorphic Strings
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1
Video Solution : https://youtu.be/bDzAcPyfw30

*/


//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.size() != str2.size())
            return 0;
        
        // a is going to store mapping for str1
        // b is going to store mapping for str2
        vector<int> a(26, -1), b(26, -1);
        
        int n = str1.size();
        
        for(int i = 0; i < n; i++){
            if(a[str1[i] - 'a'] != -1){
                int x = a[str1[i] - 'a'];
                
                if(x != str2[i] - 'a')
                    return 0;
            }
            
            if(b[str2[i] - 'a'] != -1){
                int x = b[str2[i] - 'a'];
                
                if(x != str1[i] - 'a')
                    return 0;
            }
            
            a[str1[i] - 'a'] = str2[i] - 'a';
            b[str2[i] - 'a'] = str1[i] - 'a';
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends