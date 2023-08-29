/*

Author : Manas Rawat
Date : 29/08/2023
Problem : Delete nodes having greater value on right
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1
Video Solution : https://youtu.be/Vfn50Jn7efA

*/


//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        int MAX = -1e9;
        
        function<Node *(Node *)> traverse = [&](Node * cur) -> Node * {
            if(cur == nullptr)
                return nullptr;
                
            Node * next = traverse(cur -> next);
            
            if(next != nullptr){
                Node * todelete = cur -> next;
                cur -> next = next;
                delete(todelete);
            }
            
            MAX = max(MAX, cur -> data);
            
            return (MAX > cur -> data) ? cur -> next : nullptr;
        };
        
        Node * first = traverse(head);
        
        return (first == nullptr) ? head : first;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends