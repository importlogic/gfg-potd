/*

Author : Manas Rawat
Date : 10/10/2023
Problem : Nodes at given distance in binary tree
Difficulty : Hard
Problem Link : https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1
Video Solution : NA

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends


/* A binary Tree node

struct Node

{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int> ans;
        
        function<int(Node *, int)> dfs = [&](Node * cur, int d) -> int {
            if(cur == nullptr){
                return -1;
            }
            
            if(d == 0){
                ans.push_back(cur -> data);
            }
            
            if(cur -> data == target){
                dfs(cur -> left, k - 1);
                dfs(cur -> right, k - 1);
                
                return 1;
            }
            else{
                int left = dfs(cur -> left, (d == -1) ? -1 : d - 1);
                int right = dfs(cur -> right, (d == -1) ? -1 : d - 1);
                
                if(left != -1){
                    if(k - left > 0)
                        dfs(cur -> right, k - left - 1);
                    
                    if(k - left == 0)
                        ans.push_back(cur -> data);
                        
                    return left + 1;
                }
                
                if(right != -1){
                    if(k - right > 0)
                        dfs(cur -> left, k - right - 1);
                        
                    if(k - right == 0)
                        ans.push_back(cur -> data);
                        
                    return right + 1;
                }
                
                return -1;
            }
        };
        
        dfs(root, -1);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends