/*Given an array arr of size n, the task is to check if the given array can be a level order representation of a Max Heap.
Input:
n = 6
arr[] = {90, 15, 10, 7, 12, 2}
Output: 
1
Explanation: 
The given array represents below tree
       90
     /    \
   15      10
  /  \     /
7    12  2
The tree follows max-heap property as every
node is greater than all of its descendants.
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        bool judge=true;   
        if(n%2){
            for(int i=0;i<=(n-1)/2-1;i++){
                if(arr[i]>=arr[2*i+1]&&arr[i]>=arr[2*i+2]) judge=judge&true;
                else return false;
            }
        }
        for(int i=0;i<=(n-1)/2;i++){
            if(arr[i]>=arr[2*i+1]&&arr[i]>=arr[2*i+2]) judge=judge&true;
            else return false;
        }
        return judge;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends