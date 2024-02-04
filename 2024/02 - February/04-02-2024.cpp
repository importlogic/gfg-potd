/*

Author : Manas Rawat
Date : 04/02/2024
Problem : Subtraction in Linked List
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/subtraction-in-linked-list/1
Video Solution : https://youtu.be/9YIC2gzDZ9w

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node * reverse(Node * head) {
        Node * prev = nullptr, * cur = head;
        
        while(cur){
            Node * next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
    
    pair<Node *, Node *> subtract(Node * head1, Node * head2) {
        LinkedList ans, second;
        int carry = 0;
        
        while(head1 or head2){
            int cur = (head1 ? head1 -> data : 0) - (head2 ? head2 -> data : 0) - carry;
            carry = cur < 0;
            
            if(carry){
                if((head1 and head1 -> next) or (head2 and head2 -> next)){
                    ans.insert(10 + cur);
                    second.insert(0);
                }
                else{
                    second.insert(abs(cur));
                }
            }
            else{
                ans.insert(cur);
                second.insert(0);
            }
            
            if(head1)
                head1 = head1 -> next;
            if(head2)
                head2 = head2 -> next;
        }
        
        
        if(carry){
            return {second.head, ans.head};
        }
        else{
            return {ans.head, nullptr}; // nullptr indicate that F >= S
        }  
    }
    
    Node* subLinkedList(Node* head1, Node* head2) {
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        pair<Node *, Node *> res = subtract(head1, head2);
        Node * final_ans;
        
        if(res.second){
            head1 = res.first;
            head2 = res.second;
            
            final_ans = subtract(head1, head2).first;
        }
        else{
            final_ans = res.first;
        }
        
        final_ans = reverse(final_ans);
        
        while(final_ans -> data == 0 and final_ans -> next)
            final_ans = final_ans -> next;
        
        return final_ans;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends