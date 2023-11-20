/*

Author : Manas Rawat
Date : 20/11/2023
Problem : K Sum Paths
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/k-sum-paths/1
Video Solution : https://youtu.be/zV8B4gzRo-4

*/


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) 
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++

/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
  public:
    int sumK(Node *root,int k)
    {
        unordered_map<int,int> f;
        f[0] = 1;
        
        long long ans = 0;
        const long long mod = 1e9 + 7;
        
        function<void(Node *, int)> dfs = [&](Node * node, int sum) {
            if(node == nullptr)
                return 0;
                
            sum += node -> data;
            
            if(f.find(sum - k) != f.end())
                ans = (ans + f[sum - k]) % mod;
            
            ++f[sum];
            
            dfs(node -> left, sum);
            dfs(node -> right, sum);
                
            --f[sum];
            
            if(f[sum] == 0)
                f.erase(sum);
        };
        
        dfs(root, 0);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);
  
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        string key;
        getline(cin, key);
        int k=stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends