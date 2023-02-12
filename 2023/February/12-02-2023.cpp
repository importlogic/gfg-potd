/*

Author : Manas Rawat
Date : 12/02/2023
Problem : Prime List
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/6cb0782855c0f11445b8d70e220f888e6ea8e22a/1
Video Solution : https://youtu.be/ORkkJTnX2cU

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

void sieve(vector<int> &primes){
    int max = 1e5 + 1;
    vector<bool> isprime(max, 1);
    
    isprime[0] = isprime[1] = 0;
    
    for(int i = 2; i * i < max; i++){
        if(isprime[i]){
            for(int j = i + i; j < max; j += i) isprime[j] = 0;
        }
    }
    
    for(int i = 0; i < max; i++) if(isprime[i]) primes.push_back(i);
}

void traverse(Node * current, vector<int> &primes){
    if(current == nullptr) return;
    
    int val = current -> val;
    
    int p = lower_bound(primes.begin(), primes.end(), val) - primes.begin();
    
    int left, right, newval;
    right = primes[p] - val;
    if(p > 0) left = val - primes[p - 1];
    
    if(p == primes.size()){ // input is rightmost
        newval = primes[primes.size() - 1];
    }
    else if(p > 0){ // input is in the middle
        if(left <= right) newval = primes[p - 1];
        else newval = primes[p];
    }
    else newval = primes[p]; // input is leftmost
    
    current -> val = newval;
    
    traverse(current -> next, primes);
}

class Solution{
public:
    Node *primeList(Node *head){
        vector<int> primes;
        
        sieve(primes);
        traverse(head, primes);
        
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends