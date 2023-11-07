/*

Author : Manas Rawat
Date : 07/11/2023
Problem : Sum of upper and lower triangles
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/sum-of-upper-and-lower-triangles-1587115621/1
Video Solution : https://youtu.be/oTXdwum_KMA

*/


//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        int upper, lower;
        upper = lower = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i + 1; j++)
                lower += matrix[i][j];
            for(int j = i; j < n; j++)
                upper += matrix[i][j];
        }
        
        return {upper, lower};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        vector<int> result = ob.sumTriangles(matrix,n);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends