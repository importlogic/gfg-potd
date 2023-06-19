/*

Author : Manas Rawat
Date : 28/05/2023
Problem : Nth node from end of linked list
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
Video Solution : https://youtu.be/fPB7XW8uwz8

*/


//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

#include<bits/stdc++.h>

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    auto reverse = [&](Node * current) -> int {
        Node * prev = nullptr;
        
        while(current != nullptr){
            Node * temp = current -> next;
            current -> next = prev;
            prev = current;
            current = temp;
        }
        
        current = prev;
        int pos = 1;
        
        while(current != nullptr){
            if(pos == n)
                return current -> data;
                
            current = current -> next;
            ++pos;
        }
        
        return -1;
    };
    
    return reverse(head);
}

