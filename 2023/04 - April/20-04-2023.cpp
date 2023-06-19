/*

Author : Manas Rawat
Date : 20/04/2023
Problem : Bheem Wants Ladoos
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/9b61b8efbb030aed799055f776629dbf1287fbae/1
Video Solution : https://youtu.be/aci8-LqHnao

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    int ladoos(Node* root, int home, int k)
    {
        const int inf = 1e9;
        
        map<Node *, int> distance;
        map<Node *, vector<Node *>> graph;
        
        Node * source;
        
        function<void(Node *, Node *)> traverse = [&](Node * current, Node * parent) {
            if(current == nullptr)
                return;
                
            if(parent != nullptr)
                graph[current].push_back(parent);
            if(current -> left != nullptr)
                graph[current].push_back(current -> left);
            if(current -> right != nullptr)
                graph[current].push_back(current -> right);
                
            if(current -> data == home){
                distance[current] = 0;
                source = current;
            }
            else{
                distance[current] = inf;
            }
            
            traverse(current -> left, current);
            traverse(current -> right, current);
        };
        
        traverse(root, nullptr);
        
        queue<Node *> q;
        q.push(source);
        int ans = 0;
        
        while(!q.empty()){
            Node * current = q.front();
            q.pop();
            
            ans += current -> data;
            
            if(distance[current] < k){
                for(auto child : graph[current]){
                    if(distance[child] > distance[current] + 1){
                        distance[child] = distance[current] + 1;
                        q.push(child);
                    }
                }
            }
        }
        
        return ans;
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends