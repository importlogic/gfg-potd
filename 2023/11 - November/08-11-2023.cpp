/*

Author : Manas Rawat
Date : 08/11/2023
Problem : Print Matrix in snake Pattern
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/print-matrix-in-snake-pattern-1587115621/1
Video Solution : https://youtu.be/D9gT2G-0sbI

*/


//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        int i = 0;
        int j = 0;
        
        int n = matrix.size();
        vector<int> ans(n * n);
        
        for(int c = 0; c < n * n; c++){
            ans[c] = matrix[i][j];
            
            if(i & 1)
                --j;
            else
                ++j;
                
            if(j == n or j == -1){
                if(j == n)
                    j = n - 1;
                else
                    j = 0;
                    
                ++i;
            }
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
        vector<int> result = ob.snakePattern(matrix);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends