/*

Author : Manas Rawat
Date : 15/04/2023
Problem : Find Total Time Taken
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/5ae4f296db3e6bb74641c4087d587b6f89d9d135/1
Video Solution : https://youtu.be/A58GjZiWPOQ

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int totalTime(int n, vector<int> &arr, vector<int> &time) {
        vector<bool> taken(n + 1, 0);
        
        int ans = -1;
         
        for(int i = 0; i < n; i++){
            if(!taken[arr[i]])
                ++ans, taken[arr[i]] = 1;
            else
                ans += time[arr[i] - 1];
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        
        vector<int> time(n);
        Array::input(time,n);
        
        Solution obj;
        int res = obj.totalTime(n, arr, time);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends