/*

Author : Manas Rawat 
Date : 15/03/2024
Problem : Linked List that is Sorted Alternatingly
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1
Video Solution : NA

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    void sort(Node **head)
    {
        if (head == nullptr || *head == nullptr) {
            return;
        }
        
        vector<int> data_vec;
        Node* curr = *head;
        while (curr != nullptr) {
            data_vec.push_back(curr->data);
            curr = curr->next;
        }
        
        std::sort(data_vec.begin(), data_vec.end());
        
        curr = *head;
        for (int i = 0; i < data_vec.size(); ++i) {
            curr->data = data_vec[i];
            curr = curr->next;
        }
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends
