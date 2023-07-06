/*

Author : Manas Rawat
Date : 06/07/2023
Problem : Quick Sort
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/quick-sort/1
Video Solution : https://youtu.be/mdR1UdWJMkk

*/


//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low < high){
            int p = partition(arr, low, high);
            
            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int p = low;
       int pivot = arr[high];
       
       for(int i = low; i < high; i++){
           if(arr[i] < pivot){
               swap(arr[i], arr[p]);
               ++p;
           }
       }
       
       swap(arr[p], arr[high]);
       
       return p;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends