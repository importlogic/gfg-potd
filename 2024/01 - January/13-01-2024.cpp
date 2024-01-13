/*

Author : Manas Rawat
Date : 13/01/2024
Problem : Insertion Sort for Singly Linked List
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/insertion-sort-for-singly-linked-list/1
Video Solution : https://youtu.be/yA0QclBCV6k

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        function<void(Node *)> helper = [&](Node * cur) {
            if(!cur)
                return;
                
            helper(cur -> next);
            
            int key = cur -> data;
            Node * next = cur -> next;
            
            while(next){
                if(next -> data < key){
                    cur -> data = next -> data;
                    cur = next;
                    next = cur -> next;
                }
                else{
                    break;
                } 
            }
            
            cur -> data = key;
        };
        
        helper(head_ref);
        
        return head_ref;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends