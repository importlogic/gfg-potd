/*

Author : Manas Rawat
Date : 14/01/2024
Problem : Find duplicate rows in a binary matrix
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/find-duplicate-rows-in-a-binary-matrix/1
Video Solution : https://youtu.be/btb4KVCJuqw

*/


//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class node {
    public:
    vector<node*> next;
    
    node() {
        next = vector<node*> (2, nullptr);
    }
};

class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        swap(N, M);
        
        node * root = new node();
        vector<int> ans;
        
        auto insert = [&](vector<int> &row) {
            node * cur = root;
            
            for(int i = 0; i < M; i++){
                if(cur -> next[row[i]] != nullptr){
                    cur = cur -> next[row[i]];
                }
                else{
                    node * newnode = new node();
                    cur -> next[row[i]] = newnode;
                    
                    cur = newnode;
                }
            }
        };
        
        auto find = [&](vector<int> &row) -> bool {
            node * cur = root;
            
            for(int i = 0; i < M; i++){
                if(cur -> next[row[i]] != nullptr){
                    cur = cur -> next[row[i]];
                }
                else{
                    return 0;
                }
            } 
            
            return 1;
        };
        
        for(int i = 0; i < N; i++){
            if(!find(matrix[i])){
                insert(matrix[i]);
            }
            else
                ans.push_back(i);
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
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends