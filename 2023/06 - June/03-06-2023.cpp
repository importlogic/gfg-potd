/*

Author : Manas Rawat
Date : 03/06/2023
Problem : Find Maximum Equal sum of Three Stacks
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/find-maximum-equal-sum-of-three-stacks/1
Video Solution : https://youtu.be/VqJb_NLgPlk

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int x, y, z;
        x =  y = z = 0;
        
        for(auto i : S1)
            x += i;
        for(auto i : S2)
            y += i;
        for(auto i : S3)
            z += i;
            
        int i, j, k;
        i = j = k = 0;
        
        while(i < N1 and j < N2 and k < N3){
            if(x == y and y == z)
                return x;
                
            if(x > y or x > z)
                x -= S1[i++];
            if(y > x or y > z)
                y -= S2[j++];
            if(z > x or z > y)
                z -= S3[k++];
        }
        
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends