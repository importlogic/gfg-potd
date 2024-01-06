/*

Author : Manas Rawat
Date : 06/01/2024
Problem : Techfest and the Queue
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/techfest-and-the-queue1044/1
Video Solution : https://youtu.be/E5UbBRNQxPc

*/


//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int MAX = 2e5 + 10;
vector<int> smol(MAX, MAX);
bool computed = 0;

void pre(){
    smol[1] = 1;
    for(int i = 2; i < MAX; i++){
        if(smol[i] == MAX){
            smol[i] = i;
            for(int j = i + i; j < MAX; j += i)
                smol[j] = min(smol[j], i);
        }
    }
    
    computed = 1;
}

class Solution {
public:
	int sumOfPowers(int a, int b){
	    if(!computed)
	        pre();
	        
	    int ans = 0;
	    
	    for(int i = a; i < b + 1; i++){
	        int cur = i;
	        
	        while(cur > 1){
	            ++ans;
	            cur /= smol[cur];
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends