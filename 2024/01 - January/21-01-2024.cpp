/*

Author : Manas Rawat
Date : 21/01/2024
Problem : Vertex Cover
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/vertex-cover/1
Video Solution : https://youtu.be/AAJuIj1bu60

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int next(int x){
        unsigned smallest, ripple, new_smallest, ones;

        if (x == 0) return 0;
        smallest     = (x & -x);
        ripple       = x + smallest;
        new_smallest = (ripple & -ripple);
        ones         = ((new_smallest/smallest) >> 1) - 1;
        return ripple | ones;
    }
    
    int vertexCover(int n, vector<pair<int, int>> &edges) {
        int ans = 20;
        
        auto check = [&](int bits) -> bool {
            int cur = (1 << bits) - 1;
            
            while(cur < (1 << n)){
                int m = edges.size();
                
                for(auto edge : edges){
                    int x, y;
                    tie(x, y) = edge;
                    --x; --y;
                    
                    if(((cur >> x) & 1) or ((cur >> y) & 1))
                        --m;
                }
                
                if(m == 0)
                    return 1;
                    
                cur = next(cur);
            }
            
            return 0;
        };
        
        int low = 0;
        int high = n;
        
        while(low < high - 1){
            int mid = low + (high - low) / 2;
            
            if(check(mid))
                high = mid;
            else
                low = mid;
        }
        
        return high;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends