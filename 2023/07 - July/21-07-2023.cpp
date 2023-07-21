/*

Author : Manas Rawat
Date : 21/07/2023
Problem : Reverse a Linked List in groups of given size
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
Video Solution : https://youtu.be/yAvSSgV1C_k

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        node * curHead, * nextHead;
        curHead = nextHead = nullptr;
            
        function<void(node *, node *, int)> traverse = [&](node * cur, node * prev, int p) {
            if(cur == nullptr)
                return;
            
            traverse(cur -> next, cur, (p + 1) % k);

            if((cur -> next == nullptr) or (p == k - 1))
                curHead = cur;
                
            if(p == 0){
                cur -> next = nextHead;
                nextHead = curHead;
            }
            else{
                cur -> next = prev;
            }
        };
        
        traverse(head, nullptr, 0);
        
        return curHead;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends