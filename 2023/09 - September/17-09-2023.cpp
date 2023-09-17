/*

Author : Manas Rawat
Date : 17/09/2023
Problem : Print first n Fibonacci Numbers
Difficulty : Basic
Problem Link : https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1
Video Solution : NA

*/


//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        vector<long long> ans = {1};
        if(n == 1)
            return ans;
        ans.push_back(1);
        if(n == 2)
            return ans;
            
        for(int i = 3; i < n + 1; i++){
            ans.push_back(ans[i - 3] + ans[i - 2]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends