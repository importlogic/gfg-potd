/*

Author : Manas Rawat
Date : 19/11/2023
Problem : Intersection of two sorted Linked lists
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1
Video Solution : https://youtu.be/aEjHS-I3_Q4

*/


//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        Node * newHead = nullptr;
        Node * curNode = nullptr;
        
        while(head1 != nullptr and head2 != nullptr){
            if(head1 -> data < head2 -> data)
                head1 = head1 -> next;
            else if(head2 -> data < head1 -> data)
                head2 = head2 -> next;
            else{
                if(newHead == nullptr){
                    newHead = new Node(head1 -> data);
                    curNode = newHead;
                }
                else{
                    curNode -> next = new Node(head1 -> data);
                    curNode = curNode -> next;
                }
            }
        }
        
        return newHead;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends