
/*

Author : mrpankajpandey
Date : 15/03/2024
Problem :Linked List that is Sorted Alternatingly
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1
Video Solution : NA

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
/* Function to print linked list */

void append(struct Node **headRef, struct Node **tailRef, int newData)
{
    struct Node *new_node = new Node(newData);
    struct Node *last = *headRef;
    if (*headRef == NULL)
    {
        *headRef = new_node;
        *tailRef = *headRef;
        return;
    }

    (*tailRef)->next = new_node;
    *tailRef = (*tailRef)->next;
}

// A utility function to print a linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// } Driver Code Ends

/*
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data =x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    Node *merge(Node *head1, Node *head2)
    {
        if (!head1)
            return head2;
        if (!head2)
            return head1;

        Node *temp = head1;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = head2;

        return head1;
    }

    void reverse(Node *&head)
    {
        Node *prev = NULL, *curr = head, *next;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void splitList(Node *head, Node **Ahead, Node **Dhead)
    {
        *Ahead = new Node(0);
        *Dhead = new Node(0);

        Node *ascn = *Ahead;
        Node *dscn = *Dhead;
        Node *curr = head;
        while (curr)
        {
            ascn->next = curr;
            ascn = ascn->next;
            curr = curr->next;

            if (curr)
            {
                dscn->next = curr;
                dscn = dscn->next;
                curr = curr->next;
            }
        }

        ascn->next = NULL;
        dscn->next = NULL;

        *Ahead = (*Ahead)->next;
        *Dhead = (*Dhead)->next;

        return;
    }
    // your task is to complete this function
    void sort(Node **head)
    {
        // Code here
        Node *Ahead, *Dhead;
        splitList(*head, &Ahead, &Dhead);

        reverse(Dhead);

        *head = merge(Ahead, Dhead);

        return;
    }
};

//{ Driver Code Starts.
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        struct Node *head = NULL;
        struct Node *tail = NULL;
        int n, k;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            append(&head, &tail, k);
        }
        Solution ob;
        ob.sort(&head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends