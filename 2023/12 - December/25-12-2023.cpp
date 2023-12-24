/*

Author : Manas Rawat
Date : 25/12/2023
Problem : Determinant of a Matrix
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/determinant-of-a-matrix-1587115620/1
Video Solution : https://youtu.be/ydidwdUKelo

*/


//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int>> &matrix, int n)
    {
        if(n == 1)
            return matrix[0][0];
            
        int ans = 0;
        
        // traverse all columns of 0th row
        for(int i = 0; i < n; i++){
            vector<vector<int>> second(n - 1, vector<int> (n - 1));
            
            // traverse all rows of second matrix
            for(int j = 1; j < n; j++){
                int x = 0;
                
                // traverse all columns of second matrix
                for(int k = 0; k < n; k++){
                    if(k == i)
                        continue;
                        
                    second[j - 1][x++] = matrix[j][k];
                }
            }
            
            ans += matrix[0][i] * determinantOfMatrix(second, n - 1) * ((i & 1) ? -1 : 1);
        }
        
        return ans;
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
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends