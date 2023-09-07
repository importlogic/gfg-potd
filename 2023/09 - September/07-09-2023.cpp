//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<int>q;
        int step=0;
        int sz=arr.size();
//visited so that if no. repeats ,it means it is making a loop , thererfore we will push it again in our queue.
        vector<bool>visited(100000,false);
        q.push(start);
        visited[start]=true;
    //if start is same as end ,therfore return 0
        if(start==end)return 0;
        while(!q.empty()){
            int size=q.size();
            if(size==0)return -1;
            step++;
            while(size>0){
                int u=q.front();
                q.pop();
                for(int i=0;i<sz;i++){
                    int x=(u*arr[i])%100000;
                    if(!visited[x]){
                        visited[x]=true;
                    if(x==end)return step;
                    q.push(x);
                    }
                }
                size--;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
