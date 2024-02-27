/*

Author : Manas Rawat 
Date : 27/02/2024
Problem : Play With OR
Difficulty : Easy 
Problem Link : https://www.geeksforgeeks.org/problems/play-with-or5515/1
Video Solution : NA

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


int* game_with_number(int arr[], int n);

int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        int *arr2;
        
        arr2 = game_with_number(arr, n);
        for(int i = 0;i < n; i++)
            cout << arr2[i] << " ";
        
        cout << endl;
        
    }

}

// } Driver Code Ends


int* game_with_number(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
        arr[i] = arr[i] | arr[i + 1];
        
    return arr;
}

