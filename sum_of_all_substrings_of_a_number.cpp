//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    long long sumSubstrings(string s){
        long long mod = 1e9 + 7;
        long long n = s.length();
        vector<long long> dp(n);
        
        dp[0] = s[0] - '0';
        long long totalSum = dp[0];
        
        for (int i = 1; i < n; i++) {
            dp[i] = ((i+1) * (s[i]-'0') + 10 * dp[i-1]) % mod;
            totalSum = (totalSum + dp[i]) % mod;
        }
        
        return totalSum;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends