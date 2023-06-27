/*

Author : Manas Rawat
Date : 27/06/2023
Problem : Union of Two Linked Lists
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/union-of-two-linked-list/1
Video Solution : https://youtu.be/7RXrBCO2Lbo

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
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


// } Driver Code Ends
/*
// structure of the node is as follows

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
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        set<int> elements;
        
        while(head1 != nullptr){
            elements.insert(head1 -> data);
            head1 = head1 -> next;
        }
        while(head2 != nullptr){
            elements.insert(head2 -> data);
            head2 = head2 -> next;
        }
            
        Node * current = nullptr;
        Node * head;
        
        for(auto i : elements){
            Node * newnode = new Node(i);
            if(current == nullptr){
                head = newnode;
                current = head;
            }
            else{
                current -> next = newnode;
                current = newnode;
            }
        }
        
        return head;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends