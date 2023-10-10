/*

Author : Manas Rawat
Date : 08/10/2023
Problem : Insert in a Sorted List
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1
Video Solution : NA

*/

//{ Driver Code Starts
//

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        if(head == nullptr){
            Node * newnode = new Node(data);
            return newnode;
        }
        
        Node * prev = nullptr;
        Node * cur = head;
        
        while(cur != nullptr){
            if(cur -> data > data){
                Node * newnode = new Node(data);
                
                if(prev == nullptr)
                    head = newnode;
                else 
                    prev -> next = newnode;
                    
                newnode -> next = cur;
                
                return head;
            }
            
            prev = cur;
            cur = cur -> next;
        }
        
        Node * newnode = new Node(data);
        prev -> next = newnode;
        
        return head;
    }
};


//{ Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
        
		int data;
		cin>>data;
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends
