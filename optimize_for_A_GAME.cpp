//{ Driver Code Starts
/*You are given an array arr of size n. The elements of the array represent n coin of values v1, v2, ....vn. You play against an opponent in an alternating way. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.
You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.Input:
n = 4
arr[] = {5, 3, 7, 10}
Output: 
15
Explanation: The user collects maximum
value as 15(10 + 5). It is guarantee that we cannot get more than 15 by any possible moves*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    long long maximumAmount(int n, int arr[]) {
        vector<vector<int>> dp(n, vector<int>(n));
        for (int gap = 0; gap < n; ++gap) {
            for (int i = 0, j = gap; j < n; ++i, ++j) {
                int x = ((i+2) <= j) ? dp[i+2][j] : 0;
                int y = ((i+1) <= (j-1)) ? dp[i+1][j-1] : 0;
                int z = (i <= (j-2)) ? dp[i][j-2] : 0;
                dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
            }
        }
        return dp[0][n-1];
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends