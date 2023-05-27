/*

Author : Manas Rawat
Date : 27/05/2023
Problem : Modify Linked List-1
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/modify-linked-list-1-0546/1
Video Solution : https://youtu.be/KjLrsrp4Izc

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
    struct Node* modifyTheList(struct Node *head)
    {
        Node * slow = head;
        Node * fast = head;
        
        while(fast != nullptr and fast -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        if(fast != nullptr){
            slow = slow -> next;
        }
        
        if(slow == nullptr)
            return head;
        
        Node * last = slow;
        
        auto reverse = [&last](Node * current, Node * prev) {
            while(current != nullptr){
                last = current;
                Node * next = current -> next;
                current -> next = prev;
                prev = current;
                current = next;
            }
        };
        
        reverse(slow, nullptr);
        
        Node * front = head;
        Node * back = last;
        while(back != nullptr){
            int temp = front -> data;
            
            front -> data = back -> data - front -> data;
            back -> data = temp;
            
            front = front -> next;
            back = back -> next;
        }
        
        reverse(last, nullptr);
        
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends