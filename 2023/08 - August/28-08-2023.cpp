/*

Author : Manas Rawat
Date : 28/08/2023
Problem : Remove duplicate element from sorted Linked List
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1
Video Solution : https://youtu.be/D5k85KVxy6E

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
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
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    Node * prev = nullptr;
    Node * cur = head;
    
    while(cur != nullptr){
        Node * todelete = nullptr;
        
        if(prev != nullptr){
            if(prev -> data == cur -> data){
                prev -> next = cur -> next;
                todelete = cur;
            }
            else{
                prev = cur;
            }
        }
        else{
            prev = cur;
        }
        
        cur = cur -> next;
        
        if(todelete != nullptr)
            delete(todelete);
    }
    
    return head;
}