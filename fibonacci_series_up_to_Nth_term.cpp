//{ Driver Code Starts
/*You are given an integer n, return the fibonacci series till the nth(0-based indexing) term. Since the terms can become very large return the terms modulo 109+7.
Input:
n = 5
Output:
0 1 1 2 3 5
Explanation:
0 1 1 2 3 5 is the Fibonacci series up to the 5th term.*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        vector<int>ans;
        ans.push_back(0);
        ans.push_back(1);
        int mod=1e9+7;
        if(n==1) return ans;
        int i=2;
        while(i<n){
            ans.push_back((ans[i-1]+ans[i-2])%mod);
            i++;
        }
        ans.push_back((ans[n-1]+ans[n-2])%mod);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends