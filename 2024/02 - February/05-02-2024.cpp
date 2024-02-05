/*

Author : Manas Rawat
Date : 05/02/2024
Problem : Sorted insert for circular linked list
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1
Video Solution : https://youtu.be/sBsUni7P__k

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/* structure for a Node */
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};


// } Driver Code Ends
/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
 */
 
// This function should return head of
// the modified list
class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
        if(!head){
            Node * new_node = new Node(data);
            new_node -> next = new_node;
            
            return new_node;
        }
    
        Node * cur = head; 
        
        while(1){
            if(data >= cur -> data and data <= cur -> next -> data){
                Node * new_node = new Node(data);
                new_node -> next = cur -> next;
                cur -> next = new_node;
                
                break;
            }
            
            if(cur -> next != head)
                cur = cur -> next;
            else{
                Node * new_node = new Node(data);
                cur -> next = new_node;
                new_node -> next = head;
                
                if(data <= head -> data)
                    head = new_node;
                
                break;
            }
        }
       
       return head;
    }
};

//{ Driver Code Starts.

/* Function to print Nodes in a given linked list */
void printList(struct Node *start)
{
  struct Node *temp;

  if(start != NULL)
  {
    temp = start;
    do { printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != start);
    printf("\n");
  }
}
/* Driver program to test above functions */
int main()
{
int t,n,x;
scanf("%d",&t);
int arr;
  while(t--){
  scanf("%d",&n);
  int list_size, i;
  
  /* start with empty linked list */
  struct Node *start = NULL;
  struct Node *temp,*r;
  
  
    /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
    if(n>0){
      scanf("%d",&arr);
    
    temp = new Node(arr);
    start=temp;
    r=start;
    }
    for (i = 0; i<n-1; i++)
    {
        scanf("%d",&arr);
        temp = new Node(arr);
        r->next=temp;
        r=r->next;
    }
    
    if(n>0)
    temp->next=start;
 
    scanf("%d",&x);
    Solution ob;
    start = ob.sortedInsert(start,x);
    printList(start);
    r=start;
    while(r!=start->next)
    {

      temp=start;
      start=start->next;
      free(temp);
    }
    free(start);
}
  return 0;
}

// } Driver Code Ends