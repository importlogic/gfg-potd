/*

Author : Manas Rawat
Date : 23/07/2023
Problem : Given a linked list of 0s, 1s and 2s, sort it
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
Video Solution : https://youtu.be/eU5_7zTrB1w

*/


//{ Driver Code Starts
#include <bits/stdc++.h>

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

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
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
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        vector<Node*> list;
        
        while(head != nullptr){
            list.push_back(head);
            head = head -> next;
        }
        
        int i = 0;
        int j = list.size() - 1;
        int x = 0;
        
        while(x <= j){
            if(list[x] -> data == 0){
                int temp = list[x] -> data;
                list[x] -> data = list[i] -> data;
                list[i] -> data = temp;
                ++i;
                ++x;
            }
            else if(list[x] -> data == 2){
                int temp = list[x] -> data;
                list[x] -> data = list[j] -> data;
                list[j] -> data = temp;
                --j;                
            }
            else{
                ++x;
            }
        }
        
        return list[0];
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends