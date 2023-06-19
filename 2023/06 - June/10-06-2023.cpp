/*

Author : Manas Rawat
Date : 10/06/2023
Problem : Arranging the array
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/arranging-the-array1131/1
Video Solution : https://youtu.be/Qaq2o6NSK2w

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {   
            auto merge = [&](int l, int mid, int r) {
                int size = r - l + 1;
                vector<int> t(size);
                
                int i, j, k;
                i = l;
                j = mid + 1;
                k = 0;
                
                while(i < mid + 1 and j < r + 1){
                    if(arr[i] >= 0 and arr[j] < 0)
                        t[k++] = arr[j++];
                    else
                        t[k++] = arr[i++];
                }
                
                while(i < mid + 1)
                    t[k++] = arr[i++];
                while(j < r + 1)
                    t[k++] = arr[j++];
                    
                k = 0;
                i = l;
                
                while(k < size)
                    arr[i++] = t[k++];
            };
            
            function<void(int, int)> divide = [&](int l, int r) {
                if(l < r){
                    int mid = l + (r - l) / 2;
                    
                    divide(l, mid);
                    divide(mid + 1, r);
                    merge(l, mid, r);
                }    
            };
            
            divide(0, n - 1);
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends