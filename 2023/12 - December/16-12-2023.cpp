/*

Author : Manas Rawat
Date : 16/12/2023
Problem : String's Count
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints1135/1
Video Solution : https://youtu.be/pyO0fQ5UCUY

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


long long int countStr(long long int n){
    long long ans = 0;
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            if(i + j > n)
                continue;
                
            long long curans = 1;
                
            long long total = n;
            if(j == 2){
                curans = (total * (total - 1)) / 2;
                total -= 2;
            }
            else if(j){
                curans = total;
                --total;
            }
            
            if(i)
                curans *= total;
                
            ans += curans;    
        }
    }
    
    return ans;
}