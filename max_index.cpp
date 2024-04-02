/*Given an array a of n positive integers. The task is to find the maximum of j - i subjected to the constraint of a[i] < a[j] and i < j.
Input:
n = 2
a[] = {1, 10}
Output:
1
Explanation:
a[0] < a[1] so (j-i) is 1-0 = 1.
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*brute force
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    {   int max=-1;
        // Your code here
        if(n==1) return 0;
        for(int i=0;i<n;i++){
            int count=0;
            if(i==n-1) break;
            for(int j=i+1;j<n;j++){
                if(a[i]<=a[j]) count=j-i;
            }
            if(count>max) max=count;
        }   
        return max;
    }
};*/
class Solution{
    public:
    int maxIndexDiff(int a[], int n) 
    { 
        int i = 0;
        int j = n-1;
        int maximum = INT_MIN;
        while(i < n){
            if(a[i] > a[j]){
                j--;
            }
            else{
                maximum = max(maximum , (j-i));
                j = n-1;
                i++;
            }
        }
        return maximum;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends