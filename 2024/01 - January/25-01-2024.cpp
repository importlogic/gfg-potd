/*

Author : Manas Rawat
Date : 25/01/2024
Problem : Shortest Prime Path
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/shortest-prime-path--141631/1
Video Solution : https://youtu.be/3UE4PV4tfcs

*/


//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

vector<string> primes;
bool computed = 0;

class Solution{   
public:
    void sieve(){
        int n = 9999;
        vector<bool> prime(n + 1, 1); 
        prime[0] = prime[1] = 0; 
    
        for(int i = 2; i * i <= n; i++){
            if(prime[i]){
                for(int j = i * i; j <= n; j += i) 
                    prime[j] = 0;
            }
        } 
    
        for(int i = 1000; i < n + 1; i++){
            if(prime[i])
                primes.push_back(to_string(i));
        }
        
        computed = 1;
    }
    
    int solve(int Num1,int Num2)
    {   
        if(Num1 == Num2)
            return 0;
            
        if(!computed){
            sieve();
        }
        
        const int inf = 1e9;
        
        map<string,int> d;
        for(auto i : primes)
            d[i] = inf;
            
        string start = to_string(Num1);
        string end = to_string(Num2);
            
        d[start] = 0;
        queue<string> q;
        q.push(start);
        
        while(!q.empty()){
            string cur = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                for(char j = (i == 0 ? '1' : '0'); j <= '9'; j++){
                    if(j != cur[i]){
                        string next = cur;
                        next[i] = j;
                        
                        auto ptr = d.find(next);
                        if(ptr != d.end() and ptr -> second > d[cur] + 1){
                            ptr -> second = d[cur] + 1;
                            q.push(next);
                            
                            if(next == end)
                                return d[next];
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends