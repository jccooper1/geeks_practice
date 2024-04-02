/*You are given an undirected graph of N nodes and M edges. Return 1 if the graph is a tree, else return 0.
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
    public:
 
bool iscycle(int node, int parent, vector<int> adj[], vector<bool> &visit)
{
    visit[node] = 1;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (visit[it] == 1)
            return 1;
        else if (iscycle(it, node, adj, visit))
            return 1;
    }
    return 0;
}
    int isTree(int n, int m, vector<vector<int>> &arr){
        if(m!=n-1){
            return false;
        }
        vector<bool> visited(n,false);
        vector<int> adj[n];
        for(int i=0;i<m;i++){
            adj[arr[i][0]].push_back(arr[i][1]);
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        if(iscycle(0,-1,adj,visited)){
            return false;
        }
                for(int i=0;i<n;i++){
            if(visited[i]==0)
            return 0;
        }
        return true;

    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends