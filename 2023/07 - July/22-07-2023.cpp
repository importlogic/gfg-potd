/*

Author : Manas Rawat
Date : 22/07/2023
Problem : Remove duplicates from an unsorted linked list
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
Video Solution : https://youtu.be/g1nAeeewse8

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


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        vector<int> f(1e4 + 10, 0);
        
        Node * prev = nullptr;
        Node * cur = head;
        
        while(cur != nullptr){
            ++f[cur -> data];
            
            if(f[cur -> data] > 1)
                prev -> next = cur -> next;
            else
                prev = cur;
            
            cur = cur -> next;
        }
        
        return head;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
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
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends