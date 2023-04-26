/*

Author : Manas Rawat
Date : 26/04/2023
Problem : Seating Arrangement
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/6bb49b563cc171335c6564b00307a6d867e0268d/1
Video Solution : https://youtu.be/N3QqMHhXqzY

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        int seat = 0;

        while(seat < m and n){
            if(seat + 1 < m and seats[seat + 1] == 1){
                seat += 3;
                continue;
            }
            
            if(seats[seat] == 1){
                seat += 2;
                continue;
            }
            
            if(seat > 0 and seats[seat - 1] == 1){
                ++seat;
                continue;
            }
            
            --n;
            seat += 2;
        }
        
        return n == 0;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends