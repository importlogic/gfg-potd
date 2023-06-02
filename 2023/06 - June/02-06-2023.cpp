/*

Author : Manas Rawat
Date : 02/06/2023
Problem : Santa Banta
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/santa-banta2814/1
Video Solution : https://youtu.be/-7fvbpHYDQw

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

vector<int> primes;

class Solution{
public:
    void precompute(){
        int maxSize = 2e6 + 10;
        vector<bool> isPrime(maxSize, 1);
        isPrime[0] = isPrime[1] = 0;
        
        primes.push_back(-1);
        
        for(int i = 2; i * i < maxSize; i++){
            if(isPrime[i]){
                for(int j = i * i; j < maxSize; j += i)
                    isPrime[j] = 0;
            }
        }
        
        for(int i = 0; i < maxSize; i++)
            if(isPrime[i])
                primes.push_back(i);
                
    }
    
    int helpSanta(int n, int m, vector<vector<int>> &g){
        vector<int> dsu(n, -1);
        
        function<int(int)> find = [&](int p) -> int {
            if(dsu[p] < 0) return p;
            return dsu[p] = find(dsu[p]);
        };
        
        auto merge = [&](int a, int b) {
            if(dsu[a] > dsu[b])
                swap(a, b);
                
            dsu[a] += dsu[b];
            dsu[b] = a;
        };
        
        for(int i = 1; i < n + 1; i++){
            for(auto j : g[i]){
                int x = i - 1;
                int y = j - 1;
                
                x = find(x);
                y = find(y);
                
                if(x != y)
                    merge(x, y);
            }
        }
        
        int nax = 1;
        
        for(int i = 0; i < n; i++){
            int a = find(i);
            
            if(dsu[a] < 0)
                nax = max(nax, abs(dsu[a]));
        }
        
        return nax == 1 ? -1 : primes[nax];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends