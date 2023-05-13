/*

Author : Manas Rawat
Date : 13/05/2023
Problem : Bit Magic
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/ed0422e992899f3f46340ce97b0090683ceebd67/1
Video Solution : https://youtu.be/I7wqb2F_u5s

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
    int bitMagic(int n, vector<int> &arr) {
        int ans = 0;
        
        for(int i = 0; i < n / 2; i++)
            ans += arr[i] != arr[n - i - 1];
            
        return (ans + 1) / 2; // ceil(a / b) -> (a + b - 1 / b)
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
        
        Solution obj;
        int res = obj.bitMagic(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends