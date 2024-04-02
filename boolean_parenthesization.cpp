/*Given a boolean expression s of length n with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer can be large, so return it with modulo 1003
Input: 
n = 7
s = T|T&F^T
Output: 
4
Explaination: 
The expression evaluates to true in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod=1003;
    int dp[202][202][2];
    int solve(string s,int i,int j,bool isTrue){
        int res=0;
        if(i > j) return false; 
        if(i==j){
            if(isTrue) return s[i]=='T';
            else return s[i]=='F';
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        for(int k=i+1;k<=j-1;k+=2){
            int lt=solve(s,i,k-1,true);
            int lf=solve(s,i,k-1,false);
            int rt=solve(s,k+1,j,true);
            int rf=solve(s,k+1,j,false);
            if(s[k]=='&'){
                if(isTrue) res+=lt*rt;
                else res+=lt*rf+lf*rt+lf*rf;
            }
            if(s[k]=='|'){
                if(isTrue) res+=lt*rt+lt*rf+lf*rt;
                else res+=lf*rf;
            }
            if(s[k]=='^'){
                if(isTrue) res+=lt*rf+lf*rt;
                else res+=lt*rt+lf*rf;
            }
            res=res%mod;
        }
        return dp[i][j][isTrue]=res;
    }
    int countWays(int n, string s){
        memset(dp,-1,sizeof(dp));
        return solve(s,0,n-1,true);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends