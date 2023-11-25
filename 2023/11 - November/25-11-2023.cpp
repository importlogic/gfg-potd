/*

Author : Manas Rawat
Date : 25/11/2023
Problem : Shuffle integers
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/shuffle-integers2401/1
Video Solution : https://youtu.be/encXTss7UPQ

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void shuffleArray(int a[],int n)
	{
	    const int mod = 1001;
	    for(int i = 0; i < n / 2; i++){
	        a[i * 2] += (a[i] % mod) * mod;
	        a[i * 2 + 1] += (a[i + n / 2] % mod) * mod;
	    }
	    
	    for(int i = 0; i < n; i++){
	        a[i] /= mod;
	    }
	}
};

//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends