/*

Author : Manas Rawat
Date : 08/01/2024
Problem : Merge 2 sorted linked list in reverse order
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1
Video Solution : https://youtu.be/-6iKZo-xl94

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    Node * reverse(Node * node){
        Node * prev = nullptr;
        
        while(node){
            Node * next = node -> next;
            node -> next = prev;
            prev = node;
            node = next;
        }
        
        return prev;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        node1 = reverse(node1);
        node2 = reverse(node2);
        
        Node * newHead = nullptr;
        Node * curNode = nullptr;
        
        while(node1 and node2){
            if(node1 -> data > node2 -> data){
                if(!curNode){
                    curNode = new Node;
                    curNode -> data = node1 -> data;
                    newHead = curNode;
                }
                else{
                    Node * newNode = new Node;
                    newNode -> data = node1 -> data;
                    
                    curNode -> next = newNode;
                    curNode = newNode;
                }
                
                node1 = node1 -> next;
            }
            else{
                if(!curNode){
                    curNode = new Node;
                    curNode -> data = node2 -> data;
                    newHead = curNode;
                }
                else{
                    Node * newNode = new Node;
                    newNode -> data = node2 -> data;
                    curNode -> next = newNode;
                    curNode = newNode;
                }   
                
                node2 = node2 -> next;
            }
        }
        
        while(node1){
            if(!curNode){
                curNode = new Node;
                curNode -> data = node1 -> data;
                newHead = curNode;
            }
            else{
                Node * newNode = new Node;
                newNode -> data = node1 -> data;
                curNode -> next = newNode;
                curNode = newNode;
            }  
            
            node1 = node1 -> next;
        }
        
        while(node2){
            if(!curNode){
                curNode = new Node;
                curNode -> data = node2 -> data;
                newHead = curNode;
            }
            else{
                Node * newNode = new Node;
                newNode -> data = node2 -> data;
                curNode -> next = newNode;
                curNode = newNode;
            }  
            
            node2 = node2 -> next;
        }
        
        return newHead;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends