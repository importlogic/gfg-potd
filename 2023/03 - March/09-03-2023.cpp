/*

Author : Manas Rawat
Date : 09/03/2023
Problem : Find anagrams in linked list
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/de6f6a196aecdfb3e4939ba7729809a5a4bdfe90/1
Video Solution : https://youtu.be/TPbendk2Di8

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        vector<int> original(26, 0), current(26, 0);
        
        for(auto i : s)
            ++original[i - 'a'];
            
        Node * left, * right;
        left = right = head;
        
        vector<Node*> ans;
        bool take = 1;
        
        while(left != nullptr and right != nullptr){
            if(take and right != nullptr)
                ++current[(right -> data) - 'a'];
            take = 0;
            
            int status = 1;  // case 2
            for(int i = 0; i < 26; i++){
                if(current[i] > original[i]){
                    status = -1;
                    break;
                }
                
                if(current[i] < original[i]){
                    status = 0;
                    break;
                }
            }
            
            if(status == 1){ // case 2
                ans.push_back(left);
                right = right -> next;
                left = right;
                take = 1;
                for(int i = 0; i < 26; i++)
                    current[i] = 0;
            }
            else if(status == -1){ // case 1
                --current[(left -> data) - 'a'];
                if(left == right)
                    right = right -> next, take = 1;
                left = left -> next;
            }
            else{ // case 3
                right = right -> next;
                take = 1;
            }
        }
        
        for(int i = 0; i < ans.size(); i++){
            Node * current = ans[i];
            for(int j = 0; j < s.size() - 1; j++)
                current = current -> next;
            current -> next = nullptr;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends