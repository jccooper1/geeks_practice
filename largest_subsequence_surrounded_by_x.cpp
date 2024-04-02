/*Given a square matrix a of size n x n, where each cell can be either 'X' or 'O', you need to find the size of the largest square subgrid that is completely surrounded by 'X'. More formally you need to find the largest square within the grid where all its border cells are 'X'.
Input:
n = 2
a = [[X,X],
     [X,X]]
Output:
2
Explanation:
The largest square submatrix 
surrounded by X is the whole 
input matrix.*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        // code here
        vector<vector<int>>hor(n,vector<int>(n,0));
        vector<vector<int>>ver(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='X'){
                    hor[i][j]=(j==0)?1:hor[i][j-1]+1;
                    ver[i][j]=(i==0)?1:ver[i-1][j]+1;
                }
            }
        }
        int max=0;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int small=min(hor[i][j],ver[i][j]);
                while(small>max){
                if(hor[i-small+1][j]>=small&&ver[i][j-small+1]>=small) {
                max=small;}
                small--;
                }
            }
        }
        return max;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends