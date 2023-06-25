/*

Author : Manas Rawat
Date : 25/06/2023
Problem : Unique rows in boolean matrix
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1
Video Solution : https://youtu.be/3RLVA6QQ79s

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends

class TrieNode{
    public:
    vector<TrieNode*> next;
    
    TrieNode(){
        next = vector<TrieNode*> (2, nullptr);
    }
};

class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        TrieNode * root = new TrieNode;
        vector<vector<int>> ans;
        
        for(int i = 0; i < row; i++){
            bool ok = 0;
            vector<int> newRow;
            TrieNode * current = root;
            
            for(int j = 0; j < col; j++){
                newRow.push_back(M[i][j]);
                if(current -> next[M[i][j]] != nullptr){
                    current = current -> next[M[i][j]];
                }    
                else{
                    TrieNode * newnode = new TrieNode;
                    current -> next[M[i][j]] = newnode;
                    current = newnode;
                    ok = 1;
                }
            }
            
            if(ok){
                ans.emplace_back(newRow);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends