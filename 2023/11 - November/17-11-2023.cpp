//{ Driver Code Starts
#include <bits/stdc++.h>
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



void displayCList(Node *head)
{
    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout <<endl;
    itr=itr->left;
    head = itr;
    do{
        cout<<itr->data<<" ";
        itr=itr->left;
    }while(head!=itr);
    cout<<endl;
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
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

Node* concatenateCDLL(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* aEnd = a->left;
    Node* bEnd = b->left;

    aEnd->right = b;
    b->left = aEnd;

    a->left = bEnd;
    bEnd->right = a;

    return a;
}

Node* bTreeToCListUtil(Node* root) {
    if (!root) return nullptr; // Base case to terminate recursion

    Node* leftList = bTreeToCListUtil(root->left);
    Node* rightList = bTreeToCListUtil(root->right);

    // Convert the current node to a single-node CDLL
    root->left = root->right = root;

    // Concatenate the three lists: leftList + current node + rightList
    return concatenateCDLL(concatenateCDLL(leftList, root), rightList);
}


class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    
    Node *bTreeToCList(Node *root)
    {
        if (!root) return nullptr;

    Node* leftList = bTreeToCListUtil(root->left);
    Node* rightList = bTreeToCListUtil(root->right);

    // Convert the current node to a single-node CDLL
    root->left = root->right = root;

    // Concatenate the three lists: leftList + current node + rightList
    return concatenateCDLL(concatenateCDLL(leftList, root), rightList);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution obj;
        Node *head = obj.bTreeToCList(root);
        displayCList(head);
    }
    return 0;
}


// } Driver Code Ends
