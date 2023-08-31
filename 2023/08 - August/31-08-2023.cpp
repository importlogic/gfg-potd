/*

Author : Manas Rawat
Date : 31/08/2023
Problem : AVL Tree Deletion
Difficulty : Hard
Problem Link : https://practice.geeksforgeeks.org/problems/avl-tree-deletion/1
Video Solution : https://youtu.be/GQkI8lV320M

*/


//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

int setHeights(Node* n)
{
	if(!n) return 0;
	n->height = 1 + max( setHeights(n->left) , setHeights(n->right) );
	return n->height;
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
    Node* root = new Node(stoi(ip[0]));
        
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
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    setHeights(root);
    return root;
}

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}

struct Node* deleteNode(struct Node* root, int data);

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
        
		int n;
		cin>> n;
		int ip[n];
		for(int i=0; i<n; i++)
			cin>> ip[i];
        
		for(int i=0; i<n; i++)
		{
			root = deleteNode(root, ip[i]);
			
			if( !isBalancedBST(root) )
				break;
		}
        
		if(root==NULL)
			cout<<"null";
		else
			printInorder(root);
		cout<< endl;
        
		getline(cin,s); // to deal with newline char
	}
	return 1;
}

// } Driver Code Ends

/* Node is as follows:

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

*/

Node * leftRotate(Node * cur) {
    Node * toreturn = cur -> right;
    Node * temp = cur -> right -> left;
    cur -> right -> left = cur;
    cur -> right = temp;
    
    return toreturn;
}

Node * rightRotate(Node * cur){
    Node * toreturn = cur -> left;
    Node * temp = cur -> left -> right;
    cur -> left -> right = cur;
    cur -> left = temp;
    
    return toreturn;
}

Node* deleteNode(Node* root, int data)
{
    function<Node *(Node *, int)> del = [&del](Node * cur, int data) -> Node * {
        // deleting nodes
        if(cur == nullptr)
            return nullptr;
            
        if(cur -> data == data){
            if(cur -> left == nullptr and cur -> right == nullptr){
                // the node is leaf node

                delete(cur);
                return nullptr;
            }
            else if(cur -> left == nullptr){
                // only right child is present 
                
                Node * toreturn = cur -> right;
                delete(cur);
                return toreturn;
            }
            else if(cur -> right == nullptr){
                // only left child is present
                
                Node * toreturn = cur -> left;
                delete(cur);
                return toreturn;
            }
            else{
                Node * next = cur -> left;  
                
                while(next -> right != nullptr)
                    next = next -> right;
                    
                cur -> data = next -> data;
                
                cur -> left = del(cur -> left, cur -> data);
            }
        }  
        else if(data < cur -> data){
            cur -> left = del(cur -> left, data);
        }
        else{
            cur -> right = del(cur -> right, data);
        }
        
        
        // balancing
        setHeights(cur);
        
        int left, right;
        left = right = 0;
        
        if(cur -> left != nullptr)
            left = cur -> left -> height;
        if(cur -> right != nullptr)
            right = cur -> right -> height;
            
        if(left - right > 1){
            // left imbalance
            
            left = right = 0;
            
            if(cur -> left -> left != nullptr)
                left = cur -> left -> left -> height;
            if(cur -> left -> right != nullptr)
                right = cur -> left -> right -> height;
                
        
            if(left - right >= 0){
                // LL imbalance
                cur = rightRotate(cur);
            }
            else{
                // LR imbalance
                cur -> left = leftRotate(cur -> left);
                cur = rightRotate(cur);
            }
        }
        else if(left - right < -1){
            // right imbalance
            left = right = 0;
            
            if(cur -> right -> right != nullptr)
                right = cur -> right -> right -> height;
            if(cur -> right -> left != nullptr)
                left = cur -> right -> left -> height;
                
            if(left - right <= 0){
                // RR imbalance
                cur = leftRotate(cur);
            }
            else{
                // RL imbalance
                cur -> right = rightRotate(cur -> right);
                cur = leftRotate(cur);
            }
        }
        
        return cur;
    };
    
    return del(root, data);
}