/*

Author : Manas Rawat
Date : 16/03/2023
Problem : Second smallest number
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/5c2734730cb1e98e3877a0b91f7d680d0efc8acf/1
Video Solution : https://youtu.be/86RfuHccb04

*/


//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        vector<int> number(D, 9);
        
        long long currentSum = 9 * D;
        int k = min(currentSum - S, 8LL);
            
        if(k < 0)
            return "-1";
            
        currentSum -= k;
        number[D - 1] -= k;
            
        for(int i = D - 2; i > -1; i--){
            int k = min(currentSum - S, 9LL);
                
            if(k < 0)
                return "-1";
                    
            currentSum -= k;
            number[i] -= k;
        }
        
        int index = 0;
        while(index < D - 1 and (number[index] == 0 or number[index + 1] == 9)) ++index;
        
        if(index == (D - 1))
            return "-1";
            
        --number[index];
        ++number[index + 1];
            
        string ans = "";
            
        for(int i = D - 1; i > -1; i--)
            ans += to_string(number[i]);

        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends