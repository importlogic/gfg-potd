/*

Author : Manas Rawat
Date : 06/10/2023
Problem : Reverse alternate nodes in Link List
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/given-a-linked-list-reverse-alternate-nodes-and-append-at-the-end/1
Video Solution : NA

*/


//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
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
class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        if(odd == nullptr)
            return;
            
        if(odd -> next == nullptr)
            return;
        
        Node * prev, *cur, *last;
        prev = odd;
        cur = odd -> next;
        last = nullptr;
        
        while(cur != nullptr){
            prev -> next = cur -> next;
            
            if(cur -> next != nullptr){
                Node * temp = cur -> next -> next;
                cur -> next = last;
                last = cur;
                prev = prev -> next;
                
                if(temp == nullptr)
                    break;
                    
                cur = temp;
            }
            else{
                cur -> next = last;
                last = cur;
                break;
            }
        }
        
        prev -> next = cur;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends