/*

Author : Manas Rawat
Date : 01/11/2023
Problem : Frequencies of Limited Range Array Elements
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1
Video Solution : NA

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        const int mask = (1LL << 16) - 1;
        for(auto i : arr){
            int val = i & mask;
            if(val <= N)
                arr[val - 1] += (1LL << 16);
        }
        
        for(auto &i : arr)
            i >>= 16;
    }
};


//{ Driver Code Starts.

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int N, P;
	    //size of array
	    cin >> N; 
	    
	    vector<int> arr(N);
	    
	    //adding elements to the vector
	    for(int i = 0; i < N ; i++){
	        cin >> arr[i]; 
	    }
        cin >> P;
        Solution ob;
        //calling frequncycount() function
		ob.frequencyCount(arr, N, P); 
		
		//printing array elements
	    for (int i = 0; i < N ; i++) 
			cout << arr[i] << " ";
	    cout << endl;
	}	
	return 0; 
}





// } Driver Code Ends