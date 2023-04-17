/*

Author : Manas Rawat
Date : 17/04/2023
Problem : Job Sequencing Problem
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/00ae30d0e0f6d8877c68f8b8558c5b0138fdb4b7/1
Video Solution : https://youtu.be/N7Gf3JbYyoM

*/


//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n, [](Job &a,Job &b){
            if(a.profit == b.profit)
                return a.dead < b.dead;
            return a.profit > b.profit;
        });
        
        int ds[n + 1];
        memset(ds, -1, sizeof(ds));
        
        function<int(int)> find = [&](int a) -> int {
            if(ds[a] < 0)
                return a;
            return ds[a] = find(ds[a]);
        };
        
        function<void(int, int)> merge = [&](int a, int b){
            a = find(a);
            b = find(b);
            
            if(a > b)
                swap(a, b);
                
            if(a == b)
                return;
                
            ds[a] += ds[b];
            ds[b] = a;
        };
        
        vector<int> ans(2, 0);
        
        for(int i = 0; i < n; i++){
            int x = find(arr[i].dead);
            
            if(x == 0)
                continue;
                
            merge(x, x - 1);
            
            ans[1] += arr[i].profit;
            ans[0]++;
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends